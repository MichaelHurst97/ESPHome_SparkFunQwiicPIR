# ESPHome SparkFun Qwiic PIR Custom Sensor Support
ESPHome custom sensor support for the SparkFun Qwiic PIR passive infrared sensor.
https://learn.sparkfun.com/tutorials/qwiic-pir-hookup-guide

Source: https://github.com/sparkfun/SparkFun_Qwiic_PIR_Arduino_Library

Usage:
1. Place CustomSensor_SparkFun_PIR.h next to your ESPHome yaml
2. Add the lines from example.yaml to your yaml, so the custom sensor code gets included in the compilation process.
3. When movement is detected, Home Assistant displays the number 1. So be sure to use 0 and 1 in your automations.

For more information on how to add a custom sensor to ESPHome see:
https://esphome.io/components/sensor/custom.html
