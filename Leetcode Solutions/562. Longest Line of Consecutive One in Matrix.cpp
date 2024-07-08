class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0) return 0;
        int m = mat[0].size();
        
        int res = 0;
        vector<vector<int>>hori(n, vector<int>(m, 0));
        vector<vector<int>>vert(n, vector<int>(m, 0));
        vector<vector<int>>diag(n, vector<int>(m, 0));
        vector<vector<int>>antid(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) continue;
                hori[i][j] = mat[i][j];
                vert[i][j] = mat[i][j];
                diag[i][j] = mat[i][j];
                antid[i][j] = mat[i][j];
                
                if(j!=0) hori[i][j] += hori[i][j-1];
                if(i!=0) vert[i][j] += vert[i-1][j];
                if(i>0 && j>0) diag[i][j] += diag[i-1][j-1];
                if(i>0 && j!=m-1) antid[i][j] += antid[i-1][j+1]; 
                
                res = max({res, diag[i][j], vert[i][j], hori[i][j], antid[i][j]});
            }
        }
        
        return res;
    }
};