class StockPrice {
public:
    unordered_map<int,int>mp;
    set<pair<int,int>>stock;
    int curr_price,max_timestamp;
    StockPrice() {
        curr_price = 0;
        max_timestamp = 0;
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()){
            auto it = stock.find({mp[timestamp], timestamp});
            stock.erase(it);
        }
        
        stock.insert({price, timestamp});
        mp[timestamp] = price;
        
        if(timestamp >= max_timestamp){
            max_timestamp = timestamp;
            curr_price = price;
        }
    }
    
    int current() {
        return curr_price;
    }
    
    int maximum() {
        auto it = stock.end();
        it--;
        return it->first;
    }
    
    int minimum() {
        return stock.begin()->first;
    }
};