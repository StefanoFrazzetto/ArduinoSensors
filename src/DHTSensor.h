/**
 *  DHT Temperature & Humidity Sensor
 *
 *  Depends on the following Arduino libraries:
 *  - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
 *  - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 *
 *  See guide for details on sensor wiring and usage:
 *  https://learn.adafruit.com/dht/overview
 *
 *  @author Stefano Frazzetto <github.com/StefanoFrazzetto>
*/

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class DHTSensor {

    DHT_Unified *dht;
    sensor_t sensor{};
    sensors_event_t event{};

    float temperature;
    float humidity;

public:
    DHTSensor(uint8_t PIN_NUMBER, uint8_t DHT_TYPE)
            : dht(new DHT_Unified(PIN_NUMBER, DHT_TYPE)), temperature(0), humidity(0) {}

    ~DHTSensor() {
        delete dht;
    }


public:

    /**
     * Return the temperature.
     */
    float getTemperature() {
        dht->temperature().getEvent(&event);
        return event.temperature;
    }

    /**
     * Return the relative humidity.
     */
    float getHumidity() {
        dht->humidity().getEvent(&event);
        return event.relative_humidity;
    }


    float getDewPointFast();

    /**
     *  Return the humidity sensor information.
     *
     *  Fields available:
     *  - name
     *  - version
     *  - sensor_id
     *  - max_value
     *  - min_value
     *  - resolution
    */
    sensor_t getHumiditySensorInformation() {
        sensor_t sensor;
        dht->humidity().getSensor(&sensor);
        return sensor;
    }

    /**
     *  Return the temperature sensor information.
     *
     *  Fields available:
     *  - name
     *  - version
     *  - sensor_id
     *  - max_value
     *  - min_value
     *  - resolution
    */
    sensor_t getTemperatureSensorInformation() {
        sensor_t sensor;
        dht->temperature().getSensor(&sensor);
        return sensor;
    }
};