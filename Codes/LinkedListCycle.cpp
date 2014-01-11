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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *front, *back;
        back = front = head;
        while (front->next != NULL) {	
        	if (front->next->next == NULL) return false;
        	front = front->next->next;
        	back = back->next;
        	if (front == back) return true;
        }
        return false;
    }
};