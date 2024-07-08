/*
Approach -
1. Using Sorting + Two Pointer
2. Using Heap
*/
class Solution {
public:
    //Using Sorting + Two Pointer
    //TIME - O(MlogM + NlogN) SPACE - O(1)
//     vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
//         sort(slots1.begin(), slots1.end());
//         sort(slots2.begin(), slots2.end());
//         int i = 0, j=0;
        
//         while(i<slots1.size() && j<slots2.size()){
//             if(slots1[i][1] <= slots2[j][0]) i++;
//             else if(slots1[i][0] >= slots2[j][1]) j++;
//             else{
//                 int start = max(slots1[i][0], slots2[j][0]);
//                 int end = min(slots1[i][1], slots2[j][1]);
                
//                 if(end - start >= duration){
//                     return {start, start + duration};
//                 }
//                 if(end == slots1[i][1]) i++;
//                 else j++;
//             }
//         }
        
//         return {};
//     }
    //Using Heap
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        for(int i=0;i<slots1.size();i++){
            if(slots1[i][1] - slots1[i][0] >= duration){
                pq.push({slots1[i][0], slots1[i][1], 0});
            }
        }
        for(int i=0;i<slots2.size();i++){
            if(slots2[i][1] - slots2[i][0] >= duration){
                pq.push({slots2[i][0], slots2[i][1], 1});
            }
        }
        
        while(pq.size() > 1){
            auto t1 = pq.top(); pq.pop();
            auto t2 = pq.top(); pq.pop();
            if(t1[2] ^ t2[2] == 1){
                int start = max(t1[0], t2[0]);
                int end = min(t1[1], t2[1]);
                
                if(end - start >= duration){
                    return {start, start + duration};
                }
            }
            pq.push(t2);
        }
        
        return {};
    }
};