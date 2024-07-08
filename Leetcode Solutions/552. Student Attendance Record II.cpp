class Solution {
public:
    //A < 2
    //L < consecutive 3 
//     P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ≥ 2.
//     L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ≥ 3.
//     A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ≥ 4.

//     Here, noAP(n) and noAL(n) disappeared.

//     Initial value
//     P(1) = 1.
//     L(1) = 1, L(2) = 3.
//     A(1) = 1, A(2) = 2, A(3) = 4.
    int mod = 1000000007;
    vector<int>P = vector<int>(100001, -1);
    vector<int>L = vector<int>(100001, -1);
    vector<int>A = vector<int>(100001, -1);
    int absent(int n){
        if(n == 1) return A[n] = 1;
        if(n == 2) return A[n] = 2;
        if(n == 3) return A[n] = 4;
        
        if(A[n] != -1) return A[n];
        return A[n] = ((absent(n-1)%mod + absent(n-2)%mod)%mod + absent(n-3)%mod)%mod;
    }
    int late(int n){
        if(n == 1) return L[n] = 1;
        if(n == 2) return L[n] = 3;
        
        if(L[n] != -1) return L[n];
        return L[n] = (((absent(n-1)%mod + present(n-1)%mod)%mod + absent(n-2)%mod)%mod + present(n-2)%mod)%mod;
    }
    int present(int n){
        if(n == 1) return P[n] = 1;
        if(P[n] != -1) return P[n];
        return P[n] = ((absent(n-1)%mod + present(n-1)%mod)%mod + late(n-1)%mod)%mod;
    }
    int checkRecord(int n) {
        return ((present(n)%mod + absent(n)%mod)%mod + late(n)%mod)%mod;
    }
};