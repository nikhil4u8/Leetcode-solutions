**CODE
There are some algoritms to keep minimum (or maximum) value in sliding window with amortized complexity 
O(1) per element (O(N) for all data set). This is one of them using Deque data structure, which contains 
value/index pairs. For both Min and Max you have to keep two deques.

//TIME - O(N) SPACE - O(K)
vector maxSlidingWindow(vector& nums, int y, int x) {
vector threshold_reached;
if(y == 0) return result;
int n = nums.size();

    deque<int>max_q;
    deque<int>min_q;
    
    for(int i = 0;i<n;i++) {
        while (!max_q.empty() && max_q.front() <= i-y) max-q.pop_front();
        while (!min_q.empty() && min_q.front() <= i-y) min_q.pop_front();
        
        while (!max_q.empty() && nums[max_q.back()] <= nums[i]) max_q.pop_back();
        while (!min_q.empty() && nums[min_q.back()] >= nums[i]) min_q.pop_back();
        
        max_q.push_back(i);
        min_q.push_back(i);
        
        if(i >= y-1){
            int curr_max = nums[max_q.front()];
            int curr_min = nums[min_q.front()];
            bool ans = curr_max - curr_min > x;
            
            threshold_reached.push_back(ans);
        }
    }
    
  return threshold_reached;
}