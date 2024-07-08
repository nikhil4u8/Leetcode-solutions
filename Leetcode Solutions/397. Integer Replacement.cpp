class Solution {
public:
    //BFS SOlution
    int integerReplacement(int n) {
        if(n==1) return 0;
        queue<pair<long long,long long>>q;
        long long num = (long long)n;
        q.push({num,0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            num = temp.first;
            
            if(temp.first%2 == 0){
                if(num/2 == 1) return temp.second+1;
                q.push({num/2,temp.second+1});
            }else{
                if(num==0 || num==2) return temp.second+1;
                q.push({num+1,temp.second+1});
                q.push({num-1,temp.second+1});
            }
        }
        
        return -1;
    }

    //DFS
    //Recursive solution
    unordered_map<long long,int> dp;
    int solve(long long n) {
        if(dp.find(n) != dp.end()) return dp[n];
        
        if(n<=0) return INT_MAX;
        if(n==1) return 0;    
        
        int mini = INT_MAX;
        
        if(n%2 ==0) mini =  1 + solve(n/2);
        else mini= 1 + min(solve(n+1),solve(n-1));
    
        return dp[n] = mini;
    }
    int integerReplacement(int n) {
      return solve(n);
    }
    //Converting dp to Itertive form
    int integerReplacementDP(int n) {
        if (n <= 1) return 0;
        int highbit = 30;
        while (highbit > 0 && (n&(1<<highbit)) == 0) highbit--;
        int[][] dp = new int[highbit+1][2];
        //dp[highbit][0] = 1; 
        dp[highbit][1] = 1;
        for (int i = highbit-1; i >= 0; i--) {
            if ((n&(1<<i)) != 0) {
                dp[i][0] = Math.min(dp[i+1][0], dp[i+1][1])+2;
                dp[i][1] = dp[i+1][1]+1;
            } else {
                dp[i][0] = dp[i+1][0]+1;
                dp[i][1] = Math.min(dp[i+1][0], dp[i+1][1])+2;
            }
        }
        return dp[0][0];
    }
};

**Constant Space
/*If n%2==0 =>only one option -> divide by 2
//else 2 option to do n+1 or n-1, we prefer n-1 becoz 
    in case of -> n-1 we reach (n-1)/2 in next step
    in case of -> n+1 we reach (n+1)/2 in next step and we will reach (n+1)/2-1 in next_next step
        which is equal to (n-1)/2
so we can reach at the same point through both cases but in case 2 it require one more step
so we prefer case 1  
. The exception is for 3, in which we go backwards.*/
 int integerReplacement(int n) {
        int op=0;
        if(n==3)return 2;
        long long n1=n;
        while(n1>1)
        {
            if(n1%2==0)n1/=2;
            else
            {
                long long int t=(n1-1)/2;
                if(t%2==0)
                    n1-=1;
                else
                    n1+=1;
            }
            if(n1==3)
                return n1+op;
            op++;
        }
        return op;
}