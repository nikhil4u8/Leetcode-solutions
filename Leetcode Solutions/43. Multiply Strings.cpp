/*
Ques to ask:
    - Can number contain leading 0?
    - Can number be negative?
    - Can number empty i.e ""?

Sol:
=> Elementary maths : [TIME - O(N+M) SPACE - O(1)]
-> N : no of digits in num1
-> M : no of digits in num2
    - Check if num1 or num2 is '0' or not, if it is then return 0
    - Multiply every digit of num2 (from end) to whole num1 & the 
    resultant product will be padded with 0 at the end [number of zeros 
    = 10^(len(num2) - i - 1)] then add all these product formed & return 
    ans.
*/
class Solution {
public:
//BEST SOLUTION
//Elementary Maths
//TIME - O(N+M) SPACE - O(1)
    string multiplyOneDigit(string num, char ch){
        string ans = "";
        int carry = 0, p = ch - '0';
        int i = num.length()-1;

        while(i >= 0){
            int product = carry;
            product += (num[i] - '0') * p;
            carry = product / 10;
            product %= 10;

            ans += to_string(product);
            i--;
        }

        if(carry != 0) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addNum(string num1, string num2){
        string ans = "";
        int carry = 0;
        int i = num1.length()-1, j = num2.length()-1;

        while(i>=0 || j>=0){
            int sum = carry;
            if(i >= 0) sum += num1[i] - '0';
            if(j >= 0) sum += num2[j] - '0';

            carry = sum/10;
            sum = sum%10;

            ans += to_string(sum);
            i--;
            j--; 
        }

        if(carry != 0) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        string ans = "";

        for(int i=num2.length()-1;i>=0;i--){
            string temp = multiplyOneDigit(num1, num2[i]);
            
            int j = num2.length() - i - 1;
            while(j--) temp += "0";
            ans = addNum(ans, temp);
        }

        return ans;
    }
};