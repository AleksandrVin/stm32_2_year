################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
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
74hc595n_segment_led.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
74hc595n_segment_led.list \

OBJCOPY_BIN += \
74hc595n_segment_led.bin \


# All Target
all: 74hc595n_segment_led.elf secondary-outputs

# Tool invocations
74hc595n_segment_led.elf: $(OBJS) $(USER_OBJS) C:\Users\vsash\OneDrive\Data\Information\Programming\stm32\stm32cubeIDE\74hc595n_segment_led\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "74hc595n_segment_led.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\vsash\OneDrive\Data\Information\Programming\stm32\stm32cubeIDE\74hc595n_segment_led\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="74hc595n_segment_led.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

74hc595n_segment_led.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "74hc595n_segment_led.list"
	@echo 'Finished building: $@'
	@echo ' '

74hc595n_segment_led.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "74hc595n_segment_led.bin"
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
