################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Application/logger/logger.c 

OBJS += \
./Core/Application/logger/logger.o 

C_DEPS += \
./Core/Application/logger/logger.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Application/logger/%.o Core/Application/logger/%.su Core/Application/logger/%.cyclo: ../Core/Application/logger/%.c Core/Application/logger/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Core/Application -I../Core/Drivers/led -I../Core/OS -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Application-2f-logger

clean-Core-2f-Application-2f-logger:
	-$(RM) ./Core/Application/logger/logger.cyclo ./Core/Application/logger/logger.d ./Core/Application/logger/logger.o ./Core/Application/logger/logger.su

.PHONY: clean-Core-2f-Application-2f-logger

