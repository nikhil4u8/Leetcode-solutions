class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    int minCost(string s, vector<int>& cost) {
        stack<pair<char, int>> st;
        int n = s.length();
        int price = 0;
        
        for(int i=0;i<n;i++) {
            if(st.empty() || st.top().first!=s[i]) st.push({s[i], cost[i]});
            else{
                price += min(st.top().second, cost[i]);
                if(st.top().second<cost[i]) {
                    st.pop();
                    st.push({s[i], cost[i]});
                }
            }
        }

        return price;
    }
    //TIME - O(N) SPACE - O(1)
    int minCost(string s, vector<int>& cost) {
        int min_cost = 0,last=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                min_cost += min(cost[i],cost[last]);
                if(cost[i]>cost[last]) last = i;
            }else last = i;
        }
        
        return min_cost;
    }
};