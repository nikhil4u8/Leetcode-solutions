class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        
        queue<pair<string,int>>q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                q.pop();
                
                string str = temp.first;
                if(str == endWord) return temp.second;
                
                for(int i=0;i<str.length();i++){
                    char x = str[i];
                    
                    for(int j=0;j<26;j++){
                        if(x - 'a' == j) continue;
                        
                        str[i] = 'a' + j;
                        auto it = st.find(str);
                        
                        if(it != st.end()){
                            if(str == endWord) return temp.second + 1;
                            q.push({str, temp.second+1});
                            st.erase(it);
                        }
                    }
                    
                    str[i] = x;
                }
            }
        }
        
        return 0;
    }
};