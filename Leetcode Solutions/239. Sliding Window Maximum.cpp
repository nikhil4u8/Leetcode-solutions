#define ppi pair<int,int>
class Solution {
public:
    //TIME - O(NlogK) SPACE - O(K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<ppi>pq;
        vector<int>ans;
        
        for(int i=0;i<min(k,n);i++)  pq.push({nums[i],i});
        ans.push_back(pq.top().first);
        
        for(int i=k;i<n;i++){
            while(!pq.empty() && pq.top().second<=i-k) pq.pop();
            
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
    //TIME - O(N) SPACE - O(N)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(k == 0) return result;
        int n = nums.size();
        
        deque<int> w;
        
        for(int i = 0;i<n;i++) {
            while (!w.empty() && w.front() <= i-k) w.pop_front();
            
            while (!w.empty() && nums[w.back()] <= nums[i]) w.pop_back();
        
            w.push_back(i);
            
            if(i >= k-1) result.push_back(nums[w.front()]);
        }
        
      return result;
    }
};
