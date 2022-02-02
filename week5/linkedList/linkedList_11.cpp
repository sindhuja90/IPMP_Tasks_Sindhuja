// solution 1
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *ptr1 = head1, *ptr2 = head2, *head3 = NULL, *ptr3 = head3;
    while(ptr1 && ptr2) {
        if(ptr1->data < ptr2->data)
            ptr1 = ptr1->next;
        else if(ptr1->data > ptr2->data)
            ptr2 = ptr2->next;
        else {
            Node *newNode = new Node(ptr1->data);
            if(!head3)
                head3 = newNode;
            else
                ptr3->next = newNode;
            ptr3 = newNode;
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    
    return head3;
}

// solution 2
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<int> hash;
    Node *ptr1 = head1, *ptr2 = head2, *head3 = NULL, *ptr3 = head3;
    while(ptr1) {
        hash.insert(ptr1->data);
        ptr1 = ptr1->next;
    }
    while(ptr2) {
        if(hash.find(ptr2->data) != hash.end()) {
            if(ptr3 && ptr3->data == ptr2->data) {
                ptr2 = ptr2->next;
                continue;
            }
            Node *newNode = new Node(ptr2->data);
            if(!head3)
                head3 = newNode;
            else
                ptr3->next = newNode;
            ptr3 = newNode;
        }
        ptr2 = ptr2->next;
    }
    return head3;
}