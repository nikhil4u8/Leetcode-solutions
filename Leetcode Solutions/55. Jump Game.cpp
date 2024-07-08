1.Is it possible to reach the end of array, a jump can be of arr[i]

2.Find min jumps to reach the end, a jump can be of arr[i]

3.You are at ith index and can move to i+arr[i]/i-arr[i] index, check if 
you can reach to index with value 0

4.In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.
    Return the minimum number of steps to reach the last index of the 
    array.

5.You can jump at most k steps, you want to reach last index, find the maximum score you
can get, score is the sum of nums[i] for each index i you visited in array

1.
class Solution {
public:
//Func to find if we can reach the end or not
    public boolean canJump(int[] nums) {
        int i=0, n = nums.length;
        
        while(i < n){
            if(nums[i] ==0 && i==n-1) return true;            
            if(nums[i] < n){
                i = i+ nums[i];
            }
            if(i==n-1) return true;
        }
        return false;
    }
//Fun to find how many steps it took to reach end
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int steps = nums[0],max_jump=0;
        
        for(int i=1;i<n;i++){
            steps--;
            max_jump = max(max_jump,i+nums[i]);
            
            if(steps<=0){
                if(steps < 0) return false;

                steps = max_jump - i;
                if(steps<=0 && i!=n-1) return false;
            }
        }
        
        return true;
    }
};

2.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int steps = nums[0],max_jump=0,jump_count=0;
        if(steps>=n-1) return 1;
        
        for(int i=1;i<n;i++){
            steps--;
            max_jump = max(max_jump,i+nums[i]);
            
            if(steps==0){
                steps = max_jump - i;
                jump_count++;
                max_jump = 0;
            }
        }
        
        if(max_jump!=0) jump_count++;
        
        return jump_count;
    }
};

3.
//TIME - O(N) -> since we need to visit every index once
//SPACE - O(N)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<pair<int,int>>q;
        q.push({arr[start],start});
        vector<bool>visited(n,false);
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp.first == 0) return true;
            
            int next_jump = temp.second + temp.first;
            
            if(next_jump>=0 && next_jump<n && !visited[next_jump]){
                if(arr[next_jump] == 0) return true;
                visited[next_jump] = true;
                q.push({arr[next_jump],next_jump});
            }
            
            next_jump = temp.second - temp.first;
            if(next_jump>=0 && next_jump<n && !visited[next_jump]){
                if(arr[next_jump] == 0) return true;
                visited[next_jump] = true;
                q.push({arr[next_jump],next_jump});
            }
        }
        
        return false;
    }
};

4.
class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    int minJumps(vector<int>& arr) {
        int n = arr.size(),curr_jump = 0;
        if(n<=1) return 0;
        
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<arr.size();i++)  mp[arr[i]].push_back(i);
        
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0] = true;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
        
            if(temp.second == n-1) return temp.first;
            
            for(int i=0;i<mp[arr[temp.second]].size();i++){
                int index = mp[arr[temp.second]][i];
                
                if(index == n-1) return temp.first+1;
                
                if(!visited[index]){
                    visited[index] = true;
                    q.push({temp.first+1,index});
                }
            }
            
            if(temp.second+1 == n-1 || temp.second - 1 == n-1) return temp.first + 1;
            
            if(temp.second+1<n && !visited[temp.second + 1]){
                visited[temp.second + 1] = true;
                q.push({temp.first+1,temp.second+1});
            }
            if(temp.second-1>=0 && !visited[temp.second - 1]){
                visited[temp.second - 1] = true;
                q.push({temp.first+1,temp.second-1});
            }
        }
       
        return -1;
    }
};

5.
class Solution {
public:
    //TIME - O(NlogN)  SPACE - O(N)
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);
        priority_queue<pair<int,int>>pq;
        
        dp[0] = nums[0];
        pq.push({nums[0],0});
        
        for(int i=1;i<n;i++){
            int maxi = INT_MIN;
            
            while(pq.top().second < i-k) pq.pop();
            
            dp[i] = nums[i] + pq.top().first;
            pq.push({dp[i],i});
        }
        
        return dp[n-1];
    }
};