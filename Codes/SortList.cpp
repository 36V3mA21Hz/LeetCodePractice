class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *node = head;
        while (node->next) {
            node = node->next;
        }
        quicksort(head, node);
        return head;
    }
    void quicksort(ListNode *p, ListNode *r) {
        if (p && r && p != r && p != r->next) {
            int x = r->val;
            ListNode *n0 = new ListNode(0);
            n0->next = p;
            ListNode *i = n0, *j = p;
            while (j != r) {
                if (j->val <= x) {
                    i = i->next;
                    swap(i->val, j->val);
                }
                j = j->next;
            }
            swap(i->next->val, r->val);
            ListNode *q = i->next;
            if (i == n0)
                i = NULL;
            delete n0;
            quicksort(p, i);
            quicksort(q->next, r);
        }

    }
};
