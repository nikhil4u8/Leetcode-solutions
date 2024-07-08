// /*
// TIME - O(N*M*M) 
// SPACE - O(N*M)
// N is len of word list
// M is max len of word
// */
// struct Trie{
//     unordered_map<char, Trie*>child;
//     bool isend = false;
// };
// class Solution {
// public:
//     Trie* root;
//     bool searchWord(string word, int index, int skip, Trie* temp){
//         if(skip > 1) return false;
//         if(index >= word.length()) return skip == 1 && temp->isend;
        
//         char ch = word[index];
//         for(auto child : temp->child){
//             char x = child.first;
//             if(x == ch){
//                 if(searchWord(word, index+1, skip, child.second))
//                     return true;
//             }else{
//                 if(searchWord(word, index+1, skip+1,child.second))
//                     return true;
//             }
//         }
        
//         return false;
//     }
//     void insert(string word){
//         Trie* temp = root;
        
//         for(int i=0;i<word.length();i++){
//             char x = word[i];
            
//             if(temp->child.find(x) == temp->child.end())
//                 temp->child[x] = new Trie();
//             temp = temp->child[x];
//         }
//         temp->isend = true;
//     }
//     bool differByOne(vector<string>& dict) {
//         root = new Trie();
        
//         for(int i=0;i<dict.size();i++){
//             bool ispresent = searchWord(dict[i], 0, 0, root);
//             if(ispresent) return true;
            
//             insert(dict[i]);
//         }
        
//         return false;
//     }
// };
// /*
// Remove each char from each string and insert it into map, and check if any other similar string is available or not
// You generate m variations of each strings, and it takes O(m) to insert it into the hash map.

// TIME/SPACE - O(n * m * m) 
// The point of the rolling hash (Rabin-Karp) is precisely to compute each hash in O(1).
// */
// class Solution {
// public:
//     bool differByOne(vector<string>&A) {
//         int m = A[0].size();
//         unordered_set<string>S;
//         for(string a : A)
//         {
//             string s = a;
//             for(int i = 0; i < m; i++)
//             {
//                 char ch = s[i];
//                 s[i] = '*';
//                 if(S.find(s) != S.end())
//                     return true;
//                 S.insert(s);
//                 s[i] = ch;
//             }
//         }
//         return false;
        
        
//     }
// };
/*
Generating Hash of each word, and removing each char from each string and checking if the hash is present or not
*/
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int size = dict.size();
        long mod = 1e9 + 7;
        vector<long> hash(size);
        for(int i = 0; i < size; i++) {
            for (int j = 0; j < dict[0].size(); j++) {
                hash[i] = (hash[i] * 26 + (dict[i][j] - 'a')) % mod;
            }
        }
        
        long base = 1;
        for(int i = dict[0].size() - 1; i >= 0; i--) {
            unordered_map<long, int> set;
            for(int j = 0; j < size; j++) {
                int temp = (hash[j] - base * (dict[j][i] - 'a') % mod + mod) % mod;
                if(set.find(temp) != set.end() && dict[j].substr(0, i) == dict[set[temp]].substr(0, i) && dict[j].substr(i+1) == dict[set[temp]].substr(i+1) && dict[j][i] != dict[set[temp]][i]) {
                    return true;
                }
                set[temp] = j;
            }
            base = (base * 26) % mod;
        }
        return false;
    }
};