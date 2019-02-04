#include <stdio.h>
//void do2D(point2D *p)
//{
//	printf("2D");
//}
//void do3D(point3D *p)
//{
//	printf("3D");
//}
//#define typename(x) _Generic((x), \
//  point3D   : "point3D", \
//  point2D   : "point2D", \
//  point3D * : "pointer to point3D", \
//  point2D * : "pointer to point2D"  \
//)
//
//
//
//#define doSomething(X) _Generic((X), \
//  point3D* : do3D, \
//  point2D* : do2D \
//) (X)

//typedef struct point2D
//{
//	void *prvtPoint2D;
//	int(*getX) (struct point2D*);
//	void(*setX)(struct point2D*, int);
//} point2D;
//point2D* newPoint2D();
//void deletePoint2D(point2D*);
//
//typedef struct private {
//	int x;
//	int y;
//} private;

typedef struct point2D {
	int x, y;
}point2D;
typedef struct point3D {
	struct point2D;
	int z;
} point3D;

//static int getx(struct point2D*p) {
//	return ((struct private*)(p->prvtPoint2D))->x;
//}
//static void setx(struct point2D *p, int val) {
//	((struct private*)(p->prvtPoint2D))->x = val;
//}
//
//point2D* newPoint2D() {
//	point2D* ptr;
//	ptr = (point2D*)malloc(sizeof(point2D));
//	ptr->prvtPoint2D = malloc(sizeof(private));
//	ptr->getX = &getx;
//	ptr->setX = &setx;
//	// ....
//	return ptr;
//}
//
//void deletePoint2D(point2D* point)
//{
//	free(point);
//}

void do2D(point2D *p);
void do3D(point3D *p);

#define doSomething(X) _Generic((X), \
  point3D* : do3D, \
  point2D* : do2D \
) (X)

void do2D(point2D *p)
{
	printf("2D");
}
void do3D(point3D *p)
{
	printf("3D");
}

point3D* newPoint3D() {
	point2D* ptr;
	ptr = (point3D*)malloc(sizeof(point3D));/*
	ptr->prvtPoint3D = malloc(sizeof(private));
	ptr->getX = &getx;
	ptr->setX = &setx;*/
	// ....
	return ptr;
}

int main()
{
	puts("Hello, World!");
	/*point2D *point = newPoint2D();
	int p = point->getX(point);
	point->setX(point, 42);
	p = point->getX(point);
	printf("p = %d\n", p);
	deletePoint2D(point);*//*
	point3D *point = newPoint3D();
	point->x = 17;
	int p = point->x;
	printf("p = %d\n", p);*/
	point3D *point = newPoint3D();
	printf("d = %f\n", doSomething(point));
	_getch();
	return 0;
}