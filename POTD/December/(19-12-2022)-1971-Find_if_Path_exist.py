class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = []
        for i in range(n):
            lis_t = []
            graph.append(lis_t)
        for ed in edges:
            graph[ed[0]].append(ed[1])
            graph[ed[1]].append(ed[0])
        
        queue = [source]
        visited = [False]*n
        visited[source] = True
        while len(queue)>0:
            gtony = queue[0]
            queue.pop(0)
            if gtony==destination:
                return True 
            for child in graph[gtony]:
                if not visited[child]:
                    queue.append(child)
                    visited[child] = True

            # if visited[gtony]:


        return False 

