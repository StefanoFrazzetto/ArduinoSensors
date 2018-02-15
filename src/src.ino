#include "MoistureSensor.h"
#include "DHTSensor.h"

MoistureSensor *m1;
DHTSensor *dht;

void setup() {
    Serial.begin(9600);
    m1 = new MoistureSensor(3);
    dht = new DHTSensor(2, DHT22);
}

void loop() {
    Serial.print("Moisture: ");
    Serial.print(m1->getMoisture());
    Serial.println(" %");

    Serial.print("Room temperature: ");
    Serial.println(dht->getTemperature());

    Serial.print("Humidity: ");
    Serial.print(dht->getHumidity());
    Serial.println(" %");

    Serial.println("\n");

    delay(5000);

}
