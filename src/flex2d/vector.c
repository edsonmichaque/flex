#include <flex2d/vector.h>
#include <stdlib.h>
#include <math.h>

Vector *vector_new(double x, double y)
{
	Vector *v = (Vector *)calloc(1, sizeof(Vector));

	if (NULL == v) {
		return NULL;
	}

	v->x = x;
	v->y = y;

	return v;
}

double vector_distance_squared(Vector *v)
{
	if (NULL == v) {
		return 0.0;
	}

	return v->x*v->x + v->y*v->y;
}

double vector_distance(Vector *v)
{
	return sqrt(vector_distance_squared(v)); 
}
