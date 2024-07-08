/*
APPROACH 1 - 
Initally we allocate all the difference with ladder, and when ladder finishes then we start allocating bricks to all the smaller gaps where ladder is placed

TIME - O(NlogL) 
SPACE - O(L)
N is heights.size()
L is number of ladders
*/
// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         if(heights.size() == 1) return 0;
//         priority_queue<int, vector<int>, greater<int>>pq;
        
//         for(int i=1;i<heights.size();i++){
//             int diff = heights[i] - heights[i-1];
//             //if diff <= 0 => JuMP DOWN
//             if(diff <= 0) continue;
            
//             //Otherwise allocate a ladder to climb this diff
//             pq.push(diff);
//             //If we have ladders left to allocate then push them to pq
//             if(pq.size() <= ladders) continue;
//             //Otherwise we need to allocate bricks to the diff or exchange ladders with bricks
//             bricks -= pq.top(); pq.pop();
            
//             if(bricks < 0) return i-1;
//         }
        
//         return heights.size() - 1;
//     }
// };
/*
Approach 2 - Initially we allocate all the gaps with bricks, then store all these gapes in max heap and when bricks get finished then we start allocating ladders to all the gaps where maximum bricks is used

TIME - O(NlogL)
SPACE - O(L)
N is heights.size()
L is number of ladders
*/
// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         if(heights.size() == 1) return 0;
//         priority_queue<int>pq;
        
//         for(int i=1;i<heights.size();i++){
//             int diff = heights[i] - heights[i-1];
//             //if diff <= 0 => JuMP DOWN
//             if(diff <= 0) continue;
//             // Otherwise, allocate a ladder for this climb.
//             pq.push(diff);
//             bricks -= diff;
            
//             // If we've used all the bricks, and have no ladders remaining, then 
//             // we can't go any further.
//             if(bricks < 0 && ladders == 0) return i-1;
//             // Otherwise, if we've run out of bricks, we should replace the largest
//             // brick allocation with a ladder.
//             if(bricks < 0){
//                 bricks += pq.top(); pq.pop();
//                 ladders--;
//             }
//         }
        
//         return heights.size() - 1;
//     }
// };
/*
Approach 3 - Binary Search
We have n building, so we do a binary search on them, we will check if mid building is reachable or not with given bricks and ladders, if it is then check on right i.e for more building, if it's not then check in left i.r for less building

TIME - O(NlogN)
SPACE - O(N)
*/
class Solution {
public:
    bool isReachable(vector<pair<int,int>>&jump_diff, int bricks, int ladders, int target_idx){
        for(int i=0;i<jump_diff.size();i++){
            int diff = jump_diff[i].first;
            int idx = jump_diff[i].second;
            
            if(idx > target_idx) continue;
            
            if(diff <= bricks) bricks -= diff;
            else if(ladders > 0) ladders--;
            else return false;
        }
        
        return true;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<pair<int,int>>jump_diff;
        
        for(int i=1;i<heights.size();i++){
            int diff = heights[i] - heights[i-1];
            if(diff <= 0) continue;
            jump_diff.push_back({diff, i});
        }
        sort(jump_diff.begin(), jump_diff.end());
        
        int i=0, j = heights.size()-1, ans = -1;
        
        while(i<=j){
            int mid = (i+j)/2;
            if(isReachable(jump_diff, bricks, ladders, mid)){
                ans = max(ans, mid);
                i = mid+1;
            }else j = mid-1;
        }
        
        return ans;
    }
};