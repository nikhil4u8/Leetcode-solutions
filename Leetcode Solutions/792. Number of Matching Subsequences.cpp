/*Approach 1 - if length of LCS == words[i].length() then it's a subsequence -> 
TIME - O(N*words.size*total_char_in_words_list) SPACE - O(N*max_len_of_word_in_words_list)
*/
/*Approach 2 - Compare each string with s, and check if it's a subsequence or not? -> 
TIME - O(N*word.size + total_char_in_words_list) SPACE - O(1)
*/
/*
Approach 3 - Generate all possible subseq of S and check if they're found in words list or not->O(2^n)
*/
/*
Approach 4 - Using binary search for searching next index
TIME - O(M*k*logS) SPACE - O(total_char_words_list)
M = words.size
K = max_len_of_word in words list
S = len of string S
- Create an vector that stores indices for each character a-z in S
- Then for each word, do a binary search for next index for current character in word 
  that is greater than the index we last found for the alst character
- If it doesn't exist, word doesn't exist, otherwise continue to search for word
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>>index;
        for(int i=0;i<s.length();i++)
            index[s[i]].push_back(i);
        
        int ans = 0;
        
        for(int i=0;i<words.size();i++){
            string str = words[i];
            int j = 0;
            int char_index = -1;
            bool found = true;
            
            while(j<str.length()){
                
                auto it = upper_bound(index[str[j]].begin(), index[str[j]].end(), char_index);
                if(it == index[str[j]].end()){
                    found = false;
                    break;
                }
                if(*it == char_index) *it++;
                if(it == index[str[j]].end()){
                    found = false;
                    break;
                }
                                  
                char_index = *it;
                j++;
            }
            if(found) ans++;
        }
        
        return ans;
    }
};
//Approach 4 - Using Trie
// struct Trie{
//     unordered_map<char, Trie*>child;
//     bool isend = false;
//     int freq = 0;
// };
// class Solution {
// public:
//     Trie* root;
//     int ans = 0;
//     void insert(string word){
//         Trie* temp = root;
        
//         for(int i=0;i<word.length();i++){
//             char x = word[i];
            
//             if(temp->child.find(x) == temp->child.end())
//                 temp->child[x] = new Trie();
//             temp = temp->child[x];
//         }
//         temp->isend = true;
//         temp->freq++;
//     }
    
//     int findIndex(string str, int start, char c){
//         for(int i=start;i<str.length();i++)
//             if(str[i] == c) return i;
//         return -1;
//     }
    
//     void search(string str, Trie* temp, int index){
//         for(auto child : temp->child){
//             int idx = findIndex(str, index, child.first);
//             if(idx != -1){
//                 if(child.second->isend)  ans += child.second->freq;
//                 search(str, child.second, index+1);
//             }
//         }
//     }
    
//     int numMatchingSubseq(string s, vector<string>& words) {
//         root = new Trie();
        
//         for(int i=0;i<words.size();i++) insert(words[i]);
        
//         search(s, root, 0);
//         return ans;
//     }
// };