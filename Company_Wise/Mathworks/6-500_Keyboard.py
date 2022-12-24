# https://leetcode.com/problems/keyboard-row/


















def checkword(word , list1):
    word = ''.join(sorted(word.lower()))
    for char in word:
        if char not in list1:
            return False 
    return True 


class Solution:

    def findWords(self, words: List[str]) -> List[str]:
        row1 = ["q","w","e","r","t","y","u","i","o","p"]
        # row1.sort()
        # row1 = "".join(row1)
        row2 = ["a","s","d","f","g","h","j","k","l"]
        # row2.sort()
        # row2 = "".join(row2)
        row3 = ["z","x","c","v","b","n","m"]
        # row3.sort()
        # row3 = "".join(row3)

        ans = []
        for word in words:
            # wor = ''.join(sorted(word.lower()))
            if checkword(word,row1) or checkword(word,row2) or checkword(word,row3):
                ans.append(word)


        return ans 













