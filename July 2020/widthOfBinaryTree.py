# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if(root==None):
            return 0
        
        result = 0
        q = Myqueue()
        q.append(root)
        flag = 0
        while(q.size()>0):
            n = q.size()
            result = max(result,n)
            for _ in range(n):
                top = q.pop_left()
                if(top!=None):
                    q.append(top.left)
                    q.append(top.right)
                else:
                    q.append(None)
                    q.append(None)        
            
            while(q.size()>0 and q.left()==None):
                q.pop_left()
            while(q.size()>0 and q.right()==None):
                q.pop()
        return result
            
class Myqueue(object):
    def __init__(self):
        self.q =deque([])
        self.si = 0
    def append(self,x):
        self.q.append(x)
        self.si += 1
        
    def size(self):
        return self.si 
    def pop_left(self):
        self.si -= 1
        return self.q.popleft()
    def pop(self):
        self.si -= 1
        return self.q.pop()
    
    def left(self):
        return self.q[0]
    def right(self):
        return self.q[-1]