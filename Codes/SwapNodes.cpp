class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *n0 = new ListNode(0);
        n0->next = head;
        ListNode *nCur = head, *nNext = head->next, *nPrev = n0;
        
        while (nNext) {
            nCur->next = nNext->next;
            nNext->next = nCur;
            nPrev->next = nNext;
            
            if (!nCur->next)
                break;
            nPrev = nCur;
            nCur = nCur->next;
            nNext = nCur->next;
        }
        head = n0->next;
        delete n0;
        return head;
    }
};
