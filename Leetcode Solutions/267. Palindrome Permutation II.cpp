class Solution {
public:
    unordered_set<string>ans;
    void generate_str(string str, unordered_map<char, int>freq, string prefix, string suffix){
        if(str.length() == prefix.length() + suffix.length()){
            reverse(suffix.begin(), suffix.end());
            ans.insert(prefix + suffix);
            return;
        } 
        
        for(auto it : freq){
            if(it.second == 0) continue;
            
            if(prefix.length() + suffix.length() == str.length()-1){
                if(it.second % 2 != 0){
                    freq[it.first]--;
                    generate_str(str, freq, prefix + it.first, suffix);
                    freq[it.first]++;
                }
                continue;
            }
            
            if(it.second < 2) continue;
            freq[it.first] -= 2;
            generate_str(str, freq, prefix + it.first, suffix + it.first);
            freq[it.first] += 2;
        }
    }
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int>freq;
        int count = 0;
        
        for(int i=0;i<s.length();i++) freq[s[i]]++;
        for(auto it : freq){
            if(it.second % 2 != 0) count++;
            if(count >= 2) return {};
        }
        
        generate_str(s, freq, "", "");
        
        vector<string>res;
        for(auto it=ans.begin();it != ans.end();it++) res.push_back(*it);
        
        return res;
    }
};