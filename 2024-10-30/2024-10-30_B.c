#include <stdio.h>
#include <stdlib.h>

struct competition
{
    int start;
    int last;
};

int compare(const void *a, const void *b);

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        long long current_time = 0;
        int sum = 0;
        scanf("%d", &n);
        struct competition *competition = malloc((unsigned int)n * sizeof(struct competition));
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d", &competition[j].start, &competition[j].last);
        }
        qsort(competition, (unsigned int)n, sizeof(struct competition), compare);
        for (int j = 0; j < n; j++)
        {
            if (current_time <= competition[j].start)
            {
                current_time = competition[j].start + competition[j].last;
                sum++;
            }
        }
        printf("%d\n", sum);
        free(competition);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    struct competition *c1 = (struct competition *)a;
    struct competition *c2 = (struct competition *)b;

    long long end1 = c1->start + c1->last;
    long long end2 = c2->start + c2->last;

    if (end1 > end2)
    {
        return 1;
    }
    else if (end1 < end2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}