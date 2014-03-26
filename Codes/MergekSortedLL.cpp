class Solution {
public:
	typedef vector<ListNode *>::iterator vit;
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
        	return NULL;
        ListNode *head = *(lists.begin());
        for (vit i = lists.begin() + 1; i != lists.end(); i++) {
            head = merge2Lists(head, *(i));
        }
        return head;
    }
    ListNode *merge2Lists(ListNode *n1, ListNode *n2) {
    	ListNode *n0 = new ListNode(0);
    	ListNode *head = n0;
    	while (n1 || n2) {
    		if (n1 && n2) {
    			if (n1->val <= n2->val) {
    				linkNode(head, n1);
    			} else {
    				linkNode(head, n2);
    			}
    		} else if (n1) {
    			linkNode(head, n1);
    		} else if (n2) {
    			linkNode(head, n2);
    		}
    	}
    	head = n0->next;
    	delete n0;
    	return head;
    }
    void linkNode(ListNode *&head, ListNode *&n) {
    	head->next = n;
		head = head->next;
        n = n->next;
		head->next = NULL;
    }
};
