################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sorting/MaxPQ.cpp \
../Sorting/OrderedArrayMaxPQ.cpp \
../Sorting/PriorityQueue.cpp \
../Sorting/UnorderedArrayMaxPQ.cpp 

OBJS += \
./Sorting/MaxPQ.o \
./Sorting/OrderedArrayMaxPQ.o \
./Sorting/PriorityQueue.o \
./Sorting/UnorderedArrayMaxPQ.o 

CPP_DEPS += \
./Sorting/MaxPQ.d \
./Sorting/OrderedArrayMaxPQ.d \
./Sorting/PriorityQueue.d \
./Sorting/UnorderedArrayMaxPQ.d 


# Each subdirectory must supply rules for building sources it contributes
Sorting/%.o: ../Sorting/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


