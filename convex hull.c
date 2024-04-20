#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;

    return (p1->x - p2->x);
}


void convexHull(struct Point points[], int n) {

    if (n < 3) return;

    struct Point hull[n];
    int m = 0;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do {

        hull[m++] = points[p];

        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }


        p = q;
    } while (p != l);

    for (int i = 0; i < m; i++)
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
}
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point points[n];
    printf("Enter the coordinates of each point (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, n, sizeof(struct Point), compare);

    convexHull(points, n);

    return 0;
}
