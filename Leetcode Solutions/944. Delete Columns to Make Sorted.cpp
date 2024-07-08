class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].length(), count = 0;

        for(int i=0;i<len;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] >= strs[j-1][i]) continue;
                else{
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};