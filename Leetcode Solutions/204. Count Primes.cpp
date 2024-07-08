class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;

        int count = 0;
        vector<bool>prime(n+1, false);

        for(int i = 2;i<n/2+1;i++){
            int j = i*2;
            while(j<=n){
                prime[j] = true;
                j += i;
            }
        }

        for(int i=2;i<n;i++){
            if(!prime[i]) count++;
        }

        return count;
    }
};