/*
TIME - 

Ques to ask? :-
    - Can K > total player?
    - what to do in case of duplicate score, include / not include in topK.

Sol :-
    - We can store score in a vector, in Top() method, we can simply sort 
    the array & find sum of topK. [Time - O(1) O(NlogN) O(1) | Space - O(N)]
    - Finding topK using a min Heap. [Time - O(1) O(NlogK) O(1) | Space - O(N)]
    - Use Set/Map instead of min Heap [Time - O(logN) O(k) O(logN)|Space - O(N)]

Follow up :-
    - add support for GetRankByID()? -> same as top() func
*/

//Approach 3 :- Using set / map
class Leaderboard {
public:
    unordered_map<int, int>mp;
    set<pair<int, int>>st;
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        st.erase({mp[playerId], playerId});
        mp[playerId] += score;
        st.insert({mp[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0, c = 0;
        for(auto it=st.rbegin();it!=st.rend() && c<K;it++, c++)
            sum += it->first;
        return sum;
    }
    
    void reset(int playerId) {
        st.erase({mp[playerId], playerId});
        mp[playerId] = 0;
    }
};

//Approach - 2
class Leaderboard {
public:
    unordered_map<int, int>mp;
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        mp[playerId] += score;
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int sum = 0;

        for(auto it : mp){
            sum += it.second;
            pq.push(it.second);
            if(pq.size() > K){
                sum -= pq.top();
                pq.pop();
            }
        }

        return sum;
    }
    
    void reset(int playerId) {
        mp[playerId] = 0;
    }
};