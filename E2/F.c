#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100005

struct position
{
    int x;
    int y;
};

struct Node
{
    int index;
    struct position position;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *rear = NULL;

struct Node *createNode(int index, int x, int y);
void enqueue(int index, int x, int y);
void dequeue();
bool is_empty();
void reset_queue();

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        // -2 means destination, -1 means obstacle, 0 means empty, 1 means start, others means the times to reach the point
        int **map = (int **)malloc((unsigned long long)n * sizeof(int *));
        for (int j = 0; j < n; j++)
        {
            map[j] = (int *)malloc((unsigned long long)m * sizeof(int));
            for (int k = 0; k < m; k++)
            {
                map[j][k] = 0;
            }
        }
        int start_x, start_y;
        scanf("%d %d", &start_x, &start_y);
        map[start_x - 1][start_y - 1] = 1;
        enqueue(1, start_x - 1, start_y - 1);
        int dest_x, dest_y;
        scanf("%d %d", &dest_x, &dest_y);
        map[dest_x - 1][dest_y - 1] = -2;
        for (int j = 0; j < n; j++)
        {
            char row[m + 1];
            scanf("%s", row);
            for (int k = 0; k < m; k++)
            {
                if (map[j][k] != 0)
                {
                    continue;
                }
                else if (row[k] == '#')
                {
                    map[j][k] = -1;
                }
                else if (row[k] == '.')
                {
                    map[j][k] = 0;
                }
            }
        }
        bool found = false;
        while (!is_empty())
        {
            int x = head->position.x, y = head->position.y;
            int index = head->index;
            dequeue();

            // up
            int up_x = x, up_y = y;
            while (up_x - 1 >= 0 && map[up_x - 1][up_y] != -1 && map[up_x][up_y] != -2)
            {
                up_x--;
            }
            if (map[up_x][up_y] == -2)
            {
                printf("%d\n", index);
                found = true;
                break;
            }
            if (up_x != x && map[up_x][up_y] == 0)
            {
                enqueue(index + 1, up_x, up_y);
                map[up_x][up_y] = index + 1;
            }

            // down
            int down_x = x, down_y = y;
            while (down_x + 1 < n && map[down_x + 1][down_y] != -1 && map[down_x][down_y] != -2)
            {
                down_x++;
            }
            if (map[down_x][down_y] == -2)
            {
                printf("%d\n", index);
                found = true;
                break;
            }
            if (down_x != x && map[down_x][down_y] == 0)
            {
                enqueue(index + 1, down_x, down_y);
                map[down_x][down_y] = index + 1;
            }

            // left
            int left_x = x, left_y = y;
            while (left_y - 1 >= 0 && map[left_x][left_y - 1] != -1 && map[left_x][left_y] != -2)
            {
                left_y--;
            }
            if (map[left_x][left_y] == -2)
            {
                printf("%d\n", index);
                found = true;
                break;
            }
            if (left_y != y && map[left_x][left_y] == 0)
            {
                enqueue(index + 1, left_x, left_y);
                map[left_x][left_y] = index + 1;
            }

            // right
            int right_x = x, right_y = y;
            while (right_y + 1 < m && map[right_x][right_y + 1] != -1 && map[right_x][right_y] != -2)
            {
                right_y++;
            }
            if (map[right_x][right_y] == -2)
            {
                printf("%d\n", index);
                found = true;
                break;
            }
            if (right_y != y && map[right_x][right_y] == 0)
            {
                enqueue(index + 1, right_x, right_y);
                map[right_x][right_y] = index + 1;
            }
        }

        if (!found)
        {
            printf("-1\n");
        }

        for (int j = 0; j < n; j++)
        {
            free(map[j]);
        }
        free(map);

        reset_queue();
    }

    return 0;
}

struct Node *createNode(int index, int x, int y)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->index = index;
    node->position.x = x;
    node->position.y = y;
    node->next = NULL;
    return node;
}

void enqueue(int index, int x, int y)
{
    struct Node *node = createNode(index, x, y);
    if (head == NULL)
    {
        head = node;
        rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
}

void dequeue()
{
    if (is_empty())
    {
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    if (head == NULL)
    {
        rear = NULL;
    }
}

bool is_empty()
{
    return head == NULL;
}

void reset_queue()
{
    while (!is_empty())
    {
        dequeue();
    }
}