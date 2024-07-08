class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        unordered_map<char, int>freq;
        for(int i=0;i<s.length();i++) freq[s[i]]++;
        
        int unique_char = freq.size();
        int ans = 0;
        
        for(int i=1;i<=unique_char;i++){
            int str_len = count * i;
            if(str_len > s.length()) continue;
            
            vector<int>temp_freq(26, 0);
            int start = 0, end = str_len-1;
            
            for(int j = start;j<=end;j++) temp_freq[s[j]-'a']++;
            
            while(end < s.length() + 1){
                bool flag = true;
                int temp_unique = 0;
                
                for(int j=0;j<26;j++){
                    if(temp_freq[j] == 0 || temp_freq[j] == count){
                        if(temp_freq[j] == count) temp_unique++;
                        continue;
                    }
                    flag = false;
                    break;
                }
                
                if(flag && temp_unique == i) ans++;
                
                if(end == s.length()-1) break;
                
                temp_freq[s[start++]-'a']--;
                temp_freq[s[++end]-'a']++;
            }
        }
        
        return ans;
    }
};