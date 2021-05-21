################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Classes/PIT/PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.cpp 

OBJS += \
./Sources/Classes/PIT/PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.o 

CPP_DEPS += \
./Sources/Classes/PIT/PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Classes/PIT/PITPeriodicInterrupt/%.o: ../Sources/Classes/PIT/PITPeriodicInterrupt/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


