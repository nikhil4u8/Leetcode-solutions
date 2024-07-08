class Solution {
public:
    bool solve(string str1, string str2){
        unordered_map<char, char>mp;
        unordered_set<char>unique_char;
        
        for(int i=0;i<str1.length();i++){cout<<str1[i]<<" ";
            if(mp.find(str1[i]) == mp.end()){
                mp[str1[i]] = str2[i];
                unique_char.insert(str2[i]);
            }else if(mp[str1[i]] != str2[i])
                return false;
        }
        
        if(unique_char.size() < 26) return true;
        return false;
    }
    bool canConvert(string str1, string str2) {
        if(str1.length() != str2.length()) return false;
        if(str1 == str2) return true;
        return solve(str1, str2);
    }
};