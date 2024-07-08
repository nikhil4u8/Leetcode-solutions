class Trie {
public:
//Time - O(N)
    struct trie{
        unordered_map<char,trie*>child;
        bool isend;
    };
    trie* root;
    Trie() {
        root = new trie();
    }
    //Time - O(N)
    void insert(string word) {
        trie* temp = root;
        
        for(int i=0;i<word.length();i++){
            char x = word[i];
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new trie();
            temp = temp->child[x];
        }
        
        temp->isend = true;
    }
    //Time - O(N)
    bool search(string word, bool startwith = false) {
        trie* temp = root;
        for(int i=0;i<word.length();i++){
            char x = word[i];
            if(temp->children.find(x) == temp->children.end())
                return false;
            temp = temp->children[x];
        }

        if(startwith) return true;
        return temp->isend;
    }
    // TIME - O(N)
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

Follow Up questions that your interview could ask:

How would you modify the code to implement an endsWith(String suffix) method ?
    => "Design Add and Search Words Data Structure"

How would you modify the code to implement a delete(String word) method ?
    => Just make the end as false or if want to delete whole word then while traversing the word keep 
    track of which parent char has more than one children and at the end remove the link from parent char
    which is leading towards the word

How would you modify the code to return the longest length of the string in the Trie in O(1) Time ?
