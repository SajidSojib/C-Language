#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;
double areaa(triangle tr)
{
    double p = (tr.a + tr.b + tr.c) / 2.0;
    double s = sqrt(p * (p - tr.c) * (p - tr.b) * (p - tr.a));
    return s;
}
void sort_by_area(triangle *tr, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int area = -1;
        int idx = -1;
        for (int j = i; j >= 0; j--)
        {
            if (areaa(tr[j]) > area)
            {
                area = areaa(tr[j]);
                idx = j;
            }
        }
        triangle temp = tr[i];
        tr[i] = tr[idx];
        tr[idx] = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}