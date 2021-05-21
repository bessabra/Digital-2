/*
 * dho_Temp.cpp
 *
 *  Created on: 31/08/2017
 *      Author: bessa
 */

#include <Classes/Contador/dho_Temp.h>
#include <Classes/GPIO/mkl_GPIO.h>
#include <Classes/GPIO/mkl_GPIOPort.h>

dho_Temp::dho_Temp(gpio_Pin slp, gpio_Pin rst, int cont, gpio_Pin ledCont, int vent, gpio_Pin vnt, bool flagA) {
	// TODO Auto-generated constructor stub

	_buttonSLP = mkl_GPIOPort(slp);
	_buttonSLP.setPortMode(gpio_input);
	_buttonSLP.setPullResistor(gpio_pullUpResistor);

	_buttonVNT = mkl_GPIOPort(vnt);
	_buttonVNT.setPortMode(gpio_input);
	_buttonVNT.setPullResistor(gpio_pullUpResistor);

	_buttonRST = mkl_GPIOPort(rst);
	_buttonRST.setPortMode(gpio_input);
	_buttonRST.setPullResistor(gpio_pullUpResistor);

	_ledcont = mkl_GPIOPort(ledCont);
	_ledcont.setPortMode(gpio_output);
	_ledcont.writeBit(0);

	CONT = cont;
	VENT = vent;
	flag_cont = flagA;
}

dho_Temp::~dho_Temp() {
	// TODO Auto-generated destructor stub
}

uint8_t dho_Temp::readRST() {
	return _buttonRST.readBit();
}

void dho_Temp::rst() {
	CONT = 0;
}

uint8_t dho_Temp::readVNT() {
	return _buttonVNT.readBit();
}


void dho_Temp::vnt() {
		if (VENT == 1000) {
			VENT = 500;
		}
		else
			VENT += 250;
}

uint8_t dho_Temp::readSLP() {
	return _buttonSLP.readBit();
}

uint8_t dho_Temp::ledCont(uint8_t bit) {
	_ledcont.writeBit(bit);
}

void dho_Temp::slp() {
	if (CONT < 90) {
		if (CONT % 10 == 0) {
			CONT = CONT + 10;
		} else {
			CONT = CONT + (10 - (CONT % 10));
		}
	} else
		CONT = 0;
}

bool dho_Temp::decrement() {
	if (CONT > 0) {
		CONT--;
		return 1;
	} else {
		return 0;
	}
}

int dho_Temp::getTemp() {
	return CONT;
}

int dho_Temp::getVent() {
	return VENT;
}



