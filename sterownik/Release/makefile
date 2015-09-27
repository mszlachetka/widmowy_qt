################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
wyswietlacz_widmowy.lss \

FLASH_IMAGE += \
wyswietlacz_widmowy.hex \

EEPROM_IMAGE += \
wyswietlacz_widmowy.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: wyswietlacz_widmowy.elf secondary-outputs

# Tool invocations
wyswietlacz_widmowy.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,wyswietlacz_widmowy.map -mmcu=atmega8 -o "wyswietlacz_widmowy.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

wyswietlacz_widmowy.lss: wyswietlacz_widmowy.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S wyswietlacz_widmowy.elf  >"wyswietlacz_widmowy.lss"
	@echo 'Finished building: $@'
	@echo ' '

wyswietlacz_widmowy.hex: wyswietlacz_widmowy.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex wyswietlacz_widmowy.elf  "wyswietlacz_widmowy.hex"
	@echo 'Finished building: $@'
	@echo ' '

wyswietlacz_widmowy.eep: wyswietlacz_widmowy.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex wyswietlacz_widmowy.elf  "wyswietlacz_widmowy.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: wyswietlacz_widmowy.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 wyswietlacz_widmowy.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) wyswietlacz_widmowy.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
