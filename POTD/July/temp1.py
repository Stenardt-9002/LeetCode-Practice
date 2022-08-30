class Solution:  # 44 ms, faster than 86.16%
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)  
        wordSet.discard(beginWord)

        def neighbors(word):
            for i in range(len(word)): 
                for c in ascii_lowercase:
                    newWord = word[:i] + c + word[i + 1:]
                    if newWord in wordSet:
                        yield newWord

        level = {}
        level[beginWord] = [[beginWord]]
        while level:
            nextLevel = defaultdict(list)
            for word, paths in level.items():
                if word == endWord:
                    return paths  #
                for nei in neighbors(word):
                    for path in paths:
                        nextLevel[nei].append(path + [nei])  # form new paths with `nei` word at the end
            wordSet -= set(nextLevel.keys())  # remove visited words to prevent loops
            level = nextLevel  # move to new level

        return []