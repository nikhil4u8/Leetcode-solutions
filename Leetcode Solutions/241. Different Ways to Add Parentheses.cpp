class Solution {
public:
    //TIME - O(catlan number) Space - O(N)
    vector<int> solve(string exp,int start,int end){
        if(start>end) return {};
        if(start == end) return {exp[start]-'0'};
        string str = "";
        
        vector<int>ans;
        
        for(int i=start;i<=end;i++){
            if(exp[i]=='-' || exp[i]=='+' || exp[i]=='*'){
                vector<int>left = solve(exp,start,i-1);
                vector<int>right = solve(exp,i+1,end);
                
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        int temp;
                        if(exp[i]=='+') temp = left[j]+right[k];
                        else if(exp[i]=='-') temp = left[j]-right[k];
                        else if(exp[i]=='*') temp = left[j]*right[k];
                        
                        ans.push_back(temp);
                    }
                }
                str = "";
            }else str += exp[i];
        }
        
        if(ans.size()==0 && str!="") ans.push_back(stoi(str));
        
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression,0,expression.length()-1);
    }
};

***FOLLOW-UP
    1.Negative numbers are allowed
        if first number is Negative then we can simply evaluate