// solution 1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        unordered_map<int, ListNode*> hash;
        ListNode *ptr = head;
        int k=0;
        while(ptr) {
            hash.insert(make_pair(k, ptr));
            k++;
            ptr = ptr->next;
        }
        
        return hash[k/2];
    }
};

// solution 2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// solution 3
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *ptr = head,*mid = head;
        int k = 0;
        while(ptr) {
            if(k%2 != 0)
                mid = mid->next;
            k++;
            ptr = ptr->next;
        }
        return mid;
    }
};