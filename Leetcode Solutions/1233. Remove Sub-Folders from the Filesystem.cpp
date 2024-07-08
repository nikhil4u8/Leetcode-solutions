struct Trie{
    unordered_map<string, Trie*>child;
    bool isend = false;
};
class Solution {
public:
    Trie* root;
    set<string>valid_folder;
    void insert(string word){
        Trie* temp = root;
        
        for(int i=1;i<word.length();i++){
            string x = "";
            while(i<word.length() && word[i] != '/') x += word[i++];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            
            temp = temp->child[x];
            if(temp->isend) return;
        }
        temp->isend = true;
        valid_folder.insert(word);
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        root = new Trie();
        sort(folder.begin(), folder.end());
        
        for(int i=0;i<folder.size();i++)
            insert(folder[i]);
        
        vector<string>ans(valid_folder.begin(), valid_folder.end());
        //for(auto it : valid_folder) ans.push_back(*it);
        
        return ans;
    }
};