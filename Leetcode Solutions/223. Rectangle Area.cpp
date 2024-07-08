/*
Sol : 
=> Subtracting common area : [TIME - O(1) SPACE - O(1)]
    - Find the common area, if it doesn't exist then set it to 0, add area of 
    both rectangle and subtract common area.
*/
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int width = min(ax2, bx2) - max(ax1, bx1);
        int height = min(ay2, by2) - max(ay1, by1);
        int commonArea = width * height;

        if(width < 0 || height < 0) commonArea = 0;

        return (ax2 - ax1)*(ay2 - ay1) + (bx2 - bx1)*(by2 - by1) - commonArea;
    }
};