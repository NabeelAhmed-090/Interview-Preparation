# https://leetcode.com/problems/reverse-linked-list/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def recurList(self, head, curr,  prev):
        nextNode = curr.next
        curr.next = prev
        if nextNode == None:
            curr.next = ListNode()
            curr.next = prev
            return curr
        return self.recurList(head, nextNode, curr)

    def reverseList(self, head):
        if head == None:
            return head
        return self.recurList(head, head, None)
