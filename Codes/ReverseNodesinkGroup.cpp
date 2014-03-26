class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head)
        	return head;
        ListNode *n0 = new ListNode(0);
        n0->next = head;
        head = n0;
        int i = 2, rk = 0;	//nC is at the second position.
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        len--;
        ListNode *nC = head->next->next, *nP = head->next, *nK = head, *nS = head->next;
        while (nC && k != 1 && len - rk >= k) {
        	exchange(nP, nC, nK, nS);
        	i++;
        	if (i % k == 1) {
        		nK = nP;
                rk += k;
                nS = nK->next;
        		nP = nC;
                if (nC) {
                    nC = nC->next;
                    i++;
                }
        	}
        }
        head = n0->next;
        delete n0;
        return head;
    }
    void exchange(ListNode *&nP, ListNode *&nC, ListNode *&nK, ListNode *&nS) {
    	nP->next = nC->next;
        nK->next = nC;
        nC->next = nS;
        nS = nC;
    	nC = nP->next;
    }
};
