// solution 1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode *ptr = head;
        
        while(ptr) {
            if(s.find(ptr) != s.end())
                return true;
            s.insert(ptr);
            ptr = ptr->next;
        }
        return false;
    }
};

// solution 2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        return false;
    }
};

// solution 3
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr = head, *temp = new ListNode, *next = NULL;
        while(ptr) {
            if(ptr->next == temp)
                return true;
            
            next = ptr->next;
            ptr->next = temp;
            ptr = next;
        }
        return false;
    }
};

// solution 4
class Solution {
public:
    int distance(ListNode *ptr1, ListNode *ptr2) {
        int count = 0;
        ListNode *curr = ptr1;
        while(curr != ptr2) {
            curr = curr->next;
            count++;
        }
        return count+1;
    }
    
    bool hasCycle(ListNode *head) {
        ListNode *first = head, *last = head;
        int currLen = 0, prevLen = -1;
        while(currLen>prevLen && last) {
            prevLen = currLen;
            currLen = distance(first, last);
            last = last->next;
        }
        if(last)
            return true;
        else
            return false;
    }
};