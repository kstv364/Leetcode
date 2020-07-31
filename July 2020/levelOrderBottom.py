class Solution(object):
    def levelOrderBottom(self, root):
        
        if(root==None):
            return []
        ans = [[root.val]]
        deq = deque()
        deq.append(root)
        while(len(deq)>0):
            sz = len(deq)
            row = []
            while(sz>0):
                curr = deq.popleft()
                if(curr!=None):
                    row += [curr.left,curr.right]
                    deq.append(curr.left)
                    deq.append(curr.right)
                sz-=1
            row = [e.val for e in row if e]
            if(row!=[]):
                ans.append(row)
        return ans[::-1]
            
       