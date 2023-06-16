#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedlist_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    // define the nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate the nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link the nodes
    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = NULL;

    linkedlist_traversal(head);

    return 0;
}