class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        stack<int>s;
        
        for(int i=nums.size()-1;i>=0;i--) s.push(nums[i]);
        
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[i]>=s.top()) s.pop();
            if(s.empty()) v[i] = -1;
            else v[i] = s.top();
            s.push(nums[i]);
        }
        
        return v;
    }
};