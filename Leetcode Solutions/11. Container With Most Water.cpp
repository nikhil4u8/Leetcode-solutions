class Solution {
public:
    //time - O(nlogn) space - O(N)
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) v.push_back({height[i],i});
        
        sort(v.begin(),v.end());
        int maxi = v[n-1].second,mini=v[n-1].second,ans = 0;
        
        for(int i=n-2;i>=0;i--){
            ans = max(ans,v[i].first*(max(abs(v[i].second-maxi),abs(v[i].second-mini))));
            maxi = max(maxi,v[i].second);
            mini = min(mini,v[i].second);
        }
        
        return ans;
    }
    //time - O(n) space - O(1)
    // max(abs(i-j)*min(height[i], height[j]));
    //first maximizing abs(i-j), then trying to maximize second part
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;

        while(i<height.size() && j>=0){
            cout<<i<<" "<<j<<"\n";
            ans = max(ans, abs(i-j)*min(height[i], height[j]));
            if(height[i] > height[j]) j--;
            else i++;
        }

        return ans;
    }
};