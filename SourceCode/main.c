#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "custom_functions.h"
#include "datastructures.h"

int main(void)
{	
	struct Package package;

	struct Truck trucks[3] = { 0 };
	trucks[2].weightHolding = 800;

	struct Map baseMap = populateMap();
	struct Route blue = getBlueRoute();
	struct Route yellow = getYellowRoute();
	struct Route green = getGreenRoute();

	struct Map routeMap = addRoute(&baseMap, &yellow);
	routeMap = addRoute(&routeMap, &blue);
	routeMap = addRoute(&routeMap, &green);

	promptUser(&package,&routeMap);
	return 0;
}