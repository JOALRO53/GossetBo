#!/usr/bin/python3.7

import tkinter
from tkinter import *
from tkinter import messagebox
import subprocess
from GbSecretTopic import *
from tkcalendar import *
import datetime

#from tkhtmlview import HTMLLabel
#from tkinterhtml import HtmlFrame


class GbGUI:
    def __init__(self):
        # Definicions de tipus de lletra i colors
        fons = "SeaGreen"
        fonscapses = "LightGreen"
        fontRetols = ("Arial", 17, "underline")
        fontText = ("Arial", 17)
        fontAnotacions = ("Arial", 13)

        # Ventana gràfica per encabir la resta de ginys
        self.root = tkinter.Tk()
        alto, ancho = self.root.winfo_screenheight(), self.root.winfo_screenwidth()
        self.root.title("Control de GossetBo")
        self.root.geometry("%dx%d+0+0" % (ancho, alto))
        self.root.configure(bg=fons)

        # Etiqueta retol de l'estat del sistema de control
        retolControl = Label(self.root, text='Estat del sistema')
        retolControl.configure(font=fontRetols, bg=fons)
        retolControl.place(x=100, y=30)

        # Etiqueta per a mostrar l'estat del sistema de control
        self.lbEstat = Label(self.root, text='Sistema desactivat')
        self.lbEstat.pack()
        self.lbEstat.place(x=90, y=60, height="30", width="200")
        self.lbEstat.configure(font=fontText)

        # Etiqueta per a mostrar l'estat de conexió
        self.lbConexio = Label(self.root, text='')
        self.lbConexio.place(x=ancho - 120, y=30, height="30", width="100")

        # Etiqueta per al retol de canvi de codi de desactivació
        retolCanviCodi = Label(self.root, text='Canvi del codi de desactivació')
        retolCanviCodi.configure(font=fontRetols, bg=fons)
        retolCanviCodi.place(x=50, y=260)

        # Capsa de text per introduir el codi actual
        self.tbCodiActual = Entry(self.root);
        self.tbCodiActual.configure(font=fontText, bg=fonscapses)
        self.tbCodiActual.place(x=75, y=300, width=250)

        # Etiqueta per la anotacio del codi actual
        anotacioCodiActual = Label(self.root, text='Codi actual')
        anotacioCodiActual.configure(font=fontAnotacions, bg=fons)
        anotacioCodiActual.place(x=335, y=300)

        # Capsa de text per introduir el nou codi
        self.tbNouCodi = Entry(self.root)
        self.tbNouCodi.configure(font=fontText, bg=fonscapses)
        self.tbNouCodi.place(x=75, y=350, width=250)

        # Etiqueta per la anotacio del nou codi
        anotacioNouCodi = Label(self.root, text='Nou codi')
        anotacioNouCodi.configure(font=fontAnotacions, bg=fons)
        anotacioNouCodi.place(x=335, y=350)

        # Botó per aceptar el nou codi
        btCanviCodi = Button(self.root, text="Acceptar", bg="GreenYellow", command=self.onBtCanviCodi_Clicked)
        btCanviCodi.place(x=165, y=400)
        
        lbRetolGrafana = Label(self.root, text="Gràfics", bg="seagreen", fg="Black",
                                   justify="left", anchor=W, font=fontRetols)
        lbRetolGrafana.place(x = 120, y = 520)
        
        # Etiqueta per retol del calendari de la data d'inici del gràfic
        lbDataInici = Label(self.root, text="Inici de periode", bg="seagreen", fg="Black",
                                   justify="left", anchor=W, font=fontAnotacions)
        lbDataInici.place(x = 250,y = 570)
        # EntryCalendar per a la data d'inici
        self.calendariinici = DateEntry(self.root, font = ("Dejavu", 13))
        self.calendariinici.place(x=90, y=570)
        
        # # Etiqueta per retol del calendari de la data de fi del gràfic
        lbDataFi = Label(self.root, text="Fi de periode", bg="seagreen", fg="Black",
                                   justify="left", anchor=W, font=fontAnotacions)
        lbDataFi.place(x=250, y=630)
        # Mostrar el EntryCalendar per a la data de fi del periode
        self.calendarifi = DateEntry(self.root, font = ("Dejavu", 13))
        self.calendarifi.place(x=90, y=630)
        
        # Botó per obrir el gràfic de consum d'aigua a Grafana
        btAigua = Button(self.root, text="Aigua", bg="LightBlue", command=self.onBtGrafanaA_Clicked)
        btAigua.place(x=90, y=690)
        
        # Botó per obrir el gràfic de consum de llum a Grafana
        btLlum = Button(self.root, text="Llum", bg="RoyalBlue", command=self.onBtGrafanaL_Clicked)
        btLlum.place(x=180, y=690)
        

    def onBtCanviCodi_Clicked(self):
        
        if self.tbCodiActual.get() != GbSecretTopic.codi:
            messagebox.showerror("Error", "Codi actual erroni")
        elif len(self.tbNouCodi.get()) == 0:
            messagebox.showerror("Error", "El nou codi no pot estar buit")
        else:
            codi = self.tbNouCodi.get()          
            canviat = GbSecretTopic.canviarCodi(codi)
            if canviat:
                messagebox.showinfo("OK", "Codi de desactivació canviat")
                self.tbCodiActual.delete(0, len(self.tbCodiActual.get()))
                self.tbNouCodi.delete(0, len(self.tbNouCodi.get()))
            else:
                messagebox.showerror("Error", "No s'ha canviat el codi de desactivació."+ GbSecretTopic.codi)
        

    def onBtGrafanaA_Clicked(self):
        # Datas de inici i final als calendaris
        inici = self.calendariinici.get_date()
        fi = self.calendarifi.get_date()
        # Obtindre els strings de les datas amb barra en lloc de guions
        inicib = str(inici).replace("-","/")
        fib = str(fi).replace("-","/")
        # Obtindre el unix time de les datas
        unixinici = datetime.datetime.strptime(inicib, '%Y/%m/%d').strftime("%s")
        unixfi = datetime.datetime.strptime(fib, '%Y/%m/%d').strftime("%s")
        uri = 'http://127.0.0.1:3000/d/qox2hekgz/consum-aigua?orgId=1&from='+unixinici+'999&to='+unixfi+'000'
        self.p = subprocess.Popen(['chromium-browser',uri])
        
        
    def onBtGrafanaL_Clicked(self):
        # Datas de inici i final als calendaris
        inici = self.calendariinici.get_date()
        fi = self.calendarifi.get_date()
        # Obtindre els strings de les datas amb barra en lloc de guions
        inicib = str(inici).replace("-","/")
        fib = str(fi).replace("-","/")
        # Obtindre el unix time de les datas
        unixinici = datetime.datetime.strptime(inicib, '%Y/%m/%d').strftime("%s")
        unixfi = datetime.datetime.strptime(fib, '%Y/%m/%d').strftime("%s")
        uri = 'http://localhost:3000/d/riqt0ciRk/consum-llum?from='+unixinici+'999&to='+unixfi+'000'
        self.p = subprocess.Popen(['chromium-browser',uri])
        
    
        #self.p = subprocess.Popen(['chromium-browser','http://127.0.0.1:3000/d/qox2hekgz/consum-aigua?orgId=1&from=1621221340905&to=1621264540905'])

    # Iniciar el programa

