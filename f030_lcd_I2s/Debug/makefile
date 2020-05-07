################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
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
f030_lcd_I2s.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
f030_lcd_I2s.list \

OBJCOPY_BIN += \
f030_lcd_I2s.bin \


# All Target
all: f030_lcd_I2s.elf secondary-outputs

# Tool invocations
f030_lcd_I2s.elf: $(OBJS) $(USER_OBJS) C:\Users\vsash\OneDrive\Data\Information\Programming\stm32\stm32cubeIDE\f030_lcd_I2s\STM32F030F4PX_FLASH.ld
	arm-none-eabi-gcc -o "f030_lcd_I2s.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\vsash\OneDrive\Data\Information\Programming\stm32\stm32cubeIDE\f030_lcd_I2s\STM32F030F4PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="f030_lcd_I2s.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

f030_lcd_I2s.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "f030_lcd_I2s.list"
	@echo 'Finished building: $@'
	@echo ' '

f030_lcd_I2s.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "f030_lcd_I2s.bin"
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
