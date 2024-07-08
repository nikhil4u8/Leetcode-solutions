/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
// TIME - O(logN) SPACE - O(1)
    int guessNumber(int n) {
        int i = 1, j = n;
        while(i <= j){
            int mid = i + (j - i)/2;
            int check = guess(mid);
            if(check == 0) return mid;
            else if(check == -1) j = mid - 1;
            else i = mid + 1;
        }

        return -1;
    }
};