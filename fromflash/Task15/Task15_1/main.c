#include "figures.h"

int main()
{
	Parallelepiped* p = newPar();
	p->height = 9;
	p->length = 14;
	p->width = 0.8;
	double pV = getParalVol(p);

	Cylinder* c = newCyl();
	c->height = 7.13;
	c->radius = 2.554;
	double cV = getCylinderVol(c);

	Sphere* s = newSph();
	s->radius = 27.7787;
	double sV = getSphereVol(s);

	TrianglePrism* tp = newTrPr();
	tp->baseArea = 900;
	tp->height = 0.7;
	double tpV = getTrianPrVol(tp);

	SquarePyramid* sp = newSqPr();
	sp->baseArea = 89.0001;
	sp->height = 11.11;
	double spV = getSqPyrVol(sp);

	printf_s("Parallelepiped volume: %lf\n\n", pV);
	printf_s("Cylinder volume: %lf\n\n", cV);
	printf_s("Sphere volume: %lf\n\n", sV);
	printf_s("Triangle prism volume: %lf\n\n", tpV);
	printf_s("Square pyramid volume: %lf\n\n", spV);
	return 0;
}