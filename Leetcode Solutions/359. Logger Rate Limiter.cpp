class Logger {
public:
//Time - O(1)
//Space - O(N)
    unordered_map<string,int>mp;
    Logger() {
        mp = unordered_map<string,int>();
    }
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) != mp.end() && mp[message] > timestamp) 
            return false;

        mp[message] = timestamp + 10;
        return true;
    }
};