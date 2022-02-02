// solution 1
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void remLoop(Node *head, Node *loopNode) {
        int count = 1;
        Node *ptr1 = loopNode, *ptr2 = loopNode;
        while(ptr1->next != ptr2) {
            ptr1 = ptr1->next;
            count++;
        }
        
        ptr1 = ptr2 = head;
        for(int i=0; i<count; i++)
            ptr2 = ptr2->next;
            
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr2->next != ptr1)
            ptr2 = ptr2->next;
        ptr2->next = NULL;
        
        return;
    }
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                remLoop(head, slow);
                return;
            }
        }
        return;
    }
};

// solution 2
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                Node *ptr = head, *loopNode = slow;
                while(loopNode->next != ptr) {
                    loopNode = loopNode->next;
                    if(loopNode == slow) 
                        ptr = ptr->next;
                }
                loopNode->next = NULL;
                
                break;
            }
        }
        return;
    }
};

// solution 3
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(!head || !head->next)
            return;
        
        Node *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) 
                break;
        }
        
        if(slow == fast) {
            slow = head;
            
            if(slow == fast)
                while(fast->next != slow)
                    fast = fast->next;
            
            else
                while(slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            
            fast->next = NULL;
        }
        
        return;
    }
};

// solution 4
#include <unordered_set>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        unordered_set<Node*> hash;
        Node *ptr = head, *prev = NULL;;
        while(hash.find(ptr)==hash.end() && ptr) {
            hash.insert(ptr);
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr)
            prev->next = NULL;
        
        return;
    }
};