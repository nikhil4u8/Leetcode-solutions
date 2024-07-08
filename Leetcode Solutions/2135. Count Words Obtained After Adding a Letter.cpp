class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = startWords.size();
        unordered_set<bitset<26>>bitmask_set;

        for(int i=0;i<n;i++){
            string str = startWords[i];
            bitset<26>bt;
            
            for(int j=0;j<str.length();j++) bt[str[j]-'a'] = 1;
            
            bitmask_set.insert(bt);
        }
        
        int ans = 0;
        for(int i=0;i<targetWords.size();i++){
            string str = targetWords[i];
            bitset<26>bt;
            bool found = false;
            
            for(int j=0;j<str.length();j++) bt[str[j]-'a'] = 1;
            
            for(int j=0;j<str.length();j++){
                if(bt[str[j] - 'a']){
                    bt[str[j] - 'a'] = 0;
                    if(bitmask_set.find(bt) != bitmask_set.end()){
                        found = true;
                        break;
                    }
                    bt[str[j] - 'a'] = 1;
                }
            }
            ans += found;
        }
        
        return ans;
    }
};