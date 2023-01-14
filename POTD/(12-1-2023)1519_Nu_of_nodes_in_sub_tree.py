
# https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/




class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        graph = defaultdict(list)
        countchar = defaultdict(int)
        ans = [0]*n 
        for e0 , e1 in edges:
            graph[e0].append(e1)
            graph[e1].append(e0)


        def dfs(src = 0 , par = -1):
            temp = countchar[labels[src]]
            countchar[labels[src]] +=1 

            for child in graph[src]:
                if child!=par:
                    dfs(child , src)
            ans[src] = countchar[labels[src]]-temp 

        dfs(0,-1)
        return ans 




