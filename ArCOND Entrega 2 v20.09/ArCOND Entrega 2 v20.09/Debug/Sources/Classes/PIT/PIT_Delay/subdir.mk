################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Classes/PIT/PIT_Delay/mkl_PITDelay.cpp 

OBJS += \
./Sources/Classes/PIT/PIT_Delay/mkl_PITDelay.o 

CPP_DEPS += \
./Sources/Classes/PIT/PIT_Delay/mkl_PITDelay.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Classes/PIT/PIT_Delay/%.o: ../Sources/Classes/PIT/PIT_Delay/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


