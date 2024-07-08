/*
Ques to ask :
    - Can string be null?
    - Can there be negative numbers?

Sol :
    - Traverse both string from R to L, keep on adding digit from both str
    & maintaing carry
    - To find sum / carry in decimal we do /10 or %10, but since we're 
    dealing with binary so to find sum / carry we'll do /2 or %2

Follow up :
    - Input with Normal numbers : See 415. Add String
    - Input with negative numbers
*/
class Solution {
public:
//TIME - O(max len of str) SPACE - O(1)
    string addBinary(string a, string b){
        string ans = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0, sum = 0;

        //simply adding 2 strings
        while(i >= 0 || j >= 0){
            sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            carry = sum / 2;
            sum %= 2;

            ans += to_string(sum);
        }

        if(carry != 0) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};