#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// To Traverse and Print the Linked List
void linkedList_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

struct Node *deleteAtStart(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prevPtr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (prevPtr->next->next != NULL)
    {
        prevPtr = prevPtr->next;
    }

    prevPtr->next = NULL;
    free(ptr);
    return head;
}

// To delete Before a Node
struct Node *deleteBefore(struct Node *head, int index)
{
    struct Node *ptr = head;
    int i = 0;
    while(i != index - 2)
    {
        ptr = ptr -> next;
        i++;
    }
    struct Node *prevPtr = ptr;
    ptr = ptr -> next;
    prevPtr -> next = ptr -> next;
    free(ptr);
    return head;
}

// To delete After a Node using pointer
struct Node *deleteAfter(struct Node *head, struct Node *prevPtr)
{
    struct Node *ptr = head;
    while(ptr != prevPtr -> next)
    {
        ptr = ptr -> next;
    }
    prevPtr -> next = ptr -> next;
    free(ptr);
    return head;
    
}

// To delete After a Node using Index
struct Node *deleteAfter2(struct Node *head, int index)
{
    struct Node *ptr = head;
    int i = 0;
    while(i != index)
    {
        ptr = ptr -> next;
        i++;
    }
    struct Node *prevPtr = ptr;
    ptr = ptr -> next;
    prevPtr -> next = ptr -> next;
    free(ptr);
    return head;
}

int main()
{
    // define the Nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocate the Nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link the Nodes
    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    cout << "Original Linked List: ";
    linkedList_traversal(head);

    cout << endl << "Delete in the Beginning: ";
    head = deleteAtStart(head);
    linkedList_traversal(head);

    cout << endl
         << "Delete at the End: ";
    head = deleteAtEnd(head);
    linkedList_traversal(head);

    cout << endl
         << "Delete Before a Node: ";
    head = deleteBefore(head, 2);
    linkedList_traversal(head);

    cout << endl << "Delete After a Node: ";
    head = deleteAfter2(head, 1);
    linkedList_traversal(head);

    return 0;
}