#include<iostream>
#include<malloc.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

// function to traverse the Linked List
void linkedList_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
}

// struct to insert at the beginning
struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // creates a struct that is to be linked
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    return ptr;
}

// struct to insert Before a Node
struct Node *insertBefore(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // creates a struct that is to be linked
    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    ptr -> data = data;
    p -> next = ptr;
    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevPtr, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // creates a struct that is to be linked
    
    ptr -> next = prevPtr -> next;
    prevPtr -> next = ptr;
    ptr -> data = data;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // creates a struct that is to be linked
    struct Node *p = head;

    while(p -> next != NULL)
    {
        p = p -> next;
    }
    ptr -> next = NULL;
    p -> next = ptr;
    ptr -> data = data;
    return head;

}

int main()
{
    //define Nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;

    //allocate the nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    //link the nodes
    head -> data = 5;
    head -> next = second;

    second -> data = 10;
    second -> next = third;

    third -> data = 15;
    third -> next = NULL;

    cout << "Original Linked List:";
    linkedList_traversal(head);

    cout << endl << "Insertion at the Beginning:";
    head = insertAtStart(head, 27);
    linkedList_traversal(head);

    cout << endl << "Insertion Before a Node:";
    head = insertBefore(head, 27, 2);
    linkedList_traversal(head);

    cout << endl << "Insertion After a Node:";
    head = insertBefore(head, 2, 45);
    linkedList_traversal(head);

    cout << endl << "Insertion at the End:";
    head = insertAtEnd(head, 16);
    linkedList_traversal(head);

    return 0;
}