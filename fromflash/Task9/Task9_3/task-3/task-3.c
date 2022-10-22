#include <math.h.>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BEGIN_RAND_RANGE -10
#define END_RAND_RANGE 10

struct Point {
    int x;
    int y;
};

struct Vector
{
    struct Point begin;
    struct Point end;
};

int getRandInt(int beginRange, int endRange);
void randInitVector(struct Vector* vector, int beginRange, int endRange);
void printVector(struct Vector* vector);
double getVectorModule(struct Vector* vector);

double getMaxVectorModule(struct Vector* vectors, unsigned count);

int main(void) {
    printf_s("Enter a number of vectors: ");
    unsigned vectorsNumber = 0;
    scanf_s("%u", &vectorsNumber);
    struct Vector* vectors = (struct Vector*)malloc(sizeof(struct Vector) * vectorsNumber);
    if (!vectors) return 1;
    printf_s("Vectors:\n");
    for (unsigned i = 0; i < vectorsNumber; ++i) {
        randInitVector(vectors + i, BEGIN_RAND_RANGE, END_RAND_RANGE);
        printVector(vectors + i);
        printf_s("\n");
    }
    printf_s("Max vector module: %g\n", getMaxVectorModule(vectors, vectorsNumber));

    system("pause");
    return 0;
}

int getRandInt(int beginRange, int endRange) {
    static char seed = 0;
    if (!seed) {
        srand((unsigned)(time(NULL)));
        seed = 1;
    }
    return rand() % (endRange - beginRange + 1) + beginRange;
}

void randInitVector(struct Vector* vector, int beginRange, int endRange) {
    vector->begin.x = getRandInt(beginRange, endRange);
    vector->begin.y = getRandInt(beginRange, endRange);
    vector->end.x = getRandInt(beginRange, endRange);
    vector->end.y = getRandInt(beginRange, endRange);
}

void printVector(struct Vector* vector) {
    printf_s("{ (%d, %d), (%d, %d) }", vector->begin.x, vector->begin.y, vector->end.x, vector->end.y);
}

double getVectorModule(struct Vector* vector) {
    double module;
    int firstCoord = vector->end.x - vector->begin.x;
    int secondCoord = vector->end.y - vector->begin.y;
    module = sqrt(firstCoord * firstCoord + secondCoord * secondCoord);
    return module;
}

double getMaxVectorModule(struct Vector* vectors, unsigned count) {
    double* modArr = (double*)malloc(count * sizeof(double));
    for (int i = 0; i < count; i++)
    {
        modArr[i] = getVectorModule(vectors + i);
    }
    double maxMod = modArr[0];
    for (int i = 1; i < count; i++)
    {
        maxMod = modArr[i] > maxMod ? modArr[i] : maxMod;
    }
    return maxMod;
}