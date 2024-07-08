/*
Ques to ask:
    - If n = 2, then can we generate "00"?

Sol :
//BEST APPROACH
=> Build str from middle to end : [TIME - O(5^(N/2)) SPACE - O(5^(N/2))]
    - We can start constructing string from middle, if N is odd, then 
    middle digit can have "0", "1", "8" only as they're image of 
    themselves when turned 180 degree, if N is even then middle elements 
    can be anything.
    - Now, keep wrapping middle element with out layer numbers (from both 
    the side), just make sure that "0" can't be the first digit of number.
    - Corner cases : When N == 1, then return {"0", "1", "8"} | When 
    N == 0, then return {""};

Edge case :
    - When N == 0, N == 1
    - 0 can not be at the head or the tail unless the length is 1
    - If the N is odd, then the middle digit should be one of 0, 1, 8
*/
class Solution {
public:
//TIME - O(N*5^(N/2+1)) SPACE - O(N*5^(N/2))
    vector<string>helper(int n,int m){
        if(n==0) return vector<string>{""};
        if(n==1) return vector<string> {"0","1","8"};

        vector<string> list = helper(n-2,m);
        vector<string> result;

        for(int i=0;i<list.size();i++)
        {
            string s = list[i];
            if(n!=m) 
                result.push_back("0"+s+"0");

            result.push_back("1"+s+"1");
            result.push_back("6"+s+"9");
            result.push_back("8"+s+"8");
            result.push_back("9"+s+"6");
        }
        return result;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n,n);   
    }
};
/*
TIME / SPACE COMPLEXITY EXPLANATION 
We know that the set is at least exponentially large since we have 
potentially 5 digits {0, 1, 6, 8, 9} and when we're constructing the 
result each digit can be approximately paired with the corresponding set 
{0, 1, 9, 8, 6}. Therefore constructing all possible values for n=4 for 
instance, yields approximately 0000, 0110, 0690, 0880, 0960, 1001, 1111, 
1691, 1881, etc... which is order O(5^(n/2)) which is also known as O(2^n)
*/