//
// Created by 王禹东 on 24-11-16.
//
#include "calendar.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int jd = 1;
    double frac = 1.0;
    FullMoon(1, 1, jd, frac);
    std::cout << jd << " " << frac << std::endl;
    std::cout << JulDay(10, 18, 2002) << std::endl;
    int mm, id, iyyy;
    CalDat(2452566, mm, id, iyyy);
    std::cout << mm << " " << id << " " << iyyy << std::endl;
    return 0;
}
