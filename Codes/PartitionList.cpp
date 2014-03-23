class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head)
            return NULL;
        ListNode *nCur, *nPrev;
        ListNode *n0, *n0Cur, *n0tail;
        n0 = new ListNode(0);
        n0->next = head;
        n0tail = head;
        n0Cur = n0;
        nCur = head;
        nPrev = n0;
        while (nCur) {
            if (nCur->val < x) {
                if (nCur != n0tail) {
                    nPrev->next = nCur->next;
                    n0Cur->next = nCur;
                    n0Cur = n0Cur->next;
                    n0Cur->next = n0tail;
                    nCur = nPrev->next;
                    continue;
                } else {
                    n0tail = n0tail->next;
                    n0Cur->next = nCur;
                    n0Cur = n0Cur->next;
                }
            }
            nPrev = nCur;
            nCur = nCur->next;
        }
        head = n0->next;
        delete n0;
        return head;
    }
};
