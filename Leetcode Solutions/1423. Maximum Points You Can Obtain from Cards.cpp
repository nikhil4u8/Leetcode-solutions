class Solution {
public:
//     //Recursive solution
//     int solve(vector<int>&card, int k, int start, int end){
//         if(k == 0) return 0;
//         if(start > end) return 0;
        
//         return max(card[start] + solve(card, k-1, start+1, end), 
//                    card[end] + solve(card, k-1, start, end-1));
//     }
//     int maxScore(vector<int>& cardPoints, int k) {
//         return solve(cardPoints, k, 0, cardPoints.size()-1);
//     }
//     //TIME - O(K) SPACE - O(K)
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         vector<int>frontSetCards(k+1);
//         vector<int>backSetCards(k+1);
        
//         for(int i=0;i<k;i++){
//             frontSetCards[i+1] = cardPoints[i] + frontSetCards[i];
//             backSetCards[i + 1] = cardPoints[n - i - 1] + backSetCards[i];
//         }
        
//         int max_score = 0;
//         for(int i=0;i<=k;i++){
//             int curr_score = frontSetCards[i] + backSetCards[k - i];
//             max_score = max(max_score, curr_score);
//         }
        
//         return max_score;
//     }
//     //TIME - O(K) SPACE - O(1)
//     int maxScore(vector<int> &cardPoints, int k) {
//         int frontScore = 0;
//         int rearScore = 0;
//         int n = cardPoints.size();

//         for (int i = 0; i < k; i++) {
//             frontScore += cardPoints[i];
//         }

//         // take all k cards from the beginning
//         int maxScore = frontScore;

//         // take i from the beginning and k - i from the end
//         for (int i = k - 1; i >= 0; i--) {
//             rearScore += cardPoints[n - (k - i)];
//             frontScore -= cardPoints[i];
//             int currentScore = rearScore + frontScore;
//             maxScore = max(maxScore, currentScore);
//         }

//         return maxScore;
//     }
    //TIME - O(N) SPACE - O(1)
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, total_sum = 0;
        
        for(int i=0;i<n-k;i++) sum += cardPoints[i];
        total_sum = sum;
        
        for(int i=n-k;i<n;i++) total_sum += cardPoints[i];
        
        int i=0,j=n-1-k, mini = sum;
        
        while(j<n-1){
            sum -= cardPoints[i++];
            sum += cardPoints[++j];
            
            mini = min(mini, sum);
        }
        
        return total_sum - mini;
    }
};