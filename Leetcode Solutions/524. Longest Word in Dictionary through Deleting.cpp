class Solution {
public:
    //TIME - O(LlogL + L*N*max_len_string_in_dict)
    int LCS(string s1,string s2,int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        auto cmp = [](string& t1,string& t2){
            if(t1.length()==t2.length()) return t1<t2;
            return t1.length()>t2.length();
        };
        
        //TIME - O(LlogL)
        sort(dictionary.begin(),dictionary.end(),cmp);
        int m = s.length(),maxi=0;
        string res = "";
        
        //TIME - O(L*N*M)
        for(int i=0;i<dictionary.size();i++){
            int n = dictionary[i].length();
            if(LCS(dictionary[i],s,n,m) == n){
                if(n>=maxi){
                    if(maxi==n) res = min(res,dictionary[i]);
                    else res = dictionary[i];
                }
                maxi = max(maxi,n);
            }
        }
        
        return res;
    }
    
    //TIME - O(LlogL + L*N)
    int check_subseq(string s1,string s2){
        int j=0,k=0;
        while(j<str.length() && k<s.length()){
            if(str[j] == s[k]) j++;
            k++;
        }
        
        return j;
    }
    string findLongestWord(string s, vector<string>& dict) {
        string res = "";
        int maxi = 0;
        
        //TIME - O(LlogL)
        auto cmp = [](string& t1,string& t2){
            if(t1.length()==t2.length()) return t1<t2;
            return t1.length()>t2.length();
        };
        sort(dict.begin(),dict.end(),cmp);

        //TIME - O(L*max_len_of_string)
        for(int i=0;i<dict.size();i++){
            string str = dict[i];
            int j = check_subseq(str,s);
            
            if(j == str.length() && j>=maxi){
                if(j==maxi) res = min(res,str);
                else res = str;
                maxi = max(maxi,j);
            }
        }
        
        return res;
    }
};