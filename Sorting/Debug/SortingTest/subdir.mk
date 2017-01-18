################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SortingTest/BinaryHeapMaxPQTest.cpp \
../SortingTest/HeapSortTest.cpp \
../SortingTest/IndexMaxPQTest.cpp \
../SortingTest/InsertionSortTest.cpp \
../SortingTest/LinkedListTest.cpp \
../SortingTest/OrderedArrayMaxPQTest.cpp \
../SortingTest/OrderedLinkedListMaxPQTest.cpp \
../SortingTest/QuickSortTest.cpp \
../SortingTest/TopDownMergeSortTest.cpp \
../SortingTest/UnorderedArrayMaxPQTest.cpp \
../SortingTest/UnorderedLinkedListMaxPQTest.cpp \
../SortingTest/stdafx.cpp 

OBJS += \
./SortingTest/BinaryHeapMaxPQTest.o \
./SortingTest/HeapSortTest.o \
./SortingTest/IndexMaxPQTest.o \
./SortingTest/InsertionSortTest.o \
./SortingTest/LinkedListTest.o \
./SortingTest/OrderedArrayMaxPQTest.o \
./SortingTest/OrderedLinkedListMaxPQTest.o \
./SortingTest/QuickSortTest.o \
./SortingTest/TopDownMergeSortTest.o \
./SortingTest/UnorderedArrayMaxPQTest.o \
./SortingTest/UnorderedLinkedListMaxPQTest.o \
./SortingTest/stdafx.o 

CPP_DEPS += \
./SortingTest/BinaryHeapMaxPQTest.d \
./SortingTest/HeapSortTest.d \
./SortingTest/IndexMaxPQTest.d \
./SortingTest/InsertionSortTest.d \
./SortingTest/LinkedListTest.d \
./SortingTest/OrderedArrayMaxPQTest.d \
./SortingTest/OrderedLinkedListMaxPQTest.d \
./SortingTest/QuickSortTest.d \
./SortingTest/TopDownMergeSortTest.d \
./SortingTest/UnorderedArrayMaxPQTest.d \
./SortingTest/UnorderedLinkedListMaxPQTest.d \
./SortingTest/stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
SortingTest/%.o: ../SortingTest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


