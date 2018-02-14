#include "DHTSensor.h"

float DHTSensor::getDewPointFast()  {
  float temperature = getTemperature();
  float humidity = getHumidity();

  float a = 17.368;
  float b = 238.88;
  float temp = (a * temperature) / (b + temperature) + log(humidity * 0.01);
  float Td = (b * temp) / (a - temp);

  return Td;
}
