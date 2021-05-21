#ifndef SOURCES_CLASSES_ONOFF_ONOFF_H_
#define SOURCES_CLASSES_ONOFF_ONOFF_H_

#include <Classes/GPIO/mkl_GPIOPort.h>

class Onoff{

  public:
    Onoff(gpio_Pin pin, gpio_Pin led);
    void onOff();

    uint8_t read();
    uint8_t ledStandby(uint8_t bit);

  private:
    mkl_GPIOPort _button;
    mkl_GPIOPort _led;

};

#endif /* SOURCES_CLASSES_ONOFF_ONOFF_H_ */
