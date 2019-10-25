#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct point{
    float x;
    float y;
}point_t;

point_t create_point(float x, float y){
    point_t first_point;
    first_point.x = x;
    first_point.y = y;
    return first_point;
}

float distance_between_points(point_t first, point_t second){
    float distance;
    float disx = ((second.x - first.x) * (second.x - first.x));
    float disy = ((second.y - first.y) * (second.y - first.y));
    distance = sqrtf( disx + disy );
    return distance;
}

int main()
{
    point_t p1 = create_point(1, 1);
    point_t p2 = create_point(1, 5.5f);
    float dist = distance_between_points(p1, p2);
    printf("%.2f", dist);
    return 0;

}