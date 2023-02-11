

def get_list(n):
    if(n<10):
        return [n]
    list_12  = []
    while n>0:
        list_12.append(n%10)
        n = n//10 

    list_12.reverse()
    return list_12


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for i in nums:
            ans.extend(get_list(i))
        return ans 
        