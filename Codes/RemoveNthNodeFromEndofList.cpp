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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || n == 0)
        	return NULL;
        ListNode *n0 = new ListNode(0);
        n0->next = head;
        ListNode *p1 = n0, *p2 = n0, *p2Prev = NULL;
        int i = 1;
        while (i <= n && p1 != NULL) {
        	p1 = p1->next;
        	i++;
        }
        while (p1 != NULL) {
        	p1 = p1->next;
        	p2Prev = p2;
        	p2 = p2->next;
        }
        if (p2Prev) {
        	p2Prev = p2->next;
        	delete p2;
        }
        head = n0->next;
        delete n0;
        return head;
    }
};