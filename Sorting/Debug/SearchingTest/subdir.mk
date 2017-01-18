################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SearchingTest/ArraySTTest.cpp \
../SearchingTest/BinarySearchInterpolationSTTest.cpp \
../SearchingTest/BinarySearchSTTest.cpp \
../SearchingTest/BinarySearchSingleItemST.cpp \
../SearchingTest/OrderedSequentialSearchSTTest.cpp \
../SearchingTest/SequantialSearchSTTest.cpp \
../SearchingTest/stdafx.cpp 

OBJS += \
./SearchingTest/ArraySTTest.o \
./SearchingTest/BinarySearchInterpolationSTTest.o \
./SearchingTest/BinarySearchSTTest.o \
./SearchingTest/BinarySearchSingleItemST.o \
./SearchingTest/OrderedSequentialSearchSTTest.o \
./SearchingTest/SequantialSearchSTTest.o \
./SearchingTest/stdafx.o 

CPP_DEPS += \
./SearchingTest/ArraySTTest.d \
./SearchingTest/BinarySearchInterpolationSTTest.d \
./SearchingTest/BinarySearchSTTest.d \
./SearchingTest/BinarySearchSingleItemST.d \
./SearchingTest/OrderedSequentialSearchSTTest.d \
./SearchingTest/SequantialSearchSTTest.d \
./SearchingTest/stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
SearchingTest/%.o: ../SearchingTest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


