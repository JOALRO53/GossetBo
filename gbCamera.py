
import io
import picamera
import logging
import socketserver
from threading import Condition
from http import server

PAGE="""\
<html>
<head>
<title>Camera de GossetBo</title>
</head>
<body>
<center><h1>Camera de GossetBo</h1></center>
<center><img src="stream.mjpg" width="640" height="480"></center>
</body>
</html>
"""

class StreamingOutput(object): # Classe derivada d'object per a encapsular un buffer de bytes i un objecte condition per gestionar fils
    def __init__(self):
        # Atributs de la classe
        self.frame = None
        self.buffer = io.BytesIO() # Buffer de bytes
        self.condition = Condition() # Condició per a gestionar fils.

    def write(self, buf):
        if buf.startswith(b'\xff\xd8'):
            # New frame, copy the existing buffer's content and notify all
            # clients it's available
            self.buffer.truncate()
            with self.condition:
                self.frame = self.buffer.getvalue()
                self.condition.notify_all()
            self.buffer.seek(0)
        return self.buffer.write(buf)

class StreamingHandler(server.BaseHTTPRequestHandler):# Clase derivada per a definir les tasques a realitzar quan es rep una nova petició de transmissió
    def do_GET(self):
        if self.path == '/':
            self.send_response(301)
            self.send_header('Location', '/index.html')
            self.end_headers()
        elif self.path == '/index.html':
            content = PAGE.encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'text/html')
            self.send_header('Content-Length', len(content))
            self.end_headers()
            self.wfile.write(content)
        elif self.path == '/stream.mjpg':
            self.send_response(200)
            self.send_header('Age', 0)
            self.send_header('Cache-Control', 'no-cache, private')
            self.send_header('Pragma', 'no-cache')
            self.send_header('Content-Type', 'multipart/x-mixed-replace; boundary=FRAME')
            self.end_headers()
            try:
                while True:
                    with output.condition:
                        output.condition.wait()
                        frame = output.frame
                    self.wfile.write(b'--FRAME\r\n')
                    self.send_header('Content-Type', 'image/jpeg')
                    self.send_header('Content-Length', len(frame))
                    self.end_headers()
                    self.wfile.write(frame)
                    self.wfile.write(b'\r\n')
            except Exception as e:
                logging.warning(
                    'Removed streaming client %s: %s',
                    self.client_address, str(e))
        else:
            self.send_error(404)
            self.end_headers()

""" Classe derivada de socketserver.ThreadingMixIn i de server.HTTPserver per encapsular els seus mètodes
    i atributs """
class StreamingServer(socketserver.ThreadingMixIn, server.HTTPServer):
    allow_reuse_address = True # Atribut de soketserver que permet reutilitzar adreces
    daemon_threads = True # Atribut de ThreadingMixIn per indicar si el servidor ha d'esperar per a la finalització dels seus fils d'execució

with picamera.PiCamera(resolution='640x480', framerate=24) as camera:  # Crea un objecte PiCamera
    output = StreamingOutput()  # Crea un objecte StreamingOutput
    # Rota l'imatge de la càmera
    camera.rotation = 180
    camera.start_recording(output,
                           format='mjpeg')  # Comença a gravar video i el desa al objecte StreamingOutput anterior
    try:
        address = ('', 8000)  # Localhost i port 8000
        server = StreamingServer(address,
                                 StreamingHandler)  # Crea un objecte StreamingServer amb la direcció pasada com a primer argument i el
        #  controlador del event de recepció de peticions com a segon
        server.serve_forever()  # Gestionar peticions de transmissió fins a rebre una petició explicita de finalització
    finally:
        camera.stop_recording()
