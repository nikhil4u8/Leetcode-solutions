class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int>& candidates, vector<int>temp, int sum, int target, int index){
        if(sum == target) ans.insert(temp);
        
        for(int i=index;i<candidates.size();i++){
            if(sum + candidates[i] > target) continue; 
            
            temp.push_back(candidates[i]);
            solve(candidates,temp,sum+candidates[i],target,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, {}, 0, target, 0);
        return vector(ans.begin(), ans.end());
    }
};