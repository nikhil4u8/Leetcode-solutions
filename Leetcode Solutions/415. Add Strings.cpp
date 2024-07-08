/*
Ques to ask :
    - Can string be null?
    - Does string contains negative / floating num too?

Sol :
    - Traverse both string from R to L, keep on adding digit from both str
    & maintaing carry

Follow up :
    - Input in binary number : See 67. Add Binary
    - Input with negative numbers
    - For floating point numbers
*/
class Solution {
public:
    //time - O(max(n,m)) space - O(1)
    string addStrings(string num1, string num2) {
        int l1=num1.length()-1,l2=num2.length()-1;
        string res = "";
        int carry = 0, sum = 0;
        
        while(l1>=0 || l2>=0){
            sum = carry;
            if(l1!=-1) sum += num1[l1--]-'0';
            if(l2!=-1) sum += num2[l2--]-'0';
            
            carry = sum / 10;
            sum %= 10;
            res += to_string(sum);
        }
        
        if(carry!=0) res += to_string(carry);
        reverse(res.begin(),res.end());
        
        return res;
    }
    //using stack - just store num1 and num2 and create a solution stack and treat it as res string 
    string addStrings(string num1, string num2) 
    {
        stack<int> s1, s2, solution;
        for(int i=0;i<num1.size();i++)
        {
            s1.push(num1[i]-'0');
        }
        for(int i=0;i<num2.size();i++)
        {
            s2.push(num2[i]-'0');
        }
        int carr=0, sum=0;
        while(!s1.empty() && !s2.empty())
        {
            int x= s1.top();
            int y= s2.top();
            sum = x + y + carr;
            solution.push(sum%10);
            carr = sum>=10?1:0;
            s1.pop();
            s2.pop();
        }
        while(!s1.empty())
        {
            int a = s1.top();
            int b = (a + carr);
            carr = b>=10?1:0;
            solution.push(b%10);
            s1.pop();
        }
        while(!s2.empty())
        {
            int c = s2.top();
            int d = (c + carr);
            carr = d>=10?1:0;
            solution.push(d%10);
            s2.pop();
        }
        if(carr>=1)
        {
            solution.push(1);
        }
        string k;
        while(!solution.empty())
        {
            k += solution.top()+'0';
            solution.pop();
        }
        return k;
    }


//Follow up - Add number with decimal
string addStrings(string num1, string num2) {
    
    int carry = 0 ;
    string str = "";
    int i = num1.length()-1; int j = num2.length()-1;
    int n1=0;int n2 = 0; int sum = 0;
    
    for(;i>=0||j>=0;i--,j--){
            if(i>=0) n1 = num1[i]-'0';
            else n1 = 0;
            if(j>=0) n2 = num2[j] -'0';
            else n2 = 0;
        
            sum = n1+n2+carry;
            carry = sum/10;
            sum   = sum%10;

            str += to_string(sum);
    }
    
    if(carry!=0) str += to_string(carry);
    
    reverse(str.begin(),str.end());
    return str;
}  
//Follow up - Input with negative number
/*
Find which one is biggest in magnitute, if negative num is big => overall sign is negative
else positive. Then subtract biggest magnitute num - small magnitute num and add the sign
in the end.
*/