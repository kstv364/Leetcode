class Solution(object):
    def detectCapitalUse(self, word):
        if((word.isupper()==True ) or (word.islower()==True)):
            return True
        elif((word[0].isupper()==True) and 
        	(word[1:].islower()==True)):
            return True
        return False