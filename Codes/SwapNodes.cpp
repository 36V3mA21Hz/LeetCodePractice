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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return NULL;
    	if (head->next == NULL) return head;
    	ListNode *n1 = head, *n2 = head->next, *n3 = NULL;
		n1->next = n2->next;
		n2->next = n1;
		if (n1->next == NULL) return head;
		if (n1->next->next == NULL) return head;
		n2 = n1->next->next;
		n1 = n1->next;
		n3 = n1;
    	while (n2 != NULL) {
    		n1->next = n2->next;
    		n2->next = n1;
    		n3->next = n2;
    		if (n1->next == NULL) return head;
    		if (n1->next->next == NULL) break;
    		n2 = n1->next->next;
    		n1 = n1->next;
    		n3 = n1;
    	}    
    	return head;
    }
};