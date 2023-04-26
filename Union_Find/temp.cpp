class Solution 
{
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> in_degree_c(n, 0);

        for (auto &edge : edges) 
        {
            graph[edge[0]].push_back(edge[1]);
            in_degree_c[edge[1]]++;
        }
        queue<int> q1;
        for (int i = 0; i < n; i++) 
            if (in_degree_c[i] == 0) 
                q1.push(i);
            

        vector<vector<int>> hash_c(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) 
            hash_c[i][colors[i] - 'a']++;
        
        int max_count = 0;
        int visited = 0;
        while (!q1.empty()) 
        {
            int u = q1.front();
            q1.pop();
            visited++;
            for (int v : graph[u]) 
            {
                for (int i = 0; i < 26; i++) 
                    hash_c[v][i] = max(hash_c[v][i], hash_c[u][i] + (colors[v] - 'a' == i ? 1 : 0));
                
                in_degree_c[v]--;
                if (in_degree_c[v] == 0) 
                    q1.push(v);
                
            }
            max_count = max(max_count, *max_element(hash_c[u].begin(), hash_c[u].end()));
        }
        return visited == n ? max_count : -1;
    }
};