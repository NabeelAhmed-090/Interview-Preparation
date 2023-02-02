# https://leetcode.com/problems/linked-list-cycle/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        if head == None:
            return False
        forward = head
        previous = head
        count = 1
        while (True):
            forward = forward.next
            if count % 2 == 0:
                previous = previous.next
            if forward == None:
                return False
            if forward == previous:
                return True
            count += 1
