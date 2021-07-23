#include "esphome.h"
#include "SparkFun_Qwiic_PIR.h"

class CustomSFPIR : public PollingComponent, public Sensor {
	
public:
    QwiicPIR pir;
	
    CustomSFPIR() : PollingComponent(500) {} // refresh update() every 0.5sec

    float get_setup_priority() const override {
        return esphome::setup_priority::BUS; // initialize as I2C / bus device
    }

    void setup() override {
        Wire.begin(); // initialize I2C connection
        pir.begin(); // initialize sensor

        for (uint8_t seconds = 0; seconds < 30; seconds++) // sensor warm up for 30sec
        {
            delay(1000);
        }
        pir.setDebounceTime(500); // time till new object detection can be output
		
    }
	
    void update() override {
        if (pir.available()) { 
            if (pir.objectDetected()) {
                publish_state(1); // when object is detected, pass the number 1 on to ESPHome & Home Assistant
            }
            if (pir.objectRemoved()) {
                publish_state(0); // when object is removed, pass the number 0 on to ESPHome & Home Assistant
            }
            pir.clearEventBits(); // clear everything for new measurement
        }
    }
};
