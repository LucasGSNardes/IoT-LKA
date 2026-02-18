#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Protótipos das funções (Isso resolve o erro de 'not declared')
void setup_wifi();
void reconnect();

// Configurações Wi-Fi e MQTT
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com"; 

WiFiClient espClient;
PubSubClient client(espClient);

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando em ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect("ESP32_Cliente_Unico_Kaua")) { // Mudei o ID para ser mais único
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura dos sensores
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int lum = analogRead(35);
  int pot = analogRead(34);

  // Verifica se a leitura falhou
  if (isnan(h) || isnan(t)) {
    Serial.println("Falha ao ler o sensor DHT!");
    return;
  }

  // Criar JSON para o Node-RED
  String payload = "{\"temp\":" + String(t) + ",\"hum\":" + String(h) + ",\"lum\":" + String(lum) + ",\"pot\":" + String(pot) + "}";
  
  client.publish("meu_projeto/sensores", payload.c_str());
  Serial.println("Dados enviados: " + payload);
  
  delay(10000); // Envia a cada 10 segundos
}
