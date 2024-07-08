class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>>s;
        vector<int>v(n);
        
        for(int i=temp.size()-1;i>=0;i--){
            while(!s.empty() && temp[i]>=s.top().first) s.pop();
            
            if(s.empty()) v[i] = 0;
            else v[i] = abs(i-s.top().second);
            
            s.push({temp[i],i});
        }
        
        return v;
    }
};