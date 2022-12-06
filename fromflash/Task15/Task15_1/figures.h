#pragma once

#include <stdio.h>;
#include <stdlib.h>

#define PI 3.141592

typedef struct
{
	double length;
	double width;
	double height;
}Parallelepiped;

typedef struct
{
	double radius;
	double height;
}Cylinder;

typedef struct
{
	double radius;
}Sphere;

typedef struct
{
	double baseArea;
	double height;
}TrianglePrism;

typedef struct
{
	double baseArea;
	double height;
}SquarePyramid;

double getParalVol(Parallelepiped* p);
double getCylinderVol(Cylinder* c);
double getSphereVol(Sphere* s);
double getTrianPrVol(TrianglePrism* tp);
double getSqPyrVol(SquarePyramid* sp);
Parallelepiped* newPar();
Cylinder* newCyl();
Sphere* newSph();
TrianglePrism* newTrPr();
SquarePyramid* newSqPr();
