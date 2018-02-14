# Arduino Sensors

This is a collection of wrapper classes to use Arduino sensors with ease.

## DHTSensor

The following methods are available for the DHTSensor class:

- DHTSensor(uint8_t PIN_NUMBER, uint8_t DHT_TYPE)
- getTemperature()
- getHumidity()

## MoistureSensor

The following methods are available for the MoistureSensor class:

- MoistureSensor(uint8_t PIN_NUMBER)
- getMoisture()
- getVoltage()
- getRawValue()

## Usage

Clone this repository using

```git clone https://github.com/StefanoFrazzetto/ArduinoSensors```

then start coding using the ```example.ino``` file.


## Contributing

If you want to contribute to this project, just clone the repository using

```git clone --recurse-submodules https://github.com/StefanoFrazzetto/ArduinoSensors```

This will clone the repository and the necessary libraries (Adafruit sensor & DHT sensor library).

If you are using an IDE, you will probably want to install [PlatformIO](https://platformio.org/)
to avoid errors caused by missing dependencies. You just need to download the **core** to make
things work. After installing it, go to the project directory and run

```platformio init --ide %IDE% --board %TYPE%```


When you feel satisfied with your work, open a pull request with your changes.