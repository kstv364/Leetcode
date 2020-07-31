"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        
        def f(head):
            curr = head
            while(curr):
                if(curr.child):
                    curr.child = f(curr.child)
                    cur2 = curr.child
                    while(cur2.next!=None):
                        cur2 = cur2.next
                    cur2.next = curr.next
                    if(cur2.next):
                        cur2.next.prev = cur2
                    curr.next = curr.child
                    curr.next.prev = curr
                    curr.child = None
                curr = curr.next
            return head
            
            
        head = f(head)
        return head
