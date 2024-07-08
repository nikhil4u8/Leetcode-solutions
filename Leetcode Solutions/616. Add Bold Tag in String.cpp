/*
Ques to ask:
    - Can we use a word from words array multiple times?
    - What to do when 2 substring overlaps? Ex:"aba", words:["ab","ba"]
    - What happens when 2 substr wrapped by bold tags are consecutive?
        -> Ex:"aba", words:["ab","a"]
    - What if when many combination of bold tag string is possible, then 
    what to return? Do we've a choice to not add bold tag when a 
    substr == word[i] if found?
Ex : "abc", words : ["a","c","abc"] => string = <b>abc</b> or 
<b>a</b>b<b>c</b>?

Sol :
=> Brute Force : [TIME - O(N*L*M) SPACE - O(N)]
    - There can be overlapping string or adjacent string which are bold 
    so they needed to be merged together, so if we can figure out which 
    all char needs to be bold then we can easily add open / close tag.
    - To find if a char is bold or not, we'll iterate over each str 
    (words[i]) in words array & then iterate over each substr in s with 
    the same len of words[i], if substr matched words[i] then mark all 
    char of substr as true in bold array.

BEST APPROACH
=> Optmized Brute Force : [TIME - O(M*N*L*(N-K)) SPACE - O(N)]
-> N : len of s
-> L : avg len of str in words array
-> M : len of words array
    - Instead of traversing through all char in s, we'll use a inbuilt 
    fun of s.find(str, idx) which returns the index of first occurance of 
    str in s. 
    - For every word[i] in words array, we'll find first occurance of it 
    in s, if it comes out to be -1, then move to next word[i], else mark 
    all the idx from [startIdx, startIdx+word[i].len] as bold & then set 
    startIdx = s.find(word[i], startIdx + 1) & do this until startIdx 
    becomes -1 i.e no more substr exist in s which is equal word[i]
    - In end traverse bold array & if 
        - bold[i] = true & bold[i-1] = false : add a open bold tag
        - bold[i] = true & bold[i+1] = false : add a close bold tag
    Also, add ith char in ans too.

=> Trie 
    - For searching start index trie (made of words array) can also be 
    used, otherwise approach is same
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(M*N*L*(N-K)) SPACE - O(N)
    string addBoldTag(string s, vector<string>& words) {
        int n = s.length();
        vector<bool>isBold(n, false);

        //Marking all char as bold or not bold
        for(int i=0;i<words.size();i++){ //O(M*N*L*(N-L))
            string curr = words[i];
            int start = s.find(curr);

            //finding if curr str exist in s or not & start is starting 
            //index of first occurance of curr
            //O(N*(L + (N-L)*L))=O(N*L + N*L*(N-L)) = O(N*L*(N-L-1))
            while(start != -1){
                for(int j=0;j<curr.length();j++) //O(L)
                    isBold[start + j] = true;
                start = s.find(curr, start + 1); //O((N-L)*L)
            }
        }

        string ans = "", openTag = "<b>", closeTag = "</b>";

        //Traversing bold array & adding open / close tag
        for(int i=0;i<n;i++){cout<<isBold[i]<<" ";
            if(isBold[i] && (i == 0 || !isBold[i-1])) ans += openTag;
            
            ans += s[i];

            if(isBold[i] && (i == n-1 || !isBold[i+1])) ans += closeTag;
        }

        return ans;
    }
};
//USING TRIE
struct Trie{
    unordered_map<char, Trie*>child;
    bool isend = false;
};
class Solution {
public:
    Trie* root;
    void insert(string word){
        Trie* temp = root;
        
        for(int i=0;i<word.length();i++){
            char x = word[i];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            
            temp = temp->child[x];
        }
        temp->isend = true;
    }
    string addBoldTag(string s, vector<string>& words) {
        root = new Trie();
        
        for(int i=0;i<words.size();i++) insert(words[i]);
        
        string res = "";
        int len = s.length();
        vector<bool>visited(len, false);
        
        for(int i=0;i<len;i++){
            Trie* temp = root;
            int j = i;
            for(;j<s.length();j++){
                char x = s[j];
                
                if(temp->child.find(x) == temp->child.end()) break;
                
                temp = temp->child[x];
            }
            if(temp->isend) fill(visited.begin()+i, visited.begin()+j, true);
        }
        
        for(int i=0;i<len;){
            if(!visited[i]) res += s[i++];
            else{
                res += "<b>";
                while(i<len && visited[i]){
                    res += s[i];
                    i++;
                }
                res += "</b>";
            }
        }
        
        return res;
    }
};