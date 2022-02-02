// solution 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hashA;
        ListNode *ptrA = headA, *ptrB = headB;
        while(ptrA) {
            hashA.insert(ptrA);
            ptrA = ptrA->next;
        }
        while(ptrB && hashA.find(ptrB)==hashA.end())
            ptrB = ptrB->next;
        
        return ptrB;
    }
};

// solution 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = 0, c2 = 0, diff, k = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while(ptrA) {
            c1++;
            ptrA = ptrA->next;
        }
        while(ptrB) {
            c2++;
            ptrB = ptrB->next;
        }
        diff = abs(c1-c2);
        ptrA = headA;
        ptrB = headB;
        if(c1 > c2)
            while(k < diff) {
                ptrA = ptrA->next;
                k++;
            }
        else
            while(k < diff) {
                ptrB = ptrB->next;
                k++;
            }
        while(ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        
        return ptrA;
    }
};

// solution 3
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        if(!ptrA || !ptrB)
            return ptrA;
        
        while(ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            
            if(ptrA == ptrB)
                return ptrA;
            
            if(!ptrA)
                ptrA = headB;
            if(!ptrB)
                ptrB = headA;
        }
        
        return ptrA;
    }
};