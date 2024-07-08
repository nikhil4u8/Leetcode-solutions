class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
         
        long long int bits = log2(n) + 1;
        long long int xor_num = pow(2, bits) - 1;

        return xor_num ^ n;
    }
};