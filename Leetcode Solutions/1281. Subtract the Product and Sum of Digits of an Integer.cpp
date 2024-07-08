class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        
        while(n>0){
            int t = n%10;
            sum += t;
            product *= t;
            n /=10;
        }
        
        return product-sum;
    }
};