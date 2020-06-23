#include <flex2d/vector.h>
#include <stdlib.h>

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
