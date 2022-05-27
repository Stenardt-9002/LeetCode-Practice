public static final int[][] direct_var = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public int longestIncreasingPath(int[][] matrix) {
    if(matrix.length == 0) return 0;
    int m = matrix.length, n = matrix[0].length;
    int[][] cache = new int[m][n];
    int max = 1;
    for(int i1 = 0; i1 < m; i1++) {
        for(int j1 = 0; j1 < n; j1++) {
            int len = dfs_util(matrix, i1, j1, m, n, cache);
            max = Math.max(max, len);
        }
    }   
    return max;
}

public int dfs_util(int[][] matrix, int i, int j, int m, int n, int[][] cache) {
    if(cache[i][j] != 0) return cache[i][j];
    int max = 1;
    for(int[] dir: direct_var) {
        int x = i + dir[0], y = j + dir[1];
        if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
        int len = 1 + dfs_util(matrix, x, y, m, n, cache);
        max = Math.max(max, len);
    }
    cache[i][j] = max;
    return max;
}