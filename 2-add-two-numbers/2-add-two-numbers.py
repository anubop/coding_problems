# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum = ListNode()
        curr = sum
        carry = 0
        while(l1 or l2):
            
            if l1 and l2: 
                digit = l1.val + l2.val + carry
            elif l1 and not l2:
                digit = l1.val + carry
            elif l2 and not l1:
                digit = l2.val + carry
                
            if digit >= 10:
                digit = digit % 10
                carry = 1
            else:
                carry = 0
                
            curr.next = ListNode(digit)
            curr = curr.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if(carry > 0):
            curr.next = ListNode(carry)
            
        return sum.next
            
        