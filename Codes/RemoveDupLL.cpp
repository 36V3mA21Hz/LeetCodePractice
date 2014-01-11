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
    ListNode *deleteDuplicates(ListNode *head) {
    	if (head == NULL) return NULL;
    	ListNode *n1, *n2;
    	n1 = head;
    	n2 = head->next;
    	while (n2 != NULL) {
    		if (n2->val == n1->val) { 
    			n1->next = n2->next;
    			n2 = n2->next;
    		} else {
    			n1 = n2;
    			n2 = n2->next;
    		}
    	}
    	return head;
    }
};