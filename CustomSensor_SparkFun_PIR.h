#include "esphome.h"
#include "SparkFun_Qwiic_PIR.h"

class CustomSFPIR : public PollingComponent, public Sensor {
	
public:
    QwiicPIR pir;
	
    CustomSFPIR() : PollingComponent(500) {} 

    float get_setup_priority() const override {
        return esphome::setup_priority::BUS;
    }

    void setup() override {
        Wire.begin(); 
        pir.begin();

        for (uint8_t seconds = 0; seconds < 30; seconds++) 
        {
            delay(1000);
        }
        pir.setDebounceTime(500);
		
    }
	
    void update() override {
        if (pir.available()) { 
            if (pir.objectDetected()) {
                publish_state(1);
            }
            if (pir.objectRemoved()) {
                publish_state(0);
            }
            pir.clearEventBits();
        }
    }
};
