class Solution {
public:
    //Brute force
    bool divisorGame(int n) {
        vector<bool>Alice_Wins(1001,false);
        
        Alice_Wins[1]=false;        
        Alice_Wins[2]=true;
        
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j == 0){
                    if(Alice_Wins[i-j]==false){
                        Alice_Wins[i]=true;
                        break;
                    }
                }

            }
        }
        
        return Alice_Wins[n];
    }
    //DP SOL
     bool divisorGame(int N) {
        vector<int>dp(N+1,0);
        // 0 is just dummy
        dp[0] = 0;
        // 1 is when you lose
        dp[1] = 0;
        for (int i = 2; i <= N; i++) {
            dp[i] = 0;

            // Check the factors of i
            for (int j = 1; j*j < i; j++) {
                // If we find a factor that can reduce it down to a number where
                // the other loses, then you win
                if (i % j == 0) {
                    if (dp[i - j] == 0) dp[i] = 1;
                } 
            }
        }
        return dp[N];
    }
    //Intution
    //at the end game will min value of x will be 2, anyone having 2 will win
    //and one with even num will get even num at their every turn if played optimally so they will 
    //get 2 and win
    //2 cases -> Alice has Even/Odd number
    //Case 1-> Odd ----->(only option is to subtract odd => bob will have even num) Even num
    //Case 2-> Even ----> (2 options i.e either substract odd or even)
        //case 2.1-> e - o ----> bob will have odd num (in next turn alice will get even num)
        //case 2.2-> e - e ----> bob will have even num (if played optimally then alice won't choosen this)                                                            to subtract even num)
        //so if played optimally if alice has Even ---> then Alice will choose case 2.1, so that alice
        //have even num again
    //Now if anyone having even num will recieve even num in next turn and will win at then end
    //if anyone have odd num then it will recieve odd num only in their next turn
    
    bool divisorGame(int n) {
        return n%2 == 0;    
    }
};