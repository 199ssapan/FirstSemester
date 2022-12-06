#include "figures.h"

double getParalVol(Parallelepiped* p)
{
	return p->height * p->length * p->width;
}

double getCylinderVol(Cylinder* c)
{
	return c->height * PI * c->radius * c->radius;
}

double getSphereVol(Sphere* s)
{
	return 4 * PI * s->radius * s->radius;
}

double getTrianPrVol(TrianglePrism* tp)
{
	return tp->baseArea * tp->height;
}

double getSqPyrVol(SquarePyramid* sp)
{
	return (1.0 / 3.0) * sp->baseArea * sp->height;
}

Parallelepiped* newPar()
{
	Parallelepiped* p = (Parallelepiped*)malloc(sizeof(Parallelepiped));
	p->height = 0.0;
	p->length = 0.0;
	p->width = 0.0;
	return p;
}

Cylinder* newCyl()
{
	Cylinder* c = (Cylinder*)malloc(sizeof(Cylinder));
	c->height = 0.0;
	c->radius = 0.0;
	return c;
}

Sphere* newSph()
{
	Sphere* s = (Sphere*)malloc(sizeof(Sphere));
	s->radius = 0.0;
	return s;
}

TrianglePrism* newTrPr()
{
	TrianglePrism* tp = (TrianglePrism*)malloc(sizeof(TrianglePrism));
	tp->baseArea = 0.0;
	tp->height = 0.0;
	return tp;
}

SquarePyramid* newSqPr()
{
	SquarePyramid* sp = (SquarePyramid*)malloc(sizeof(SquarePyramid));
	sp->baseArea = 0.0;
	sp->height = 0.0;
	return sp;
}