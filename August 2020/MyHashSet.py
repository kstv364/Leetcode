class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.arr = [set([])]*(37)
        

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        self.arr[key % 37].add(key)

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        if(key in self.arr[key%37]):
            self.arr[key%37].remove(key)

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        if(key in self.arr[key%37]):
            return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)