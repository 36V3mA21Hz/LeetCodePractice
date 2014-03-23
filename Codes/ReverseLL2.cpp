class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m == n)
        	return head;
        ListNode *n0 = new ListNode(0);
        n0->next = head;
        head = n0;
        ListNode *nCur = head->next, *nPrev = head, *nGate = NULL, *nStart = NULL;
        int i = 1;
        while (nCur) {
        	if (i++ == m) {
        		nGate = nPrev;
        		nStart = nCur;
        		break;
        	}
        	nPrev = nCur;
        	nCur = nCur->next;
        }
        nPrev = nCur;
        nCur = nCur->next;
        while (i <= n && nCur) {
        	nPrev->next = nCur->next;
        	nGate->next = nCur;
        	nCur->next = nStart;
        	nStart = nCur;
        	nCur = nPrev->next;
            i++;
        }
        head = n0->next;
        delete n0;
        return head;
    }
};
