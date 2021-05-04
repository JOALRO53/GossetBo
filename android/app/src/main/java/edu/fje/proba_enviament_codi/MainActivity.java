package edu.fje.proba_enviament_codi;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.eclipse.paho.android.service.MqttAndroidClient;
import org.eclipse.paho.client.mqttv3.IMqttActionListener;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.IMqttToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import java.util.UUID;

public class MainActivity extends AppCompatActivity implements MqttCallback, IMqttActionListener
{
    private static final String SERVER_URI = "tcp://10.244.59.173:1883";
    private static final String TOPIC = "CodiEnviat";
    private static final int QOS = 1;
    private static final String TAG = "MainActivity";
    private MqttAndroidClient mqttAndroidClient;
    private Button btEnviament;
    private TextView tbCodi;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btEnviament = findViewById(R.id.btEnviament);
        btEnviament.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String missatge = tbCodi.getText().toString();
                publishMessage(missatge);
        }
    });
        tbCodi = findViewById(R.id.tbCodi);

        String clientId = UUID.randomUUID().toString();
        Log.d(TAG, "onCreate: clientId: " + clientId);

        mqttAndroidClient = new MqttAndroidClient(getApplicationContext(), SERVER_URI, clientId);
        mqttAndroidClient.setCallback(this);

        MqttConnectOptions mqttConnectOptions = new MqttConnectOptions();
        mqttConnectOptions.setCleanSession(false);

        try {
            Log.d(TAG, "onCreate: Connecting to " + SERVER_URI);
            mqttAndroidClient.connect(mqttConnectOptions, null, this);
        } catch (MqttException ex){
            Log.e(TAG, "onCreate: ", ex);
        }
    }

    @Override
    public void onSuccess(IMqttToken asyncActionToken) {
        Log.d(TAG, "onSuccess: ");
        try {
            mqttAndroidClient.subscribe(TOPIC, QOS);
        } catch (Exception e) {
            Log.e(TAG, "Error subscribing to topic", e);
        }
    }

    @Override
    public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
        Log.e(TAG, "Failed to connect to: " + SERVER_URI, exception);
    }

    @Override
    public void connectionLost(Throwable cause) {
        Log.d(TAG, "connectionLost: ", cause);
    }

    @Override
    public void messageArrived(String topic, MqttMessage message) {
        Log.d(TAG, "Incoming message: " + new String(message.getPayload()));
    }

    @Override
    public void deliveryComplete(IMqttDeliveryToken token) {
        Log.d(TAG, "deliveryComplete: ");
    }


    public void publishMessage(String payload) {
        try {
            if (mqttAndroidClient.isConnected() == false) {
                mqttAndroidClient.connect();
            }

            MqttMessage message = new MqttMessage();
            message.setPayload(payload.getBytes());
            message.setQos(0);
            mqttAndroidClient.publish(TOPIC, message,null, new IMqttActionListener() {
                @Override
                public void onSuccess(IMqttToken asyncActionToken) {
                    Log.i(TAG, "publish succeed!") ;
                }

                @Override
                public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
                    Log.i(TAG, "publish failed!") ;
                }
            });
        } catch (MqttException e) {
            Log.e(TAG, e.toString());
            e.printStackTrace();
        }
    }


}