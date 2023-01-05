class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections)<n-1:
            return -1 
        graph_1 = [set() for i in range(n)]
        for i,j in connections:
            graph_1[i].add(j)
            graph_1[j].add(i)
        visited = [0]*n 

        def dfs_u(i):
            if visited[i]:
                return 0 
            visited[i] = 1 
            for j in graph_1[i]:
                dfs_u(j)
            return 1
        return sum(dfs_u(i) for i in range(n))-1