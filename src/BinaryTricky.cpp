//
// Created by David Wang on 24-11-16.
//

#include "BinaryTricky.h"

int TwoTimesPlusOne(int n)
{
    return (n << 1) | 1;
}

bool IsPowerOfTwo(int n)
{
    return (n && ((n & (n - 1)) == 0));
}

bool IsPowerOfTwoOrZero(int n)
{
    return ((n & (n - 1)) == 0);
}

int CountOnes(int n)
{
    int c;
    for (c = 0; n; c++) n &= n - 1;
    return c;
}

unsigned long long RoundUpToNextPowerOfTwo(unsigned long long n)
{
    n--;
    n |= n >> 1; n |= n >> 2; n |= n >> 4; n |= n >> 8; n |= n >> 16; n |= n >> 32;
    n++;
    return n;
}
