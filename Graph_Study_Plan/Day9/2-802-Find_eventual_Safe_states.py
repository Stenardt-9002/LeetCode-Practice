class Solution:
    def eventualSafeNodes(self, graph):
        N = len(graph)
        dp = [-1] * N
        def dfs(x):
            if dp[x] != -1: return dp[x]
            dp[x] = 0
            for i in graph[x]:
                if dfs(i) == 0:
                    return 0
            dp[x] = 1
            return 1
        return [i for i in range(N) if dfs(i)]


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        visited = [0]*n 
        def dfs_u(src):
            visited[src] = 1 
            for child in graph[src]:
                if visited[child]==1 or (visited[child]==0 and dfs_u(child)==False):
                    return False #found cycle 
            visited[src] = 2
            return True # no cycle 
            
        ans = []
        for i in range(n):
            if (visited[i]==2 or(visited[i]==0 and dfs_u(i))):
                ans.append(i)
        return ans 
            

    




