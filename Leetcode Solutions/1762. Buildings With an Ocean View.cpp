/*
Ques :
    - What to do in case of same height building?
    - On which side ocean is : left or right?
    - Is there any specific order in which output needs to returned?

Sol :
=> Brute Force - [TIME - O(N^2) SPACE - O(1)]
    - Traverse array from Left to Right & for each idx (i), go through 
    all the index form [i+1...n] to check if there exist a building whose
    height > curr building height, if there exist such building then curr
    index won't be able to see ocean, if it's not then curr building is
    able to see ocean


=> Best Approach - [TIME - O(N) SPACE - O(1)]
    - In above approach we're traversing through many elements multiple
    time, so to avoid this for every idx we just have to maintain max 
    building height [i+1...n] & compare it with curr building height.
    - Since last building has always a ocean view, so it makes sense to 
    traverse from R to L
    - While traversing, keep track of highest building we've seen so far
    - A building (idx = i) will be able to see ocean view only if there 
    is no building present after that from (i+1, n-1) whose height is 
    greater than current building.
*/
class Solution {
public:
    //TIME - O(N) SPACE - O(1)
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;
        int max_building_height = 0;

        for(int i=heights.size()-1;i>=0;i--){
            if(heights[i] > max_building_height){
                max_building_height = heights[i];
                ans.push_back(i);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};