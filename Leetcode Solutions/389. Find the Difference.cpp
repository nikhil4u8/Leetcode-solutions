class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>arr(26,0);
        int len = t.length()-1;
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        arr[t[len]-'a']--;
        
        for(int i=0;i<26;i++){
            if(arr[i]==-1) return 'a'+i;
        }
        
        return 'm';
    }
};