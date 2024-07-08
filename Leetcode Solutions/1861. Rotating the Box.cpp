class Solution {
public:
    //TIME - O(N*M) SPACE - O(N*M)
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>>new_box(n, vector<char>(m, '.'));
        
        //First marking all the walls in new_box
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(box[i][j] == '*')
                    new_box[j][m-1-i] = '*';
            }
        }
        
        //rotating box
        for(int i=0;i<m;i++){
            int k = n-1;
            for(int j=n-1;j>=0;j--){
                if(box[m-1-i][j] == '#') new_box[k--][i] = '#';
                else if(box[m-1-i][j] == '*') k = j-1;
            }
        }
        
        return new_box;
    }
};