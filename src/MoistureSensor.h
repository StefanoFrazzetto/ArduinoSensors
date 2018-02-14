class MoistureSensor {
    const uint8_t PIN_NUMBER; // The analog pin number

    static const short WET_SENSOR_VALUE = 0; // The value when the sensor is immersed into water
    static const short DRY_SENSOR_VALUE = 1023; // The value when the sensor is dry

    int rawValue;
    int voltage;
    int moisture;

private:
    int getSensorValue() {
        return analogRead(PIN_NUMBER);
    }

public :
    MoistureSensor(uint8_t PIN_NUMBER) : PIN_NUMBER(PIN_NUMBER) {}

    /**
       Return the relative humidity.
    */
    int getMoisture() {
        moisture = map(getSensorValue(), DRY_SENSOR_VALUE, WET_SENSOR_VALUE, 0, 100);
        return moisture;
    }

    /**
       Return the analog reading value.
       Min: 0 - Max: 1023
    */
    int getRawValue() {
        rawValue = getSensorValue();
        return rawValue;
    }

    /**
       Return the voltage read from the pin.
       Min: 0.00 V - Max: 5.00 V
    */
    float getVoltage() {
        voltage = getSensorValue() * (5.0 / 1023.0);
        return voltage;
    }
};

