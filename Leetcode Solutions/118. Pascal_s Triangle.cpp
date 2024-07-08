class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1},{1,1}};
        
        vector<vector<int>>ans = generate(numRows-1);
        
        vector<int>temp;
        for(int i=0;i<numRows;i++){
            if(i == 0 || i == numRows-1) temp.push_back(1);
            else{
                int res = ans[numRows-2][i] + ans[numRows-2][i-1];
                temp.push_back(res);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};