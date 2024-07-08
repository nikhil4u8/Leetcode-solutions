class Solution {
public:
    //BRUTE FORCE
    //TIME - O(N^2) SPACE - O(1)
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        
        for(int i=0;i<heights.size();i++) {
             int j=i+1,k=i-1;
  
             while(j<heights.size() && heights[j]>=heights[i]) j++;
             while(k>=0 && heights[k]>=heights[i]) k--;
             
             maxi = max(maxi,heights[i]*(j-k-1));
        }
        
        return maxi;
    }
    //overall time - (N)
    //TIME - O(N) SPACE - O(N)
    vector<int>NSR(vector<int>height){
        int n = height.size();
        vector<int>ans(n);
        stack<pair<int,int>>sta;
        
        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && height[i]<=sta.top().first) sta.pop();
            
            if(sta.empty()) ans[i] = n;
            else ans[i] = sta.top().second;
            
            sta.push({height[i],i});
        }
        
        return ans;
    }
    //TIME - O(N) SPACE - O(N)
    vector<int>NSL(vector<int>height){
        int n = height.size();
        vector<int>ans(n);
        
        stack<pair<int,int>>sta;
        
        for(int i=0;i<n;i++){
            while(!sta.empty() && height[i]<=sta.top().first) sta.pop();
            
            if(sta.empty()) ans[i] = -1;
            else ans[i] = sta.top().second;
            
            sta.push({height[i],i});
        }
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nsl(n,0),nsr(n,0);
        
        nsl = NSL(heights); //TIME - O(N)
        nsr = NSR(heights); //TIME - O(N)
        int ans = INT_MIN;
        
        //TIME - O(N) 
        for(int i=0;i<n;i++){
            ans = max(ans, heights[i] * abs(nsr[i]-nsl[i]-1));
        }
        
        return ans;
    }
};

//BEST QUALITY 
// TIME - O(N SPACE - O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n, 0);
        vector<int>right(n, 0);
        stack<pair<int, int>>sta;

        for(int i=0;i<n;i++){
            while(!sta.empty() && heights[i]<=sta.top().first) sta.pop();
            if(sta.empty()) left[i] = i+1;
            else left[i] = i - sta.top().second;
            sta.push({heights[i], i});
        }

        sta = {};

        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && heights[i]<=sta.top().first) sta.pop();
            if(sta.empty()) right[i] = n - i;
            else right[i] = sta.top().second - i;
            sta.push({heights[i], i});
        }

        int res = 0;
        for(int i=0;i<n;i++) res = max(res, heights[i]*(left[i]+right[i]-1));
        
        return res;
    }
};