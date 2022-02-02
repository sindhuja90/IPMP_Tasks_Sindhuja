// solution 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *ptr = head;
        int count = 0;
        stack<int> s, s2;
        while(ptr) {
            s.push(ptr->val);
            ptr = ptr->next;
            count++;
        }
        for(int i=0; i<count/2; i++) {
            s2.push(s.top());
            s.pop();
        }
        if(count%2!=0)
            s.pop();
        
        return s==s2;
    }
};

// solution 2
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *ptr=head;
        stack<int> s;
        while(ptr) {
            s.push(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr) {
            if(ptr->val != s.top())
                return false;
            ptr=ptr->next;
            s.pop();
        }
        return true;
    }
};

// solution 3
class Solution {
public:
    void reverse(ListNode **head) {
        ListNode *prev = NULL, *curr = *head, *next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *head = prev;
        
        return;
    }
    
    bool compare(ListNode *head1, ListNode *head2) {
        ListNode *ptr1 = head1, *ptr2 = head2;
        while(ptr1 && ptr2) {
            if(ptr1->val != ptr2->val)
                return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        if(ptr1 || ptr2)
            return false;
        
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = NULL, *second = NULL, *midnode = NULL;
        bool res = true;
        
        if(head && head->next) {
            while(fast && fast->next) {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }
            
            if(fast) {
                midnode = slow;
                slow = slow->next;
            }
            
            second = slow;
            prev->next = NULL;
            
            reverse(&second);
            res = compare(head, second);
            reverse(&second);
            
            if(midnode) {
                prev->next = midnode;
                midnode->next = second;
            }
            else
                prev->next = second;
        }
        
        return res;
    }
};