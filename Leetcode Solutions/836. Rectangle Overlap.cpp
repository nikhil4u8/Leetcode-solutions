/*
Ques to ask :
    - What if 2 rectangle touch at the corner or edge?

Sol:
BEST APPROACH
=> Finding valid common rect : [TIME - O(1) SPACE - O(1)]
    - Finding coordinates of common rect & checking if it's valid rect 
    or not.
*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int commonRectTopX = min(rec1[2], rec2[2]);
        int commonRectTopY = min(rec1[3], rec2[3]);

        int commonRectBottomX = max(rec1[0], rec2[0]);
        int commonRectBottomY = max(rec1[1], rec2[1]);

        return commonRectTopX > commonRectBottomX && 
               commonRectTopY > commonRectBottomY;
    }
};