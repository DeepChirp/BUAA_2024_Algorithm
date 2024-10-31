#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

long long heap[MAX_SIZE];
int heapSize = 0;

void swap(long long *a, long long *b);
void heapifyUp(int index);
void heapifyDown(int index);
void insert(long long data);
long long getBiggest();
void deleteTop();

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int op;
        long long data;
        scanf("%d", &op);
        if (op == 1)
        {
            // insert a new element
            scanf("%lld", &data);
            insert(data);
        }
        else if (op == 2)
        {
            // delete the biggest element
            deleteTop();
        }
        else if (op == 3)
        {
            // print the biggest element
            printf("%lld\n", getBiggest());
        }
    }
    // print out all elements in order
    while (heapSize > 0)
    {
        printf("%lld ", getBiggest());
        deleteTop();
    }
    printf("\n");

    return 0;
}

void swap(long long *a, long long *b)
{
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while (index > 1 && heap[index] > heap[index / 2])
    {
        swap(&heap[index], &heap[index / 2]);
        index /= 2;
    }
}

void heapifyDown(int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= heapSize && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right <= heapSize && heap[right] > heap[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

void insert(long long data)
{
    heapSize++;
    heap[heapSize] = data;
    heapifyUp(heapSize);
}

long long getBiggest()
{
    return heap[1];
}

void deleteTop()
{
    heap[1] = heap[heapSize];
    heapSize--;
    heapifyDown(1);
}