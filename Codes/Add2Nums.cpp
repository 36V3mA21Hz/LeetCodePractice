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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *n0 = new ListNode(0);
//		n0->next = l1;
//        l1 = reverseNodes(n0, NULL)->next;
//        n0->next = l2;
//        l2 = reverseNodes(n0, NULL)->next;
        ListNode *head = n0;
        int carry = 0;
        while (l1 || l2) {
        	if (l1 && l2) {
        		int rem = (l1->val + l2->val + carry) % 10;
        		carry = (l1->val + l2->val + carry) / 10;
        		head->next = new ListNode(rem);
        		head = head->next;
        		l1 = l1->next;
        		l2 = l2->next;
        	} else if (l1) {
        		int rem = (l1->val + carry) % 10;
        		carry = (l1->val + carry) / 10;
        		head->next = new ListNode(rem);
        		head = head->next;
        		l1 = l1->next;
        	} else if (l2) {
        		int rem = (l2->val + carry) % 10;
        		carry = (l2->val + carry) / 10;
        		head->next = new ListNode(rem);
        		head = head->next;
        		l2 = l2->next;
        	}
        }
        if (carry) {
        	head->next = new ListNode(carry);
        }
//        head = reverseNodes(n0, NULL);
        return n0->next;
        
    }
//    ListNode *reverseNodes(ListNode *head, ListNode *end) {
//    	ListNode *nC = head->next, *nN = head->next->next;
//    	while (nN != end) {
//            nC->next = nN->next;
//    		nN->next = head->next;
//            head->next = nN;
//    		nN = nC->next;
//    	}
//    	return head;
//    }
};