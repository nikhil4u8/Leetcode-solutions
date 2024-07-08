class Solution {
public:
    //Brute force
    //TIME - O(N*M*K*log(M*K))  SPACE - O(N)
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int>row = mat[0];
        
        //TIME - O(N*K*M*log(M*K))
        for(int i=1;i<mat.size();i++){
            vector<int>sum_of_2_row;
            //time - O(M*K)
            for(int j=0;j<mat[i].size();j++){
                for(int k=0;k<row.size();k++){
                    sum_of_2_row.push_back(row[k] + mat[i][j]);
                }
            }
            
            //TIME - O(M*Klog(M*K))
            sort(sum_of_2_row.begin(),sum_of_2_row.end());
            row.resize(min(k,(int)sum_of_2_row.size()));
            
            //Time - O(K)
            for(int i=0;i<min(k,(int)sum_of_2_row.size());i++) row[i] = sum_of_2_row[i];
        }
        
        return row[k-1];
    }
};