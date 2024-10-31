#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 1010
#define MAX 20

struct Person
{
    char name[MAX_NAME_LENGTH];
    int nameLength;
    int key;
};

struct Person persons[MAX];
int count = 0;

int compareByNameLength(const void *a, const void *b)
{
    struct Person *personA = (struct Person *)a;
    struct Person *personB = (struct Person *)b;
    if (personA->nameLength != personB->nameLength)
    {
        return personA->nameLength - personB->nameLength; // Ascending order
    }
    else
    {
        return personB->key - personA->key; // Descending order
    }
}

int compareByKey(const void *a, const void *b)
{
    struct Person *personA = (struct Person *)a;
    struct Person *personB = (struct Person *)b;
    return personA->key - personB->key; // Ascending order
}

void insertPerson(struct Person person)
{
    if (count < MAX)
    {
        persons[count++] = person;
        qsort(persons, count, sizeof(struct Person), compareByNameLength);
    }
    else if (person.nameLength > persons[0].nameLength)
    {
        persons[0] = person;
        qsort(persons, MAX, sizeof(struct Person), compareByNameLength);
    }
}

int main()
{
    char buffer[MAX_NAME_LENGTH];
    int key = 0;

    while (fgets(buffer, MAX_NAME_LENGTH, stdin) != NULL)
    {
        struct Person person;
        strncpy(person.name, buffer, MAX_NAME_LENGTH);
        person.nameLength = strlen(buffer) - 1;
        person.key = key++;

        insertPerson(person);
    }

    qsort(persons, count, sizeof(struct Person), compareByKey);

    for (int i = 0; i < count; i++)
    {
        printf("%s", persons[i].name);
    }

    return 0;
}