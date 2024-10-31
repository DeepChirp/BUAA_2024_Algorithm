#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int group;
    scanf("%d", &group);
    for (int i = 0; i < group; i++)
    {
        int person;
        scanf("%d", &person);
        int persons[10000];
        int sum = 0;
        memset(persons, 0, sizeof(persons));
        for (int j = 0; j < person; j++)
        {
            int height;
            scanf("%d", &height);
            for (int k = 0; k < j + 1; k++)
            {
                if (height >= persons[k])
                {
                    sum++;
                }
                else
                {
                    for (int l = j; l > k; l--)
                    {
                        persons[l] = persons[l - 1];
                        sum++;
                    }
                    persons[k] = height;
                    break;
                }
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
