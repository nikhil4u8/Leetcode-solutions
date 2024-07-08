struct compare{
    bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
//TIME - O(NlogK) SPACE - O(N)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //SPACE - O(N) TIME - O(N)
        unordered_map<string,int>freq;
        for(int i=0;i<words.size();i++) freq[words[i]]++;
        
        //SPACE - O(K), TIME - O(Nlogk)
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        
        for(auto it : freq){
            pq.push({it.second,it.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};