//TIME - O(NlogN) SPACE - O(N)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 0) return 0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<sticks.size();i++) pq.push(sticks[i]);
        
        int cost = 0;
        
        while(pq.size()>1){
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            cost += t1+t2;
            
            pq.push(t1+t2);
        }
        
        return cost;
    }
};