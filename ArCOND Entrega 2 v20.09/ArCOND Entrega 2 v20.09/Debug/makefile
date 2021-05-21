################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/Classes/TPM/TPM_PWM/subdir.mk
-include Sources/Classes/TPM/TPM_Measure/subdir.mk
-include Sources/Classes/TPM/TPM_Delay/subdir.mk
-include Sources/Classes/TPM/subdir.mk
-include Sources/Classes/PIT/PIT_Delay/subdir.mk
-include Sources/Classes/PIT/PITPeriodicInterrupt/subdir.mk
-include Sources/Classes/PIT/subdir.mk
-include Sources/Classes/Onoff/subdir.mk
-include Sources/Classes/Multiplexador/subdir.mk
-include Sources/Classes/GPIO/subdir.mk
-include Sources/Classes/Display/subdir.mk
-include Sources/Classes/Contador/subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
ArCOND\ Entrega\ 2\ v20.09.siz \


# All Target
all: ArCOND\ Entrega\ 2\ v20.09.elf secondary-outputs

# Tool invocations
ArCOND\ Entrega\ 2\ v20.09.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -T "MKL25Z128xxx4_flash.ld" -Xlinker --gc-sections -L"C:/workspace_kds/ArCOND Entrega 2 v20.09/Project_Settings/Linker_Files" -Wl,-Map,"ArCOND Entrega 2 v20.09.map" -specs=nosys.specs -specs=nano.specs -Xlinker -z -Xlinker muldefs -o "ArCOND Entrega 2 v20.09.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ArCOND\ Entrega\ 2\ v20.09.siz: ArCOND\ Entrega\ 2\ v20.09.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "ArCOND Entrega 2 v20.09.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(C++_DEPS)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS)$(S_UPPER_DEPS) "ArCOND Entrega 2 v20.09.elf"
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
