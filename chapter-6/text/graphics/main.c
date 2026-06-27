/* This program illustrates the usage of structures and operators '.' and '->'
   via concepts that occur in graphics. */

#include <math.h>
#include <stdio.h>

#define XMAX 16
#define YMAX 9
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);

int main() {
    struct point a = {3, 4};
    double dist = sqrt((double)(a.x * a.x + a.y * a.y));
    printf("Coordinates of point a are a.x = %d and a.y = %d.\n", a.x, a.y);
    printf("It's distance from origin is %f.\n", dist);

    struct rect screen;
    struct point middle;
    screen.pt1 = makepoint(XMAX, YMAX);
    screen.pt2 = makepoint(0, 0);
    middle = addpoint(screen.pt1, screen.pt2);
    middle = makepoint(middle.x / 2, middle.y / 2);
    printf("Screen's middle point is (%d, %d).\n", middle.x, middle.y);

    screen = canonrect(screen);
    printf("Is middle point inside the screen? %d.\n", ptinrect(middle, screen));

    struct point origin = {0, 0}, *p;
    p = &origin;
    printf("Origin is (%d, %d).\n", (*p).x, (*p).y);
    printf("Origin is (%d, %d).\n", p->x, p->y);

    return 0;
}

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}

int ptinrect(struct point p, struct rect r) {
    int xcheck = p.x >= r.pt1.x && p.x <= r.pt2.x;
    int ycheck = p.y >= r.pt1.y && p.y <= r.pt2.y;

    return xcheck && ycheck;
}

struct rect canonrect(struct rect r) {
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);

    return temp;
}
