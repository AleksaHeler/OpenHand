################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Application/fsm/fsm.c 

OBJS += \
./Core/Application/fsm/fsm.o 

C_DEPS += \
./Core/Application/fsm/fsm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Application/fsm/%.o Core/Application/fsm/%.su Core/Application/fsm/%.cyclo: ../Core/Application/fsm/%.c Core/Application/fsm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Core/Application/fsm -I../Core/Application/log -I../Core/Drivers/led -I../Core/Drivers/btn -I../Core/Drivers/emg -I../Core/Drivers/i2c -I../Core/Drivers/internal -I../Core/Drivers/motor -I../Core/Drivers/pot -I../Core/OS -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wno-missing-braces -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Application-2f-fsm

clean-Core-2f-Application-2f-fsm:
	-$(RM) ./Core/Application/fsm/fsm.cyclo ./Core/Application/fsm/fsm.d ./Core/Application/fsm/fsm.o ./Core/Application/fsm/fsm.su

.PHONY: clean-Core-2f-Application-2f-fsm

