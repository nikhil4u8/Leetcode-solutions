class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++)
            pq.push({score[i], i});
        
        vector<string>ans(n, "");
        int t = 1;
        while(!pq.empty()){
            if(t == 1) ans[pq.top().second] = "Gold Medal";
            else if(t == 2) ans[pq.top().second] = "Silver Medal";
            else if(t == 3) ans[pq.top().second] = "Bronze Medal";
            else ans[pq.top().second] = to_string(t);
            pq.pop();
            t++;
        }
        
        return ans;
    }
};