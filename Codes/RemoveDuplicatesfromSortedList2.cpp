class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *n0 = new ListNode(0);
        n0->next = head;
        ListNode *nCur = head->next, *nStart = n0, *nEnd = head, *nPrev = head;
        while (nCur) {
            if (nCur->val == nPrev->val) {
                nEnd = nCur;
            } else {
                if (nStart->next != nEnd) {
                    ListNode *dNode1 = nStart->next;
                    ListNode *dNode2 = dNode1->next;
                    nStart->next = nEnd->next;
                    while (dNode1 != nCur) {
                        delete dNode1;
                        dNode1 = dNode2;
                        dNode2 = dNode2 ? dNode2->next : NULL;
                    }
                    nEnd = nStart->next;
                } else {
                    nStart = nEnd;
                    nEnd = nEnd->next;
                }
            }
            nPrev = nCur;
            nCur = nCur->next;
        }
        if (nStart->next != nEnd) {
            ListNode *dNode1 = nStart->next;
            ListNode *dNode2 = dNode1->next;
            nStart->next = nEnd->next;
            while (dNode1 != nCur) {
                delete dNode1;
                dNode1 = dNode2;
                dNode2 = dNode2 ? dNode2->next : NULL;
            }
            nEnd = nStart->next;
        }
        head = n0->next;
        delete n0;
        return head;
    }
};
