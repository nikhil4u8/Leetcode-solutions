class Solution {
public:
    //TIME - O(N!) SPACE - O(N!)
    //Initially we have N choices, and in each choice we have (N - 1) choices, 
    //and so on
    //The space complexity should also be N! since we have N! solutions and each 
    //of them requires 1 space to store elements.
    set<vector<int>>ans;
    void getPermute(vector<int>temp, int idx){
        ans.insert(temp);
        
        for(int i=idx;i<temp.size();i++){
            swap(temp[idx], temp[i]);
            getPermute(temp, idx+1);
            swap(temp[idx], temp[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        getPermute(nums, 0);
        return vector(ans.begin(), ans.end());
    }
};