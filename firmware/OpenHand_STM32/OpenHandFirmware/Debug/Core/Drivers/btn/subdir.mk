################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Drivers/btn/btn.c 

OBJS += \
./Core/Drivers/btn/btn.o 

C_DEPS += \
./Core/Drivers/btn/btn.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Drivers/btn/%.o Core/Drivers/btn/%.su Core/Drivers/btn/%.cyclo: ../Core/Drivers/btn/%.c Core/Drivers/btn/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Core/Application/fsm -I../Core/Application/log -I../Core/Drivers/led -I../Core/Drivers/btn -I../Core/Drivers/emg -I../Core/Drivers/i2c -I../Core/Drivers/internal -I../Core/Drivers/motor -I../Core/Drivers/pot -I../Core/OS -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wno-missing-braces -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Drivers-2f-btn

clean-Core-2f-Drivers-2f-btn:
	-$(RM) ./Core/Drivers/btn/btn.cyclo ./Core/Drivers/btn/btn.d ./Core/Drivers/btn/btn.o ./Core/Drivers/btn/btn.su

.PHONY: clean-Core-2f-Drivers-2f-btn

