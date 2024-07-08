struct Trie{
    unordered_map<string,Trie*>child;
    string content = "";
    bool isfile = false;
};
class FileSystem {
public:
    Trie* root;
    FileSystem() {
        root = new Trie();
    }
    vector<string> solve(string path, bool add_path = false,string content = "",
                 bool read_file = false,bool ls = false){
        
        Trie* temp = root;
        int index = 1;
        string dir = "";
        
        while(index < path.length()){
            if(path[index] == '/'){
                if(temp->child.find(dir) == temp->child.end())
                    temp->child[dir] = new Trie();
                temp = temp->child[dir];
                dir = "";
            }else dir += path[index];
            index++;
        }
        
        if(dir != ""){
            if(temp->child.find(dir) == temp->child.end())
                temp->child[dir] = new Trie();
            temp = temp->child[dir];
        }
        if(content != ""){
            temp->content += content;
            temp->isfile = true;
        }
        
        if(read_file) return {temp->content};
        
        if(ls){
            if(temp->isfile) return {dir};
            
            vector<string>ans;
            for(auto it : temp->child){
                ans.push_back(it.first);
            }
            return ans;
        }
        
        return {};
    }
    vector<string> ls(string path) {
        vector<string>ans = solve(path,false,"",false,true);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
    
    void mkdir(string path) {
        solve(path,true,"",false);
    }
    
    void addContentToFile(string filePath, string content) {
        solve(filePath,false,content,false);
    }
    
    string readContentFromFile(string filePath) {
        return solve(filePath,false,"",true)[0];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */