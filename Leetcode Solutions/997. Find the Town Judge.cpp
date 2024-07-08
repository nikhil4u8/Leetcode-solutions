class Solution {
public:
    //TIME - O(N) SPACE - O(N)
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<int>indegree(n, 0);
//         vector<int>outdegree(n, 0);
        
//         for(int i=0;i<trust.size();i++){
//             indegree[trust[i][1]-1]++;
//             outdegree[trust[i][0]-1]++;
//         }
        
//         for(int i=0;i<n;i++){
//             if(indegree[i] == n-1 && outdegree[i] == 0)
//                 return i+1;
//         }
        
//         return -1;
//     }
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>score(n, 0);
        
        for(int i=0;i<trust.size();i++){
            score[trust[i][1] - 1]++;
            score[trust[i][0] - 1]--;
        }
        
        for(int i=0;i<n;i++){
            if(score[i] == n-1) 
                return i+1;
        }
        return -1;
    }
};