#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

struct student
{
    char name[10];
    int scoreA;
    int scoreB;
    int scoreC;
    int scoreSum;
};
struct student students[MAX];

int compareStudents(const void *a, const void *b);

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].scoreA, &students[i].scoreB, &students[i].scoreC);
        students[i].scoreSum = students[i].scoreA + students[i].scoreB + students[i].scoreC;
    }

    qsort(students, (unsigned int)n, sizeof(struct student), compareStudents);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", students[i].name);
    }

    return 0;
}

int compareStudents(const void *a, const void *b)
{
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;
    if (s1->scoreSum != s2->scoreSum)
    {
        return s2->scoreSum - s1->scoreSum;
    }
    else if (s1->scoreA != s2->scoreA)
    {
        return s2->scoreA - s1->scoreA;
    }
    else
    {
        return strcmp(s1->name, s2->name);
    }
}