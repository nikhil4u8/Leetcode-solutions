class Solution {
public:
    /*For BFS we need length of wordList we need O(n) time.
    For word we need O(m) time where m is the word length.
    For word comparison we again need extra O(m) time.
    And finally we are checking for every 26 character i.e., O(26)
    
    Time Complexity = O(n * m * m * 26)
    */
    //SPACE - O(number of words * number of characters per word
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        unordered_map<string,int>dict;
        
        for(int i=0;i<wordList.size();i++)
            dict[wordList[i]]++;
        
        while(!q.empty()){
            pair<string,int>p = q.front();
            q.pop();
            
            for(int i=0;i<p.first.length();i++){
                char x = p.first[i];
                
                for(int j=0;j<26;j++){
                    if(j==x-'a') continue;
            
                    string str = p.first;
                    str[i] = ('a'+j);
                    if(dict[str]>0){
                        if(str == endWord) return p.second+1;
                        
                        q.push({str,p.second+1});
                        dict[str]--;
                    }
                }
                
                p.first[i] = x;
            }
        }
        
        return 0;
    }
};