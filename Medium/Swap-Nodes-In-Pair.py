# https://leetcode.com/problems/swap-nodes-in-pairs/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def swapPairs(self, head):
        if not head or not head.next:
            return head
        pp = None
        prev = head
        curr = head.next
        retNode = curr
        while (True):
            nextNode = curr.next
            curr.next = prev
            if pp:
                pp.next = curr
            pp = prev
            prev = nextNode
            if nextNode:
                curr = nextNode.next
                if not curr:
                    pp.next = prev
                    break
            else:
                pp.next = prev
                break
        return retNode
