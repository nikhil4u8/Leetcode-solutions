/*
Ques to ask :
    - What do when freq is equal?
    - Does string contains lower / upper both alphabets?

Sol :
=> Naive approach
    - Store freq of char in array [vector<pair<int, char>>].
    - if a new char is added then check if it already exist in freq 
    array, find it's idx and update it's freq, otherwise add a new 
    element in freq array
    - sort the array, and add each element one by one in ans string
    
=> Best Solution
    - Store the freq of character in s inside a map
    - then using priority queue we can sort the mapping in map
    - then take char out of pq one by one and append it to ans string

Follow up :
    - For same freq maintain same sequence of char as it's in original str
        => Along with freq, add a idx as a secondary sort if the freq 
        is same
    - For same freq, arrange according to lexicographical order 
    (smallest first)
        => Instead of Max heap use min heap, and reverse ans str in end
*/
class Solution {
public:
//TIME - O(N) SPACE - O(52) -> since we've only 52 char
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int>mp;
        priority_queue<pair<int, char>>pq;

        for(int i=0;i<s.length();i++) mp[s[i]]++;
        for(auto it : mp) pq.push({it.second, it.first});

        while(!pq.empty()){
            int freq = pq.top().first;
            char x = pq.top().second;

            while(freq--) ans += x;

            pq.pop();
        }

        return ans;
    }
};