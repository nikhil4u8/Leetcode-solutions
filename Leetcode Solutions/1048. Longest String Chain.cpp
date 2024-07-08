class Solution {
public:
    static bool compare(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int>mp;
        for(int i=0;i<words.size();i++) mp[words[i]] = 1;
        
        sort(words.begin(), words.end(), compare);
        
        int longest_chain = 0;        
        for(int i=0;i<words.size();i++){
            string str = words[i];
            
            for(int j=0;j<str.length();j++){
                string temp_str = str.substr(0,j) + str.substr(j+1);
                
                if(mp.find(temp_str) != mp.end())
                    mp[str] = max(mp[str], 1 + mp[temp_str]);
            }
            longest_chain = max(longest_chain, mp[str]);
        }
        
        return longest_chain;
    }
    //TIME - O(N*N*L) SPACE - O(N)
    //Using DP
//     bool isPred(string w1, string w2){
//         int n = w1.length();
//         int m = w2.length();
        
//         if(m != n+1) return false;
        
//         int count = 0,j=0,i=0;
//         while(i<n && j<m){
//             if(w1[i] == w2[j]) count++;
//             else i--;
//             i++;
//             j++;
//         }
        
//         return count == w1.length();
//     }
//     int longestStrChain(vector<string>& words) {
//         int n = words.size();
//         vector<int>dp(n, 0);
    
//         sort(words.begin(), words.end(), compare);//NlogN
        
//         int longest_chain = 0;        
//         //N*N*L
//         for(int i=0;i<n;i++){
//             int maxi = 0;
//             for(int j=i-1;j>=0;j--){
//                 //O(L)
//                 if(isPred(words[j], words[i]))
//                     maxi = max(maxi, dp[j]);
//             }
//             dp[i] = 1 + maxi;
//             longest_chain = max(longest_chain, dp[i]);
//         }
        
//         return longest_chain;
//     }
};