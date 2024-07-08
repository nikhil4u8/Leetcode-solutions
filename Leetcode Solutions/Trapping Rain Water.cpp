/*
Sol : 
ans[curr] = min(far_left, far_right) - height[curr];
=> Brute Force : [TIME - O(N^2) SPACE - O(1)]
    - For each idx, we'll run 2 for loop to find what is the max_height 
    in left / right and take min of them - height[curr].

=> Max using 2 array : [TIME - O(N) SPACE - O(N)]
    - Instead of running 2 for loop to find farest greatest to the left 
    and right, we'll maintain 2 array to store max for left / right.

BEST APPROACH
=> Using 2 Pointers : [TIME - O(N) SPACE - O(1)]
    - Maintain 2 point left (start) / right (end) & we'll see whose height 
    is bigger, say height[left] < height[right] this means that there is a 
    possibility to fill water at left pos, and no possibility of filling 
    water at right pos.
    - We'll maintain a leftMax / rightMax too, then check if 
    height[left] < leftMax or not, if it is then we can fill water here = 
    leftMax - height[left] otherwise if height[left] > leftMax, then we'll 
    update leftMax.
    - Similar do this for right.

*/
class Solution {
    public int trap(int[] height) {
        if (height == null || height.length == 0) return 0;
        
        // Pointers to both ends of the array.
        int left = 0; int right = height.length - 1;
        int maxLeft = 0; int maxRight = 0;
        
        int totalWater = 0;
        while (left < right) {
            // Water could, potentially, fill everything from left to right, 
            //if there is nothing in between.
            if (height[left] < height[right]) {
                // If the current elevation is greater than the previous 
                // maximum, water cannot occupy that point at all.
                // But, we know that everything from maxLeft to the cur idx, 
                // has been optimally filled, as we've been adding water 
                // to the brim of the last maxLeft.
                if (height[left] >= maxLeft) { 
                    // Now, we've found new maximum, look to see how much 
                    // water we can fill from this point on.
                    maxLeft = height[left]; 
                // If we've yet to find a maximum, we know that we can fill 
                // the current point with water up to the previous max, as 
                // any more will overflow it. We also subtract the cur 
                // height, as that is the elevation the ground will be at.
                } else totalWater += maxLeft - height[left]; 

                left++;
            // If the height[eft] > height[right], we cannot fill from left to right without over-
            // flowing; however, we do know that we could potentially fill from right to left, if there is nothing in between.
            } else {
                // Similarly to above, we see that we've found a height greater than the max, and cannot fill it whatsoever, but
                // everything before is optimally filled
                if (height[right] >= maxRight) { 
                    // We can say we've found a new maximum and move on.  
                    maxRight = height[right]; 
                // If we haven't found a greater elevation, we can fill the current elevation with maxRight - height[right]
                // water.
                } else totalWater += maxRight - height[right]; 
                // Decrement left, we'll look at the next point.
                right--;
            }
        }
        // Return the sum we've been adding to.
        return totalWater;
    }
}