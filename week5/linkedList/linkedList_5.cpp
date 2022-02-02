// solution 1
#include <iostream>

using namespace std;

class node {
    public:
    int data;
    node *next;
};

void push(node **head, int val) {
    node *ptr = *head;
    node *newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    
    while(ptr && ptr->next)
        ptr = ptr->next;
    
    if(!ptr)
        *head = newNode;
    else
        ptr->next = newNode;
    
    return;
}

void printList(node *head) {
    node *ptr = head;
    while(ptr) {
        cout<<ptr->data<<' ';
        ptr = ptr->next;
    }
    cout<<endl;
    
    return;
}

void deleteList(node **head) {
    node *ptr = *head, *next = NULL;
    while(ptr) {
        next = ptr->next;
        delete ptr;
        ptr = next;
    }
    *head = NULL;
    
    return;
}

int main() {
    node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printList(head);
    deleteList(&head);
    printList(head);
    
    return 0;
}