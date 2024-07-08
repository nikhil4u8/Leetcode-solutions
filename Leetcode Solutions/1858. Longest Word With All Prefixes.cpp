struct Trie{
    unordered_map<char, Trie*>child;
    bool isend = false;
};
class Solution {
public:
    int max_len = 0;
    Trie* root;
    bool insert(string str){
        Trie* temp = root;
        int count_isend = 0, len = str.length();
        
        for(int i=0;i<len;i++){
            char x = str[i];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            temp = temp->child[x];
            if(temp->isend) count_isend++;
        }
        temp->isend = true;
        count_isend++;
        
        return count_isend == len;
    }
    string longestWord(vector<string>& words) {
        root = new Trie();
        
        sort(words.begin(),words.end());
        
        string max_str = "";
        for(int i=0;i<words.size();i++){
            if(insert(words[i])){
                if(max_str.length() < words[i].length()) max_str = words[i];
                else if(max_str.length() == words[i].length())
                    max_str = min(max_str,words[i]);
            }
        }
        
        return max_str;
    }
};