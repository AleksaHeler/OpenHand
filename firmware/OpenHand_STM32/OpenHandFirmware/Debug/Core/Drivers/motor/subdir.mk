################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Drivers/motor/motor.c 

OBJS += \
./Core/Drivers/motor/motor.o 

C_DEPS += \
./Core/Drivers/motor/motor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Drivers/motor/%.o Core/Drivers/motor/%.su Core/Drivers/motor/%.cyclo: ../Core/Drivers/motor/%.c Core/Drivers/motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Core/Application/fsm -I../Core/Application/log -I../Core/Drivers/led -I../Core/Drivers/btn -I../Core/Drivers/emg -I../Core/Drivers/i2c -I../Core/Drivers/internal -I../Core/Drivers/motor -I../Core/Drivers/pot -I../Core/OS -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wno-missing-braces -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Drivers-2f-motor

clean-Core-2f-Drivers-2f-motor:
	-$(RM) ./Core/Drivers/motor/motor.cyclo ./Core/Drivers/motor/motor.d ./Core/Drivers/motor/motor.o ./Core/Drivers/motor/motor.su

.PHONY: clean-Core-2f-Drivers-2f-motor

