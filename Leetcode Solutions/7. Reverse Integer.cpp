class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int rev_x = 0;
        int sign = x>0 ? 1 : -1;
        x = abs(x);

        while(x>0){
            if(rev_x>INT_MAX/10 || (rev_x==INT_MAX/10 && x%10>7)) return 0;
            rev_x = rev_x*10 + x%10;
            x = x/10;
        }

        return sign*rev_x;
    }
};