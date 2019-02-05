#include <stdio.h>

typedef struct point2D {
	void *prvtPoint2D;
	int(*getX) (struct point2D*);
	void(*setX)(struct point2D*, int);
	int(*getY) (struct point2D*);
	void(*setY)(struct point2D*, int);
} point2D;

point2D* newPoint2D();
void deletePoint2D(point2D*);

typedef struct point3D {
	struct point2D;
	void *prvtPoint3D;
	int(*getZ) (struct point3D*);
	void(*setZ)(struct point3D*, int);
} point3D;

point3D* newPoint3D();
void deletePoint3D(point3D*);

typedef struct private2D {
	int x;
	int y;
} private2D;

typedef struct private3D {
	int z;
} private3D;

static int getx(struct point2D*p) 
{
	return ((struct private2D*)(p->prvtPoint2D))->x;
}

static void setx(struct point2D *p, int val) {
	((struct private2D*)(p->prvtPoint2D))->x = val;
}

static int gety(struct point2D*p)
{
	return ((struct private2D*)(p->prvtPoint2D))->y;
}

static void sety(struct point2D *p, int val) {
	((struct private2D*)(p->prvtPoint2D))->y = val;
}

static int getz(struct point3D*p)
{
	return ((struct private3D*)(p->prvtPoint3D))->z;
}

static void setz(struct point3D *p, int val) {
	((struct private3D*)(p->prvtPoint3D))->z = val;
}

point2D* newPoint2D() {
	point2D* ptr;
	ptr = (point2D*)malloc(sizeof(point2D));
	ptr->prvtPoint2D = malloc(sizeof(private2D));
	ptr->getX = &getx;
	ptr->setX = &setx;
	ptr->getY = &gety;
	ptr->setY = &sety;
	return ptr;
}

point3D* newPoint3D() {
	point3D* ptr;
	ptr = (point3D*)malloc(sizeof(point3D));
	ptr->prvtPoint2D = malloc(sizeof(private2D));
	ptr->prvtPoint3D = malloc(sizeof(private3D));
	ptr->getX = &getx;
	ptr->setX = &setx;
	ptr->getY = &gety;
	ptr->setY = &sety;
	ptr->getZ = &getz;
	ptr->setZ = &setz;
	return ptr;
}

void deletePoint2D(point2D*p)
{
	free(p->prvtPoint2D);
	free(p);
}
void deletePoint3D(point3D*p)
{
	free(p->prvtPoint2D);
	free(p->prvtPoint3D);
	free(p);
}

void print2D(point2D *p)
{
	printf("x = %d\n", p->getX);
	printf("y = %d\n", p->getY);
}

void print3D(point3D *p)
{
	printf("x = %d\n", p->getX);
	printf("y = %d\n", p->getY);
	printf("z = %d\n", p->getZ);
}

#define printPoint(X) _Generic((X), \
point2D*: print2D, \
point3D* : print3D \
)(X)

int main() {
	point2D *point2d = newPoint2D();
	point3D *point3d = newPoint3D();

	point2d->setX(point2d, 42);
	point2d->setY(point2d, 21);

	int p1x = point2d->getX(point2d);
	int p1y = point2d->getX(point2d);

	printf("p1x = %d\n", p1x);
	printf("p1y = %d\n", p1y);
	/*------------------------------------*/
	printf("------------------------------------\n");
	/*------------------------------------*/
	point3d->setX(point3d, 17);
	point3d->setY(point3d, 13);
	point3d->setZ(point3d, 7);

	int p2x = point3d->getX(point3d);
	int p2y = point3d->getY(point3d);
	int p2z = point3d->getZ(point3d);

	printf("p2x = %d\n", p2x);
	printf("p2y = %d\n", p2y);
	printf("p2z = %d\n", p2z);

	//printPoint(point2d);
	//printPoint(point3d);

	deletePoint2D(point2d);
	deletePoint2D(point3d);
	_getch();
	return 0;
}