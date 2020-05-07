################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
f103_nrf_transmit.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
f103_nrf_transmit.list \

OBJCOPY_BIN += \
f103_nrf_transmit.bin \


# All Target
all: f103_nrf_transmit.elf secondary-outputs

# Tool invocations
f103_nrf_transmit.elf: $(OBJS) $(USER_OBJS) C:\Users\vsash\OneDrive\Data\Information\Programming\stm32\stm32cubeIDE\f103_nrf_transmit\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "f103_nrf_transmit.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\vsash\OneDrive\Data\Information\Programming\stm32\stm32cubeIDE\f103_nrf_transmit\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="f103_nrf_transmit.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

f103_nrf_transmit.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "f103_nrf_transmit.list"
	@echo 'Finished building: $@'
	@echo ' '

f103_nrf_transmit.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "f103_nrf_transmit.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
