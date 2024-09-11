#ifndef CUSTOM_FUNCTIONS_H
#define CUSTOM_FUNCTIONS_H
#include "datastructures.h"
#include "mapping.h"

// Dispatch a truck with a package to the closest route
int dispatchTruck(struct Package package, struct Truck* trucks);
// Check if the weight and capacity of a package are valid for a given truck
int isValidWeight(struct Truck truck, struct Package package);
// Euclidean distance
int convertToInt(char letter);
// Initialize a truck with a given route
void initializeTruck(struct Truck* truck, struct Route route);
// Prompt the user for shipment details
int promptUser(struct Package*, struct Map*);

char convertToLetter(int number);
int isTruckFull(struct Truck* truck);
int allTrucksAreFull(struct Truck* trucks, int numTrucks);

#endif // !CUSTOM_FUNCTIONS_H

