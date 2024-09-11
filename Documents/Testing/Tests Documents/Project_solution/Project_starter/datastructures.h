#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define MAP_ROWS 25
#define MAP_COLS 25
#define MAX_ROUTE 100

/**
 * A map is a 2D raster representation of a map with contents of the map encoded as numeric values.
 */
struct Map
{
    int squares[MAP_ROWS][MAP_COLS];
    int numRows;
    int numCols;
};

/**
 * A point represents the row-column position of a square on a map.
 */
struct Point
{
    char row;
    char col;
};

/**
 * A route is a collection of points that are adjacent to one another and constitute a path from the
 * first point on the path to the last.
 */
struct Route
{
    struct Point points[MAX_ROUTE];
    int numPoints;
    char routeSymbol;
};

struct Package
{
    struct Point destination;
    double capacity; // the capacity in double value
    double weight;
};

struct Truck
{
    double weightHolding;     // weight of truck
    double capacityHolding;   // capacity in CM holding
    struct Route route;       // route to follow
    struct Package* packages; // a dynamic array of all the packages stored in this truck
};

typedef struct
{
    double distance;
    char color; // 'B' for blue, 'Y' for yellow, 'G' for green
} DistanceWithColor;

#endif // DATA_STRUCTURES_H