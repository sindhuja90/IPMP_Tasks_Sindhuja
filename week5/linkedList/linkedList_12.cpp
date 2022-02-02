// solution 1
void deleteAlt(struct Node *head){
    // Code here
    Node *ptr = head, *next = NULL;
    while(ptr && ptr->next) {
        next = ptr->next;
        ptr->next = next->next;
        delete next;
        ptr = ptr->next;
    }
}

// solution 2
void deleteAlt(struct Node *head){
    // Code here
    if(!head || !head->next)
        return;
        
    Node *ptr = head->next;
    head->next = ptr->next;
    delete(ptr);
    deleteAlt(head->next);
}
