#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "custom_functions.h"
#include "datastructures.h"
#include "mapping.h"
#include "stdio.h"
#include <ctype.h>

// Function to check if the weight and capacity of a package are valid for a given truck
int isValidWeight(struct Truck truck, struct Package package)                           
{
	double newWeight = truck.weightHolding + package.weight;
	double newCapacity = truck.capacityHolding + package.capacity;

	if (newWeight > 1500 || newCapacity > 48)
	{
		return 0; // Invalid weight or capacity
	}
	return 1; // Valid weight and capacity
}

int isTruckFull(struct Truck* truck)                                                  
{
	return (truck->capacityHolding >= 48 || truck->weightHolding >= 1500);
}

int allTrucksAreFull(struct Truck* trucks, int numTrucks)                           
{
	int full = 0;
	for (int i = 0; i < numTrucks; i++)
	{
		if (isTruckFull(&trucks[i]))
		{
			full++;
		}
	}

	if (full == 3)
	{
		return 1;
	}

	return 0;
}

char convertToLetter(int number)                                                     
{
	if (number < 1 || number > 24)
	{
		// Print a message for an invalid number
		printf("Invalid number!");
		return '\0'; // Return null character to indicate failure
	}
	else
	{
		char result = 'A' + number - 1;
		return result;
	}
}



void printRoute(int truckIndex, struct Route* route)
{
	printf("Ship on ");
	if (truckIndex == 0)
	{
		printf("BLUE ");
	}
	else if (truckIndex == 1)
	{
		printf("YELLOW ");
	}
	else
	{
		printf("GREEN ");
	}

	if (route->numPoints == 0)
	{
		printf("LINE,  no diversion");
	}
	else
	{
		printf("LINE, ");
		for (int i = 0; i < route->numPoints; i++)
		{
			printf("%d%c", route->points[i].row + 1, convertToLetter(route->points[i].col));
			if (i != route->numPoints - 1)
			{
				printf(", ");
			}
		}
	}
	printf("\n");
}

// return the number of reroutes its gonno take
// to reach to destination
int getDistance(struct Point start, struct Point end)
{
	struct Map base = populateMap();
	printf("Ran till here");
	printf("ending at: %d,%d", end.row, end.col);
	struct Route shr = shortestPath(&base, start, end);

	return shr.numPoints;
}

// Function to dispatch a truck with a package to the closest route
int dispatchTruck(struct Package package, struct Truck* trucks)
{
	if (trucks == NULL)
	{
		return 0;
	}

	// Check if all trucks are full
	if (!allTrucksAreFull(trucks, 3))
	{
		// Initialize trucks and routes
		struct Map baseMap = populateMap();
		struct Route blue = getBlueRoute();
		struct Route yellow = getYellowRoute();
		struct Route green = getGreenRoute();

		struct Map routeMap = addRoute(&baseMap, &yellow);
		routeMap = addRoute(&routeMap, &blue);
		routeMap = addRoute(&routeMap, &green);

		// Find the closest point to the destination on each route
		int closestYellow = getClosestPoint(&yellow, package.destination);
		int closestBlue = getClosestPoint(&blue, package.destination);
		int closestGreen = getClosestPoint(&green, package.destination);

		// Calculate distances and store them with colors
		DistanceWithColor distancesWithColor[3];
		distancesWithColor[0].distance = distance(&blue.points[closestBlue], &package.destination);
		distancesWithColor[0].color = 'B'; // Blue

		distancesWithColor[1].distance = distance(&yellow.points[closestYellow], &package.destination);
		distancesWithColor[1].color = 'Y'; // Yellow

		distancesWithColor[2].distance = distance(&green.points[closestGreen], &package.destination);
		distancesWithColor[2].color = 'G'; // Green

		// Sort distanceWithColor array based on distance
		for (int i = 0; i < 3 - 1; i++)
		{
			for (int j = 0; j < 3 - i - 1; j++)
			{
				if (distancesWithColor[j].distance > distancesWithColor[j + 1].distance)
				{
					// Swap the elements
					DistanceWithColor temp = distancesWithColor[j];
					distancesWithColor[j] = distancesWithColor[j + 1];
					distancesWithColor[j + 1] = temp;
				}
			}
		}

		// Iterate through the sorted distanceWithColor array
		for (int i = 0; i < 3; i++)
		{
			int truckIndex = -1;
			struct Point start = { 1 };

			// Determine the truck index based on color
			if (distancesWithColor[i].color == 'B')
			{
				truckIndex = 0;
				start = blue.points[closestBlue];
			}
			else if (distancesWithColor[i].color == 'Y')
			{
				truckIndex = 1;
				start = yellow.points[closestYellow];
			}
			else if (distancesWithColor[i].color == 'G')
			{
				truckIndex = 2;
				start = green.points[closestGreen];
			}

			// Check if the truck is not full
			if (truckIndex != -1 && !isTruckFull(&trucks[truckIndex]))
			{
				// Add the package to the truck
				// addPackageToTruck(&trucks[truckIndex], package);

				// Print Information about the shipment
				// printf("Package shipped on Truck %d (Color : %c)\n", truckIndex + 1, distancesWithColor[i].color);

				struct Route shortest = shortestPath(&routeMap, start, package.destination);

				// printf("Number of diversion: %d \n", shortest.numPoints);
				printRoute(truckIndex, &shortest);
				// return after adding the package
				return 1;
			}
		}
	}
	else
	{
		// Print a message if all trucks are full
		printf("All trucks are full!");
		return 0;
	}
}

int convertToInt(char letter)                                                  
{
	letter = toupper(letter);

	if (letter < 'A' || letter > 'Y')
	{
		printf("Invalid letter!");
	}
	else
	{
		int result = letter - 'A';
		return result;
	}

	return 0;
}

// Function to prompt the user for shipment details
int promptUser(struct Package* package, struct Map* mapToCheck)
{
	int row_input;
	char row_char1=0;
	char row_char2=0;
	char col_letter;
	int col_input;
	printf("Enter shipment weight, box size and destination (0 0 x to stop): ");

	// Read input from the user
	if (scanf("%lf %lf %d %c", &(package->weight), &(package->capacity), &row_input, &col_letter) != 4)
	{
		printf("Terminator command entered!");
		return -1; // return -1 to indicate an error
	}

	// Check for valid weight values
	if (package->weight <= 0 || package->weight > 1500)
	{
		printf("Invalid weight (must be 1-1500 Kg.)!\n");
		while (getchar() != '\n')
			;	  // Clear the input buffer
		return 0; // Return 0 to indicate failure
	}

	// Check for valid capacity values
	if (package->capacity != 0.5 && package->capacity != 1.0 && package->capacity != 2.0)
	{
		printf("Invalid box size!\n");
		while (getchar() != '\n')
			;	  // Clear the input buffer
		return 0; // Return 0 to indicate failure
	}
	// Convert the column letter to an integer
	col_letter = toupper(col_letter);

	col_input = convertToInt(col_letter);

	if (!(col_input))
	{
		printf("Invalid destination!\n");
		return 0;
	}

	// Check for a valid destination within the map
	if ((row_input < 26 && row_input > 0) && *(&mapToCheck->squares[row_input][col_input]) != 1)
	{
		printf("Invalid destination!\n");
		return 0; // retrun 0 to indicate an error
	}

	while (getchar() != '\n')
		;	  // Clear the input buffer
	return 1; // Return 1 to indicate success
}