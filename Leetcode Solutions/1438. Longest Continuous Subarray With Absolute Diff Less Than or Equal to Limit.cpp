class Solution {
public:
    //TIME - O(NlogN) SPACE - O(N)
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>>maxi;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>mini;
        
        int max_len = 1, start = 0, end = -1;
        
        for(int i=0;i<nums.size();i++){
            end++;
            maxi.push({nums[i], i});
            mini.push({nums[i], i});
            
            while(!maxi.empty() && !(maxi.top().second >= start && maxi.top().second <= end)) maxi.pop();
            while(!mini.empty() && !(mini.top().second >= start && mini.top().second <= end)) mini.pop();
            
            int _min = mini.top().first;
            int _max = maxi.top().first;
            
            while(_max - _min > limit){
                start++;
                while(!maxi.empty() && !(maxi.top().second >= start && maxi.top().second <= end)) maxi.pop();
                while(!mini.empty() && !(mini.top().second >= start && mini.top().second <= end)) mini.pop();
                
                _max = maxi.top().first;
                _min = mini.top().first;
            }
            
            max_len = max(max_len, end - start + 1);
        }
        
        return max_len;
    }
    
    //TIME - O(N) SPACE - O(N)
    /*
    Approach - By using max Deque. We maintain list of max element candidates in monotonically decreasing order. Everytime the right pointer reaches a new position, we need to dequeue the "tail" element who is smaller than the nums[right]. Since, those "old small tail" elements will never be the range maximum from now on. After "clean up" the "old small tail" elements, add nums[right] into the deque, and then, the head of deque is the current maximum.
    */
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<pair<int, int>>maxi, mini;
        int start = 0, end = -1, max_len = 0;
        
        for(int i=0;i<n;i++){
            while(!maxi.empty() && maxi.front().first < nums[i]) maxi.pop_front();
            while(!mini.empty() && mini.front().first > nums[i]) mini.pop_front();
            
            maxi.push_front({nums[i], i});
            mini.push_front({nums[i], i});
            
            end++;
            
            while(!maxi.empty() && !(maxi.back().second >= start && maxi.back().second <= end)) maxi.pop_back();
            while(!mini.empty() && !(mini.back().second >= start && mini.back().second <= end)) mini.pop_back();

            while(!maxi.empty() && !mini.empty() && maxi.back().first - mini.back().first > limit){
                start++;
                while(!maxi.empty() && !(maxi.back().second >= start && maxi.back().second <= end))
                    maxi.pop_back();
                while(!mini.empty() && !(mini.back().second >= start && mini.back().second <= end))
                    mini.pop_back();
            }
            
            max_len = max(max_len, end - start + 1);
        }
        
        return max_len;
    }
};