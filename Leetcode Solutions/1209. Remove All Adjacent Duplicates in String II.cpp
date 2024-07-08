/*
Desc :-
    - Remove all k duplicate from string until we no longer have
    - Output will be unique
    - k>=2, s contains lowercase letters

Ques to ask / Edge cases? :- 
    - How to remove the k elements, like do we need to remove 
    all k first, then in second iternation next k elements?
    - Can K be 0/1? or can K > len of string
    - Is 'a' & 'A' considered same?
    - Is it a gurantee that there will be a unique output?
    - Can 's' be a empty string?

Sol :
=> Brute Force : [TIME - O(N^2) SPACE - O(1)]
    - Count repeating adjacent letters & if count reached k then remove 
    those char from str & then iterate again from starting. Do this until 
    there are k adjacent duplicates remaining.

BEST APPROACH
=> Using Stack : [TIME - O(N) SPACE - O(N)]
    - In the above approach, we re-iterating and recheck already visited 
    char multiple times. So to avoid this we use STACK,to remember what 
    the count of previous char n avoid re-iterating.
    - In stack we store char & it's adjacent count, if count of a char > k 
    then reduce it's count to count%k, and if in case the case got erased 
    completely, then check if the char prev to the removed one is same as 
    of next char or not, if it's same then freq of next char going to 
    merge with prev char. If it's not same, then continue traversing

Follow up :
    - Remove adjacent >=K elements
        -> When we find a different then check if freq of prev char >= k 
        or not, if it is then remove it completely, else continue 
        traversing. 
    - Remove all adjacent duplicates
        -> Ref : 1047. Remove All Adjacent Duplicates In String
    - Remove all adjacent duplicates >= k
        -> Ref : 1209. Remove All Adjacent Duplicates in String II
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>sta;
        
        for(int i=0;i<s.length();i++){
            if(!sta.empty() && sta.top().first==s[i]){
                sta.top().second++;
                if(sta.top().second == k) sta.pop();
            }else sta.push({s[i],1});
        }
        
        string str = "";
        while(!sta.empty()){
            auto temp = sta.top();
            sta.pop();
            while(temp.second--) str += temp.first;
        }
        
        reverse(str.begin(),str.end());
        
        return str;
    }
};

**FOLLOW-UP
    1.Remove adjacent >=K elements
string removeDuplicates(string s, int k) {
    stack<pair<char,int>> st;
    for (auto c : s) {
        if (!st.empty() && st.top().first != c && st.top().second >= k) 
            st.pop();
        if (!st.empty() && st.top().first == c) 
            st.top().second += 1;
        else 
            st.push(make_pair(c, 1));
    }
    
    if (st.top().second >= k) st.pop();
    
    string res;
    while(!sta.empty()){
        int cnt = sta.top().second;
        char c = sta.top().first;
        for (int i = 0; i < cnt; i++) {
            res += c;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}