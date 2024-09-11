#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "custom_functions.h"
#include "datastructures.h"

int main(void)
{
	struct Truck trucks[3] = { 0 };
	struct Package package;
	struct Point pt = {
		7, 24 };
	package.destination = pt;
	package.weight = 100;
	package.capacity = 2.0;

	dispatchTruck(package, trucks);
	struct Point pt2 = {
		12, 11 };
	package.destination = pt2;
	package.weight = 100;
	package.capacity = 2.0;
	dispatchTruck(package, trucks);



	return 0;
}