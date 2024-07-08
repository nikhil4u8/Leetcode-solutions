class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0) return s;
        
        int len = s.length();
        unordered_map<char, int>freq;
        for(int i=0;i<len;i++) freq[s[i]]++;
        
        priority_queue<pair<int,char>>pq;
        
        for(auto it : freq) pq.push({it.second, it.first});
        int j = 0;
        string res(len, '#');
        
        while(!pq.empty()){
            vector<char>cache;
            for(int i=0;i<k && j<len;i++){
                if(pq.empty()) return "";
                auto temp = pq.top();
                pq.pop();
                res[j] = temp.second;
                j++;
                if(--freq[temp.second] > 0) cache.push_back(temp.second);
            }
            for(int i=0;i<cache.size();i++) pq.push({freq[cache[i]], cache[i]});
        }
        
        return res;
    }
};