// solution 1
#include <iostream>

using namespace std;

class node {
    public:
    int data;
    node *next;
};

void push(node **head, int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    
    return;
}

void printList(node *head) {
    node *temp = head;
    while(temp) {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
    
    return;
}

void printReverse(node *head) {
    if(!head)
        return;
        
    printReverse(head->next);
    cout<<head->data<<' ';
    
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
    printReverse(head);
    
    return 0;
}