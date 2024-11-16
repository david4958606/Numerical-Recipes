//
// Created by 王禹东 on 24-11-16.
//
#include "src/calendar.h"
#include <iostream>
#include <limits>

union UDouble
{ // variables in a union share the same memory location
	double d;
	unsigned char c[8];
};

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
	UDouble u{};
	u.d = 6.5;
	for (const unsigned char i: u.c)
	{
		printf("%02x", i);

	}
	printf("\n");
	std::cout << std::numeric_limits<double>::epsilon() << std::endl;
}
