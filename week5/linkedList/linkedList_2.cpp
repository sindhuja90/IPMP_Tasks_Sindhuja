// solution 1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *ptr=head, *forward;
        while(ptr) {
            forward = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = forward;
        }
        head = prev;
        
        return head;
    }
};

// solution 2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        
        ListNode *rest = reverseList(head->next);
        head->next->next = head;
        
        head->next = NULL;
        
        return rest;
    }
};

// solution 3
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        ListNode *temp = head;
        
        if(!temp || !temp->next)
            return head;
        
        while(temp->next) {
            s.push(temp);
            temp = temp->next;
        }
        head = temp;
        
        while(!s.empty()) {
            temp->next = s.top();
            s.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        
        return head;
    }
};