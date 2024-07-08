class Solution {
public:
    void generateParenthesis(vector<string>&res,int n,int open,int close,string str){
        if(open==n && close==n){
            res.push_back(str);
            return;
        }
        
        if(open>close && close<n) generateParenthesis(res,n,open,close+1,str+')');
        if(open<n) generateParenthesis(res,n,open+1,close,str+'(');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generateParenthesis(res,n,0,0,"");
        return res;
    }
};