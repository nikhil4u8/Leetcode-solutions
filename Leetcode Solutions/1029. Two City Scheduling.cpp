/*
Ques to ask :-
    - Can n be odd?

Ques interviewer can ask :-
    - About compare func
*/

class Solution {
public:
EXPLANATION:-
    //For each index we have 2 choices i.e A or B, so we choose such that our ans is minimized
    //Top-Down Dp(recoursion with memorization)
    int findMinValUsingDP(vector<vector<int>>&costs,int X,int Y,int index,vector<vector<int>>&dp){
        if(index==costs.size() && X==0 && Y==0)  return 0;
    
        if(dp[X][Y] != INT_MAX) return dp[X][Y];
    
        int mini = INT_MAX;
    
        if(X!=0) mini = costs[index][0] + findMinValUsingDP(costs,X-1,Y,index+1,dp);
        if(Y!=0) mini = min(mini, costs[index][1] + findMinValUsingDP(costs,X,Y-1,index+1,dp));
    
        return dp[X][Y] = mini;
    }
    int twoCitySchedCost(vector<vector<int>>& costs){
        int n = costs.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return findMinValUsingDP(costs,n/2,n/2,0,dp);
    }
    //1.Mathematically
    //     -Let's say we divide array into 2 parts each containing n elements
    //     -now 2 case arise->U1=X1+X2+...Xn/V1=Yn+1 + Yn+2+...Y2n OR U2=Y1+Y2....+Yn/V2=Xn+1+Xn+2....+X2n
    //     -2 cases for total cost -> TC1 = U1+V1 OR TC2 = U2+V2
    //     -and we need to find min(TC1,TC2);
    //     -TC1+TC2=sum of costs array and TC1-TC2=[(X1-Y1)+(X2-Y2)+...(Xn-Yn)]-[(Xn+1-Yn+1)+...(X2n-Y2n)]
    //     -2*TC1 = sum of costs array + diff -> minimize the difference to get the answer
    //     -so we need to sort the array according to their difference
    //     -TC1=(sum of costs array + sum of first part of diff array - sum second part of diff array)/2
    //2.Intution for below code
    //     -say if everyone went to city A and we sum all cost of city A and now we need to know which 
    //      person took the worst decision to go to A instead of B
    //     -worst decision -> the cost to B < cost to A
    //     -store all differences in a array and sort it, add the first n difference to sum, bcoz 
    //      diff=Y-X when added to sum cost of city A will nullify.
    //TIME - O(NlogN)  SPACE - O(N)
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>worst_decision;
        
        int sum = 0;
        for(int i=0;i<costs.size();i++){
            sum += costs[i][0];
            worst_decision.push_back(costs[i][1]-costs[i][0]);
        }
        
        sort(worst_decision.begin(),worst_decision.end());
        
        for(int i=0;i<costs.size()/2;i++) sum += worst_decision[i];
        
        return sum;
    }
//     3.Intution for below code
//         -say 2 person are there and 2 flight are there ie [X1,Y1],[X2,Y2]
//         -2 cases arises -> p0->X1 p1->Y2 OR p0->X2 p1->Y1
//         -to find which cases is more cost effective -> X1+Y2 < X2+Y1 (1st is cost effective)
//         -i.e X1-Y1 < X2-Y2 -> sort according to the difference in pair and ans = X1+...Xn+Yn+1+...Y2n
//  //TIME - O(N)  SPACE - O(1)
    bool compare(vector<int>&v1, vector<int>&v2){
        if(v1[0]-v1[1] == v2[0]-v2[1]) return v1[0] < v2[0];
        return v1[0]-v1[1] < v2[0] - v2[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),compare);
        
        int n = costs.size()/2;
        int sum = 0;
        
        for(int i=0;i<n;i++) sum += costs[i][0] + costs[i+n][1];   
        
        return sum;
    }
};