/*
 * dho_Temp.h
 *
 *  Created on: 31/08/2017
 *      Author: bessa
 */

#include <Classes/GPIO/mkl_GPIOPort.h>
#include <Classes/GPIO/mkl_GPIO.h>
#ifndef SOURCES_LIB_DHO_TEMP_H_
#define SOURCES_LIB_DHO_TEMP_H_

class dho_Temp {
public:

	dho_Temp(gpio_Pin slp, gpio_Pin rst, int cont, gpio_Pin ledCont, int vent, gpio_Pin vnt, bool flagA);
	virtual ~dho_Temp();

	void slp();
	uint8_t readSLP();

	void rst();
	uint8_t readRST();

	void vnt();
	uint8_t readVNT();

	uint8_t ledCont(uint8_t bit);

	bool decrement();
	int getTemp();
	int getVent();

	int CONT;
	int VENT;
	bool flag_cont;

private:
	mkl_GPIOPort _buttonSLP;
	mkl_GPIOPort _buttonRST;
	mkl_GPIOPort _ledcont;
	mkl_GPIOPort _buttonVNT;

};

#endif /* SOURCES_LIB_DHO_TEMP_H_ */
