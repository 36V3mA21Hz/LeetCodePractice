class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head)
        	return NULL;
        ListNode *n = head;
        int length = 1;
        while (n->next) {
        	n = n->next;
        	length++;
        }
        mergesort(head, n);
        return head;
    }
    void mergesort(ListNode *p, int pi, int ri) {
    	if (pi < ri) {
    		int mid = (pi + ri) / 2;
    		while ()
    		mergesort(p, pi, mid - 1);
    		mergesort(p, mid + 1, ri);
    	}
    }
};
