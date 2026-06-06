# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return head
        l, r = head, head.next
        if not r: return head

        while l and r:
            l.val, r.val = r.val, l.val
            if not r.next or not r.next.next: break
            l = l.next.next
            r = r.next.next
        return head

