class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
        	return NULL;
        ListNode *n0;
        n0 = new ListNode(0);
        n0->next = head;
        ListNode *nICur = head->next, *nIPrev = head, *nJCur = head, *nJPrev = n0;
        
        while (nICur) {
            nJPrev = n0;
            nJCur = n0->next;
            while (nICur->val > nJCur->val && nICur != nJCur) {
                nJPrev = nJCur;
                nJCur = nJCur->next;
            }
            nIPrev->next = nICur->next;
            nJPrev->next = nICur;
            if (nICur != nJCur) {
                nICur->next = nJCur;
                nICur = nIPrev->next;
            } else {
                nIPrev = nICur;
                nICur = nICur->next;
            }
        }
        
        head = n0->next;
        delete n0;
        return head;
    }
};
