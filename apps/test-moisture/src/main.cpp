#include "MoistureSensor.h"
#include "hw_bridge.h"
#include "mbed.h"

DigitalOut led1(LED1);

int main() {
  led1 = 0;  // start with LED off

  float moisture = 0;  // initialize default variables
  float temperature = 0.0;

  MoistureSensor sensor = MoistureSensor(TEMP_MOIST_I2C_SDA, TEMP_MOIST_I2C_SCL);

  while (1) {
    sensor.reset();  // reset all registers on sensor to default values

    ThisThread::sleep_for(500ms);

    led1 = (sensor.getStatus());  // turn on LED if the sensor's HW_ID code matches the known value

    printf("\r\nChecking Device ID...\r\n");  // read device HW_ID, reading of 85 is expected

    ThisThread::sleep_for(100ms);

    printf("\r\nReading Moisture...\r\n");  // read moisture from sensor, reading of 65534 indicates unsuccessful
                                            // initialization
    moisture = sensor.read();
    printf("Moisture: %f \r\n", moisture);

    ThisThread::sleep_for(100ms);

    printf("\r\nReading Temperature...\r\n");  // read temperature from sensor, reading of -273.0 indicates
                                               // unsuccessful initialization
    temperature = sensor.alternateRead();
    printf("Temperature: %f \r\n", temperature);

    printf("\r\n-----------------------------\r\n");

    ThisThread::sleep_for(100ms);
  }
}
