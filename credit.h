#pragma once

#include <stdio.h>
#include <stdlib.h>

int digitCount(long int);
int checkLengthValidity(long int);
int * getEverySecond(long int);
int getRestSum(long int);
int productsDigits(int*);
int validate(int, int);

int checkAmex(long int);
int checkMastercard(long int);
int checkVisa(long int);

void run(long int);

void test(long int);


int checkLengthValidity(long int a)
{
    if (digitCount(a) == 13 || digitCount(a) == 15 || digitCount(a) == 16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int digitCount(long int a)
{
    int count = 0;
    while (a != 0)
    {
        a /= 10;
        ++count;
    }
    return count;
}

int * getEverySecond(long int a)
{
    char snum[17];
    int mult = digitCount(a) / 2;
    int* res = (int*)malloc(sizeof(int)*mult);

    sprintf(snum, "%li", a);

    int ind = 0;
    for (int i = 0; i < sizeof(snum)/sizeof(snum[0]); ++i)
    {
        if (i % 2 == 0)
        {
            res[ind] = 2 * (snum[i] - '0');
            ++ind;
        }
    }

    //free(res);
    return res;
}

int productsDigits(int* a)
{
    int count = 0;
    for (int i = 0; i < sizeof(a); ++i)
    {
        if (*(a + i) > 9)
        {
            int temp = *(a + i) % 10;
            count += temp;
            count += (*(a + i) - temp) / 10;
        }
        else
        {
            count += *(a + i);
        }
    }
    return count;
}

int getRestSum(long int a)
{
    char snum[17];
    int mult = digitCount(a) / 2;
    int* res = (int*)malloc(sizeof(int)*mult);

    sprintf(snum, "%li", a);

    int ind = 0;
    for (int i = 1; i < sizeof(snum)/sizeof(snum[0]); ++i)
    {
        if (i % 2 == 1)
        {
            res[ind] = snum[i] - '0';
            ++ind;
        }
    }
    int count = 0;
    for (int i = 0; i < mult; ++i)
    {
        count += *(res + i);
    }

    return count;
}

int validate(int a, int b)
{
    if ((a + b) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkAmex(long int a)
{
    char snum[17];
    sprintf(snum, "%li", a);

    if (digitCount(a) == 15)
    {
        if (snum[0] == '3')
        {
            if(snum[1] == '4' || snum[1] == '7')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int checkMastercard(long int a)
{
    char snum[17];
    sprintf(snum, "%li", a);

    if (digitCount(a) == 16)
    {
        if (snum[0] == '5')
        {
            if (snum[1] == '1' || snum[1] == '2' || snum[1] == '3' \
                || snum[1] == '4' || snum[1] == '5')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int checkVisa(long int a)
{
    char snum[17];
    sprintf(snum, "%li", a);

    if (digitCount(a) == 13 || digitCount(a) == 16)
    {
        if (snum[0] == '4')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void run(long int a)
{
    int* seconds    = getEverySecond(a);
    int prodDigs    = productsDigits(seconds);
    int rest        = getRestSum(a);

    int validNums   = validate(prodDigs, rest);
    int validLength = checkLengthValidity(a);

    if (validNums + validLength == 2){
        if (checkAmex(a))
        {
            printf("VALID\nAMERICAN EXPRESS\n");
        }
        else if (checkMastercard(a))
        {
            printf("VALID\nMASTERCARD\n");
        }
        else if (checkVisa(a))
        {
            printf("VALID\nVISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

/// tests
void test(long int a)
{
    printf("%d\n", digitCount(a));
    if (checkLengthValidity(a))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    int* temp = getEverySecond(a);
    for (int i = 0; i < digitCount(a)/2; ++i)
    {
        printf("%d", *(temp + i));
    }
    printf("\n");

    int b = productsDigits(temp);
    printf("%d\n", b);

    int count = getRestSum(a);
    printf("%d\n", count);
}


