class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), minimum = INT_MAX, ans = INT_MAX;
        priority_queue<int>pq;

        for(int i = 0;i<n;i++){
            if(nums[i] % 2 != 0) nums[i] *= 2;
            minimum = min(minimum, nums[i]);
            pq.push(nums[i]);
        }

        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();

            ans = min(ans, curr - minimum);

            if(curr % 2 == 0){
                curr /= 2;
                minimum = min(minimum, curr);
                pq.push(curr);
            }else return ans;
        }

        return ans;
    }
};