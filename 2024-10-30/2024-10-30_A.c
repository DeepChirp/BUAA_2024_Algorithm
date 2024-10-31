#include <stdio.h>
#include <stdlib.h>

struct dishes
{
    int price;
    int taste;
    double ratio;
};

int compare(const void *a, const void *b);

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    struct dishes *dishes = malloc((unsigned int)n * sizeof(struct dishes));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &dishes[i].taste, &dishes[i].price);
        dishes[i].ratio = (double)dishes[i].taste / dishes[i].price;
    }

    qsort(dishes, (unsigned int)n, sizeof(struct dishes), compare);

    double total_taste = 0;
    int index = 0;
    while (k > 0)
    {
        if (k >= dishes[index].price)
        {
            total_taste += dishes[index].taste;
            k -= dishes[index].price;
        }
        else
        {
            total_taste += dishes[index].ratio * k;
            k = 0;
        }
        index++;
    }

    printf("%.3lf\n", total_taste);

    return 0;
}

int compare(const void *a, const void *b)
{
    struct dishes *d1 = (struct dishes *)a;
    struct dishes *d2 = (struct dishes *)b;

    if (d1->ratio > d2->ratio)
    {
        return -1;
    }
    else if (d1->ratio < d2->ratio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
