/*
Ques to ask :
    - Can x / n be negative or can x == 0?
    - Can x / n be fractional?

Sol :
=> Brute Force
    - Use inbuild fun of pow

=> Using For loop : [TIME - O(N) SPACE - O(1)]
    - Run a for loop to multiply x, n times.

=> Using recursion : [TIME - O(logN) SPACE - O(1)]
    - If n is even, then x^n is composed of x^(n/2) * x^(n/2), so we just 
    have to find x^(n/2) recursively & multiply it 2 times.
    - If n is odd, then also we need to find x^(n/2) recursively & 
    multiply x*x^(n/2)*x^(n/2).
    - If in case n is negative then instead of multiplying x we need to 
    multiply (1/x) n times.
*/
class Solution {
public:
//TIME - O(logN) SPACE - O(1)
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == -1) return 1/x;
        if(n == 1) return x;
        
        double temp = myPow(x, n/2);

        if(n % 2 == 0) return temp*temp;

        if(n < 0) return (temp*temp)/x;

        return x*temp*temp;
    }
};