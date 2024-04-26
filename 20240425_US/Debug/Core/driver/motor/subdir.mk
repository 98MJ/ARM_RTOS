################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/motor/motor.c 

OBJS += \
./Core/driver/motor/motor.o 

C_DEPS += \
./Core/driver/motor/motor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/motor/%.o Core/driver/motor/%.su Core/driver/motor/%.cyclo: ../Core/driver/motor/%.c Core/driver/motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver-2f-motor

clean-Core-2f-driver-2f-motor:
	-$(RM) ./Core/driver/motor/motor.cyclo ./Core/driver/motor/motor.d ./Core/driver/motor/motor.o ./Core/driver/motor/motor.su

.PHONY: clean-Core-2f-driver-2f-motor

