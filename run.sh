#!/bin/bash

clang -std=c11 -Werror -Wall -Wextra main.c source/credit.c -o credit

./credit
