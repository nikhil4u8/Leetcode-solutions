class Solution {
public:
    //TIME - O(N*M)
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        
        for(int i=1;i<strs.size();i++){
            int j=0;
            for(;j<str.length();j++){
                if(str[j]!=strs[i][j]) break;
            }
            str = str.substr(0,j);
        }
        
        return str;
    }
};

class Solution {
public:
    struct Trie{
        unordered_map<char, Trie*>children;
        int count = 0;
        bool isend = false;
    };
    Trie* root;
    int maxi;
    string longestPrefix = "";

    void insert(string str){
        Trie* temp = root;

        for(int i=0;i<str.length();i++){
            char x = str[i];

            if(temp->children.find(x) == temp->children.end())
                temp->children[x] = new Trie();

            temp = temp->children[x];
            temp->count += 1;

            if(maxi == temp->count){
                longestPrefix = str.substr(0, i+1);
            }
        }

        temp->isend = true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        root = new Trie();
        maxi = strs.size();

        for(int i=0;i<strs.size();i++)
            insert(strs[i]);
        
        return longestPrefix;
    }
};