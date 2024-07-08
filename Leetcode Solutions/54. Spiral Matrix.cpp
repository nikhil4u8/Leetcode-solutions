class Solution {
public:
    //Time - O(N*M)  SPACE - O(N*M)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int n = matrix.size();
        int m = matrix[0].size();
       // n=1,m=2;
        int temp = n%2==0 ? n/2-1 : n/2;
        int k = 0;
        while(k<=temp && res.size()!=n*m){
            //first row
            for(int i=k;i<m-k;i++)  res.push_back(matrix[k][i]);
            if(res.size() == n*m) break;
            //last col
            for(int i=k+1;i<n-k;i++) res.push_back(matrix[i][m-k-1]);
            if(res.size() == n*m) break;

            //last row
            for(int i=m-k-2;i>=k;i--) res.push_back(matrix[n-k-1][i]);
            if(res.size() == n*m) break;

            //first col
            for(int i=n-k-2;i>k;i--) res.push_back(matrix[i][k]);
            k++;
        }
        
        return res;
    }
};