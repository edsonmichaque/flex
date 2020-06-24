typedef struct Vector_t Vector;
typedef struct Vector Point;

struct Vector_t
{
	double x, y;
};

Vector *vector_new(double, double);
double vector_distance_squared(Vector *);
double vector_distance(Vector *);
