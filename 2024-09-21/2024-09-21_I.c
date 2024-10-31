#include <stdio.h>
#include <stdlib.h>
// #include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100005

struct Fish
{
    int position;
    // bool alive;
    int left;
    int right;
    // same type
    int same_type_left;
    int same_type_right;
};

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int types[MAX];
        struct Fish fishes[n];
        memset(types, -1, sizeof(types));
        for (int j = 0; j < n; j++)
        {
            int current_type;
            scanf("%d", &current_type);
            fishes[j].position = j;
            // fishes[j].alive = true;
            fishes[j].left = j - 1;
            fishes[j].right = (j == n - 1) ? -1 : j + 1;

            fishes[j].same_type_right = -1;

            fishes[j].same_type_left = types[current_type];
            if (types[current_type] != -1)
            {
                fishes[types[current_type]].same_type_right = j;
            }

            types[current_type] = j;
        }

        int current_index = k - 1;

        do
        {
            printf("%d ", fishes[current_index].position + 1);
            int temp = current_index;

            if (fishes[current_index].same_type_left == -1 && fishes[current_index].same_type_right == -1) // no more same type
            {
                if (fishes[current_index].right == -1)
                {
                    current_index = fishes[current_index].left;
                }
                else if (fishes[current_index].left == -1)
                {
                    current_index = fishes[current_index].right;
                }
                else
                {
                    int left_distance = fishes[current_index].position - fishes[current_index].left;
                    int right_distance = fishes[current_index].right - fishes[current_index].position;
                    if (left_distance <= right_distance)
                    {
                        current_index = fishes[current_index].left;
                    }
                    else
                    {
                        current_index = fishes[current_index].right;
                    }
                }
            }
            else if (fishes[current_index].same_type_left == -1)
            {
                current_index = fishes[current_index].same_type_right;
                fishes[current_index].same_type_left = -1;
            }
            else if (fishes[current_index].same_type_right == -1)
            {
                current_index = fishes[current_index].same_type_left;
                fishes[current_index].same_type_right = -1;
            }
            else
            {
                int left_distance = fishes[current_index].position - fishes[current_index].same_type_left;
                int right_distance = fishes[current_index].same_type_right - fishes[current_index].position;
                if (left_distance <= right_distance)
                {
                    fishes[fishes[current_index].same_type_left].same_type_right = fishes[current_index].same_type_right;
                    fishes[fishes[current_index].same_type_right].same_type_left = fishes[current_index].same_type_left;
                    current_index = fishes[current_index].same_type_left;
                }
                else
                {
                    fishes[fishes[current_index].same_type_right].same_type_left = fishes[current_index].same_type_left;
                    fishes[fishes[current_index].same_type_left].same_type_right = fishes[current_index].same_type_right;
                    current_index = fishes[current_index].same_type_right;
                }
            }

            if (fishes[temp].left != -1)
            {
                fishes[fishes[temp].left].right = fishes[temp].right;
            }
            if (fishes[temp].right != -1)
            {
                fishes[fishes[temp].right].left = fishes[temp].left;
            }

        } while (fishes[current_index].same_type_left != -1 || fishes[current_index].same_type_right != -1 || fishes[current_index].left != -1 || fishes[current_index].right != -1);

        printf("%d", fishes[current_index].position + 1);
        putchar('\n');
    }

    return 0;
}
