class Solution {
public:
    void solve(string digit,vector<string>&ans,unordered_map<int,string>&mp,int index,string str){
        if(str.length() == digit.length()){
            ans.push_back(str);
            return;
        }
        
        for(int i=0;i<mp[digit[index]-'0'].size();i++){
            solve(digit,ans,mp,index+1,str + mp[digit[index]-'0'][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        vector<string>ans;
        
        solve(digits,ans,mp,0,"");
        
        return ans;
    }
};