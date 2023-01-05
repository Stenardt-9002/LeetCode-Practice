class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        list_s = list(s.split(" "))
        if(len(pattern)!=len(list_s)):
            return False
        dictionary = {}
        reverse_dict = {}
        for i in range(len(pattern)):
            if (pattern[i] not in dictionary.keys()) or (list_s[i] not in reverse_dict.keys()):
                if (pattern[i] not in dictionary.keys()) and (list_s[i] not in reverse_dict.keys()):
                    reverse_dict[list_s[i]] = pattern[i]
                    dictionary[pattern[i]] = list_s[i]
                else :
                    return False 
            elif dictionary[pattern[i]]!=list_s[i] or reverse_dict[list_s[i]]!=pattern[i]:
                return False

        return True 
