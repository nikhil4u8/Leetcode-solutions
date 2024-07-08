class Solution {
public:
    //TIME - O(N) SPACE - O(1)
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);
        for(int i=0;i<min(t.length(),s.length());i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        
        return s.length()==t.length();
    }
};