#ifndef __VECTOR_H__
#define __VECTOR_H_

typedef struct Vector_t Vector;
typedef struct Vector Point;

struct Vector_t
{
	double x, y;
};

Vector *vector_new(double, double);
double vector_distance_squared(Vector *);
double distance(Vector *);

#endif /* __VECTOR_H__ */
