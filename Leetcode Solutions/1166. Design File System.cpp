struct Trie{
    unordered_map<string,Trie*>child;
    int val = 0;
    bool isend = false;
};
class FileSystem {
public:
    Trie* root;
    FileSystem() {
        root = new Trie();
    }
    
    bool createPath(string path, int value) {
        Trie* temp = root;
        int index = 1;
        string dir = "";
        
        while(index < path.length()){
            if(path[index] == '/'){
                
                if(temp->child.find(dir) == temp->child.end()) 
                    return false;
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
        
        if(temp->isend) return false;
        
        temp->isend = true;
        temp->val = value;
        
        return true;
    }
    
    int get(string path) {
        Trie* temp = root;
        int index = 1;
        string dir = "";
        
        while(index < path.length()){
            if(path[index] == '/'){
                
                if(temp->child.find(dir) == temp->child.end()) 
                    return -1;
                temp = temp->child[dir];
                
                dir = "";
            }else dir += path[index];
            
            index++;
        }
        
        if(dir != ""){
            if(temp->child.find(dir) == temp->child.end())
                return -1;
            temp = temp->child[dir];
        }
        
        if(!temp->isend) return -1;
        return temp->val;
    }
};