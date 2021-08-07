#pragma once

#include <stdio.h>
#include <stdlib.h>

int digitCount(long int);
int checkLengthValidity(long int);
int * getEverySecond(long int);
int getRestSum(long int);
int productsDigits(int*,size_t);
int validate(int, int);

int checkAmex(long int);
int checkMastercard(long int);
int checkVisa(long int);

void run();

void test(long int);
