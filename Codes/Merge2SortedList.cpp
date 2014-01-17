/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	if (l1 == NULL && l2 == NULL) return NULL;
    	else if (l1 == NULL) return l2;
    	else if (l2 == NULL) return l1;
    	ListNode *n1, *n2, *n3, *n3prev, *l3;
    	n1 = l1;
    	n2 = l2;
    	if (n1->val > n2->val) {
    		n3 = new ListNode(n2->val);
    		n2 = n2->next;
    	} else {
    		n3 = new ListNode(n1->val);
    		n1 = n1->next;
    	}
    	l3 = n3;
    	n3prev = n3;
    	while (n1 != NULL && n2 != NULL) {
    		if (n1->val > n2->val) {
    			n3 = new ListNode(n2->val);
    			n2 = n2->next;
    		} else {
    			n3 = new ListNode(n1->val);
    			n1 = n1->next;
    		}
    		n3prev->next = n3;
    		n3prev = n3;
    	}
    	ListNode *n4;
    	if (n1 == NULL && n2 == NULL) n4 = NULL; 
    	else if (n1 == NULL) n4 = n2;
    	else if (n2 == NULL) n4 = n1;
    	while (n4 != NULL) {
    		n3 = new ListNode(n4->val);
    		n3prev->next = n3;
    		n3prev = n3;
    		n4 = n4->next;
    	}
    	return l3;
    }
};