################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Account.cpp \
../AccountsOwner.cpp \
../Bank.cpp \
../Client.cpp \
../Currency.cpp \
../MoneyAmount.cpp \
../Person.cpp \
../Transaction.cpp \
../main.cpp 

OBJS += \
./Account.o \
./AccountsOwner.o \
./Bank.o \
./Client.o \
./Currency.o \
./MoneyAmount.o \
./Person.o \
./Transaction.o \
./main.o 

CPP_DEPS += \
./Account.d \
./AccountsOwner.d \
./Bank.d \
./Client.d \
./Currency.d \
./MoneyAmount.d \
./Person.d \
./Transaction.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


