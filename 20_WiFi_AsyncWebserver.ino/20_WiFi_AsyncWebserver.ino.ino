#include <WiFi.h> //Einbinden der WiFi-Bibliothek
#include <ESPAsyncWebServer.h> //Einbinden der Webserver-Bibliothek
//Ein Objekt namens server erstellen. Der Bauplan bzw. die Klasse des
//Objekts heisst AsyncWebServer. Wir benutzen spaeter die Methoden
//on(), onNotFound() und begin() des Objekts. 80 bedeutet, dass der
//Webserver auf Port 80 Anfragen erwartet. Dies ist der Standard HTTP-Port.
AsyncWebServer server(80);
//WLAN-Zugangsdaten
char* ssid = "Chrisns"; //hier muss die SSID stehen
char* passwort = "chrisfan123"; //hier muss das Passwort stehen

void setup() {
Serial.begin(115200); //serielle Schnittstelle initialisieren
Serial.print("Verbindungsaufbau zu ");
Serial.println(ssid);
WiFi.begin(ssid, passwort); //WiFi-Verbind. herstellen, auf Verbindung warten

while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.print("Verbindung hergestellt.\n Lokale IP: ");
Serial.println(WiFi.localIP());
Serial.print("ESP Board MAC Adresse: ");
Serial.println(WiFi.macAddress());

//Die Antworten des Servers definieren
server.on( "/", HTTP_GET , [] (AsyncWebServerRequest * request) {
  request->send( 200, "text/plain", "Hallo Welt!" );});
  server.onNotFound([] (AsyncWebServerRequest * request) {
  request->send(404, "text/plain", "Seite nicht vorhanden!");});
  server.begin(); //Den Server starten mit der Methode begin()
}

void loop() { }