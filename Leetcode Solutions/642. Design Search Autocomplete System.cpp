class AutocompleteSystem {
public:
    struct compare {
        bool operator()(pair<int, string>& l, pair<int, string>& r) {
            if(l.first == r.first) return l.second < r.second;
            return l.first > r.first; 
        }
    };
    struct Trie{
        unordered_map<char,Trie*>child;
        unordered_map<string,int>order;
    };
    Trie* root;
    string cache = "";
    void insert(string str, int times){
        Trie* temp = root;
        
        for(int i=0;i<str.length();i++){
            char x = str[i];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            
            temp->order[str] += times;            
            temp = temp->child[x];
        }
        temp->order[str] += times;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        
        for(int i=0;i<times.size();i++)
            insert(sentences[i],times[i]);
    }
    
    vector<string> top_words(){
        Trie* temp = root;
        for(int i=0;i<cache.length();i++){
            char x = cache[i];
            
            if(temp->child.find(x) == temp->child.end()) 
                return {};
            temp = temp->child[x];
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare>pq;
        
        for(auto it : temp->order){
            pq.push({it.second,it.first});
            if(pq.size() > 3)
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
    vector<string> input(char c) {
        if(c == '#'){
            insert(cache,1);
            cache = "";
            return {};
        }
        cache += c;
        return top_words();
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */