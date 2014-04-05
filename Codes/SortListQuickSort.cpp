class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head)
        	return NULL;
        ListNode *n = head;
        int length = 1;
        while (n->next) {
        	length++;
        	n = n->next;
        }
        quicksort(head, n, 1, length);
        return head;
    }
    void quicksort(ListNode *p, ListNode *r, int pi, int ri) {
    	if (pi < ri) {
            int qi = 0;
    		ListNode *q = partition(p, r, pi, ri, qi);
    		quicksort(p, q, pi, qi - 1);
    		quicksort(q->next->next, r, qi + 1, ri);
    	}
    }
    ListNode *partition(ListNode *p, ListNode *r, int pi, int ri, int &qi) {
       	ListNode *n0 = new ListNode(0);
    	n0->next = p;
    	int x = rand() % (ri - pi + 1) + 1;
    	int k = 0;
    	ListNode *n = n0;
    	while (k != x) {
    		n = n->next;
            k++;
    	}
    	swap(n->val, r->val);
    	int temp = r->val, ii = 0;
    	ListNode *j = p, *i = n0;
    	while (j != r) {
    		if (j->val <= temp) {
    			i = i->next;
                ii++;
    			swap(i->val, j->val);
    		}
            j = j->next;
    	}
    	swap(i->next->val, r->val);
        qi = ii + pi;
    	return i;
    }
};
