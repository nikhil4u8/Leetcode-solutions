//TIME - O(2^(M*N)*M*N)
//Backtracking
// class Solution {
// public:
//     bool isZeroMatrix(vector<vector<int>>&mat, int n, int m){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j] != 0)
//                     return false;
//             }
//         }
        
//         return true;
//     }
//     void flipMatrix(vector<vector<int>>&mat, int x, int y, int n, int m){
//         mat[x][y] ^= 1;
//         if(x-1>=0) mat[x-1][y] ^= 1;
//         if(x+1<n) mat[x+1][y] ^= 1;
//         if(y-1>=0) mat[x][y-1] ^= 1;
//         if(y+1<m) mat[x][y+1] ^= 1;
//     }
//     int minimumFlips(vector<vector<int>>mat, int n, int m, int x, int y){
//         if(y == m){
//             x++;
//             y = 0;
//         }
//         if(x == n) return isZeroMatrix(mat, n, m) ? 0 : INT_MAX;
        
//         int temp1 = minimumFlips(mat, n, m, x, y+1);
        
//         flipMatrix(mat, x, y, n, m);
//         int temp2 = minimumFlips(mat, n, m, x, y+1);
//         if(temp2 != INT_MAX) temp2++;
        
        
//         return min(temp1, temp2);
//     }
//     int minFlips(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         int ans = minimumFlips(mat, n, m, 0, 0);
        
//         if(ans == INT_MAX) return -1;
//         return ans;
//     }
// };
//TIME - O(2^(M*N)*M*N)
//BFS
class Solution {
public:
    vector<int>dir = {0, 0, 1, 0, -1, 0};
    int minFlips(vector<vector<int>>& mat) {
        int start = 0, m = mat.size(), n = mat[0].size();
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                start |= mat[i][j] << (i * n + j); 
        
        queue<int>q;
        unordered_map<int, bool>visited;
        
        q.push(start);
        visited[start] = true;
        int step = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr_state = q.front(); q.pop();
                
                if(curr_state == 0) return step;
                
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        
                        int next_state = curr_state;
                        for(int k=0;k<5;k++){
                            int r = i + dir[k], c = j + dir[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n)
                                next_state ^= 1 << (r * n + c);
                        }
                        
                        if(visited.find(next_state) == visited.end()){
                            visited[next_state] = true;
                            if(next_state == 0) return step+1;
                            q.push(next_state);
                        }
                        
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};