# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        if head == None:
            return head
        h0 = ListNode(0)
        h0.next = head
        curr, prev = head.next, head
        while curr != None:
            nd, ndPrev = h0.next, h0
            while nd != curr:
                if curr.val < nd.val:
                    #insert curr before nd
                    #curr.next, prev.next, ndPrev.next are affected
                    prev.next = curr.next
                    curr.next = nd
                    ndPrev.next = curr
                nd, ndPrev = nd.next, ndPrev.next
            curr, prev = curr.next, prev.next
        return h0.next
