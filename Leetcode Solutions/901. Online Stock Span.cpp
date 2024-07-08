class StockSpanner {
public:
    stack<pair<int,int>>sta;
    int count;
    StockSpanner() {
        sta = stack<pair<int,int>>();
        count = 0;
    }
    int next(int price) {
        count++;
        while(!sta.empty() && sta.top().first<=price) sta.pop();
        
        int res = count;
        if(!sta.empty()) res = count - sta.top().second;
        sta.push({price,count});
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */