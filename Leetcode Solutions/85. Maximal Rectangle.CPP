***UNDERSTAND IT AGAIN
class Solution {
public:
    //BRUTE FORCE
    //TIME - O(N^3)
//for a start/end point, we do not need to consider all end/start points, we only 
//need to consider points that connect to the start/end point by all 1s. We use a
//2d array to cache number of consecutive 1s to the left of each point. Then for 
//a point, we can determine its maximal rectangles in linear time.
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (!r) return 0;
        int c = matrix[0].size(), area = 0;
        vector<vector<int>> ones(r,vector<int>(c));
        for(int i=0;i<r;i++) 
            for(int j=0;j<c;j++) {
                if(matrix[i][j]=='0') continue;
                int w = ones[i][j] = (j?ones[i][j-1]:0) + 1;
                for(int k=i; k>=0; k--) {
                    w = min(ones[k][j],w);
                    area = max(area,w*(i-k+1));
                }
            }
        return area;
    }
    //DP METHOD
    //TIME - O(N^2)
//The optimal solution does not check a rectangle by start/end point. Given a point 
//(i, j), it computes the left boundary, right boundary of the maximal rectangle 
//with height(i,j) incrementally in constant time. 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (!r) return 0;
        int c = matrix[0].size(), area = 0;
        vector<int> left(c), right(c,c), height(c);
        for(int i=0;i<r;i++) { 
            int cur = 0;
            for(int j=0;j<c;j++)
                if(matrix[i][j]=='0') {
                    height[j] = left[j] = 0;
                    cur = j+1; //left boundary of current row
                } else {
                    left[j] = max(left[j],cur);  //left boundary for height[j]
                    height[j]++;
                }
            cur = c;
            for(int j=c-1;j>=0;j--) {
                if (matrix[i][j]=='0') cur = j;
                right[j] = matrix[i][j]=='0'? c:min(right[j],cur);
                area = max(height[j]*(right[j]-left[j]),area);
            }
        }
        return area;
    }
    //TIME - O(N*M) SPACE - O(M)
    vector<int>NSL(vector<int>&height,int n){
        stack<pair<int,int>>sta;
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            while(!sta.empty() && height[i]<=sta.top().first) sta.pop();
            
            if(sta.empty()) ans[i] = 0;
            else ans[i] = sta.top().second+1;
            
            sta.push({height[i],i});
        }
        
        return ans;
    }
    vector<int>NSR(vector<int>&height,int n){
        stack<pair<int,int>>sta;
        vector<int>ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && height[i]<=sta.top().first) sta.pop();
            
            if(sta.empty()) ans[i] = n+1;
            else ans[i] = sta.top().second+1;
            
            sta.push({height[i],i});
        }
        
        return ans;
    }
    int MAH(vector<int>&height,int n){
        vector<int>nsr(n);
        vector<int>nsl(n);
        
        nsr = NSR(height,n);
        nsl = NSL(height,n);
        
        int ans = 0;
        for(int i=0;i<height.size();i++){
            ans = max(ans,height[i]*(nsr[i]-nsl[i]-1));
        }
        
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        vector<int>height(m,0);
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }    
            
            ans = max(ans,MAH(height,m));
        }
        
        return ans;
    }
};