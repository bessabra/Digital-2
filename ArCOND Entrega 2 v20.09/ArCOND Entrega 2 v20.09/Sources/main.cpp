#include <MKL25Z4.h>
#include <Classes/Display/dsf_SerialDisplays.h>
#include <Classes/GPIO/mkl_GPIOPort.h>
#include <Classes/Multiplexador/Multiplexer.h>
#include <Classes/TPM/TPM_Delay/mkl_TPMDelay.h>
#include <Classes/Onoff/Onoff.h>
#include <Classes/PIT/PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.h>
#include <Classes/PIT/mkl_PIT.h>
#include <Classes/Contador/dho_Temp.h>
#include <Classes/TPM/TPM_PWM/mkl_TPMPulseWidthModulation.h>

/*Framework Display e PIT*/
mkl_PITInterruptInterrupt pit(PIT_Ch0);
dsf_SerialDisplays display(gpio_PTA12, gpio_PTA2, gpio_PTA4);

/*Temporizador8 */
dho_Temp cont(gpio_PTC7, gpio_PTC0, 0, gpio_PTD1, 500, gpio_PTA5, true);

/*Botão Onoff */
Onoff onoffButton(gpio_PTD4, gpio_PTB19);

/**Framework PWM*/
mkl_TPMPulseWidthModulation pwm(tpm_PTD5);

Multiplexer multiplex;
mkl_TPMDelay delay(tpm_TPM1);

uint32_t debounceTime = 24576;

bool flagonOff = false;
bool flagTest = false;
bool flag_zero = true;
uint8_t temperatura = 28;
uint8_t contador = 0;

int setupPIT() {
	pit.enablePeripheralModule();
	pit.setPeriod(0x4e20);
}

extern "C" {
void PIT_IRQHandler(void) {
	//display.updateDisplays();
	pit.clearInterruptFlag();
}
}

int main(void) {

	cont.ledCont(1);
	int Div = 1000;
	display.clearDisplays();
	setupPIT();
	pit.resetCounter();
	pit.enableTimer();
	pit.enableInterruptRequests();

	delay.setFrequency(tpm_div128);
	delay.startDelay(10);

	flag_zero = true;

	while (true) {
		display.updateDisplays();

		//uint8_t resultMultiplex = multiplex.select(1, temperatura, contador);

	/*Botão onoff*/
	if (!onoffButton.read() && delay.timeoutDelay()) {
		while (!onoffButton.read());
		delay.startDelay(debounceTime);
		flagonOff = !flagonOff;
		onoffButton.ledStandby(flagonOff);
		cont.ledCont(1);
		cont.VENT = 1000;
	}


	if (flagonOff) {

		pwm.setFrequency(tpm_div16, 999);
		pwm.setDutyCycle(cont.getVent());
		pwm.enableOperation();

		if (!cont.readVNT()) {
			while(!cont.readVNT());
			cont.vnt();
		}

		if (cont.getTemp() != 0) {
			cont.ledCont(0);
		}else{
			cont.ledCont(1);
		}

		if (cont.getTemp() == 0)
			flag_zero = false;
		else
			flag_zero = true;

		if (!cont.readRST()) {
			while (!cont.readRST());
			cont.rst();
		}
		if (!cont.readSLP()) {
			while (!cont.readSLP());
			cont.slp();
		}
		display.writeWord(cont.getTemp());
		Div--;

		if (Div <= 0) {
			cont.decrement();
			Div = 1000;

		if (cont.getTemp() == 0 && flag_zero)
			flagonOff = false;
			flag_zero = false;
			onoffButton.ledStandby(flagonOff);
			cont.ledCont(1);
		}

	} else {
		if(!flag_zero)
		{
			cont.VENT = 0;
			pwm.setDutyCycle(cont.getVent());
			pwm.enableOperation();
		}
		display.clearDisplays();
		cont.CONT = 0;
	}

	display.hideZerosLeft();
}

return 0;
}

