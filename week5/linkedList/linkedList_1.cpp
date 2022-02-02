// solution 1
int getNthFromLast(Node *head, int n)
{
       // Your code here
        Node *ptr=head;
        int count=0, pos;
        while(ptr) {
            count++;
            ptr=ptr->next;
        } 
        pos=count-n+1;
       
        if(pos<=0)
            return -1;
        else {
            Node *ptr=head, *prev;
            count=0;
            while(count<pos) {
                prev=ptr;
                ptr=ptr->next;
                count++;
            }
            return prev->data;
        }
}

// solution 2
int getNthFromLast(Node *head, int n)
{
       // Your code here
        Node *main=head, *ref=head;
        int count=0;
        if(!head || n<=0)
            return -1;
        
        while(count<n-1) {
            ref=ref->next;
            if(!ref)
                return -1;
            count++;
        }
        
        while(ref->next) {
            ref=ref->next;
            main=main->next;
        }
        return main->data;
}
