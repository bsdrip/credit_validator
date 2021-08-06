#include "../headers/credit.h"

#include <stdio.h>
#include <stdlib.h>


// checks if the length of the card number matches either one of the relevant brands standard
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

// counts the number of digits of the card number
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

// puts every other number (0, 2, 4, 5... indices) into an array of integers
int * getEverySecond(long int a)
{
  char snum[17];
  int length = digitCount(a);
  int mult = digitCount(a) / 2;
  int* res = (int*)malloc(sizeof(int)*mult);

  sprintf(snum, "%li", a);

  int ind = 0;
  for (int i = 0; i < length; ++i)
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

// adds together the digits of every other number in the card number
int productsDigits(int* a, int length)
{
  int count = 0;
  for (int i = 0; i < length; ++i)
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

// adds together every second number of the card 
int getRestSum(long int a)
{
  char snum[17];
  int mult = digitCount(a) / 2;
  int* res = (int*)malloc(sizeof(int)*mult);

  sprintf(snum, "%li", a);

  int ind = 0;
  for (unsigned long int i = 1; i < sizeof(snum)/sizeof(snum[0]); ++i)
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

// returns true (1) if the result is valid (result mod 10 = 0)
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

// checks for American Express standards
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

// checks for Mastercard standards
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

// checks for Visa standards
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

// runs the programs functions in order and gets back a result
void run()
{
  long int a = 0;
  printf("NUMBER: ");
  scanf("%ld", &a);

  int* seconds    = getEverySecond(a);
  int length      = 0;

  if (digitCount(a) % 10)
  {
    length = digitCount(a) / 2 + 1;
  }
  else 
  {
    length = digitCount(a) / 2;
  }

  int prodDigs    = productsDigits(seconds,length);
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

// tests
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

  int length = digitCount(a)/2;

  int* temp = getEverySecond(a);
  for (int i = 0; i < digitCount(a)/2; ++i)
  {
    printf("%d", *(temp + i));
  }
  printf("\n");

  int b = productsDigits(temp, length);
  printf("%d\n", b);

  int count = getRestSum(a);
  printf("%d\n", count);
}


