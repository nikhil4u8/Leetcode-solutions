/*
Ques to ask :
    - What if string has leading '0', then is it valid?

Sol :
=> Checking if starting / ending char are image of each other : 
[TIME - O(N) SPACE - O(1)]
    - Take 2 pointer, start / end, and check if digit at both pointer 
    are image of each other or not.
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    bool isStrobogrammatic(string num) {
        unordered_map<int, int>image;
        image[1] = 1;
        image[0] = 0;
        image[6] = 9;
        image[8] = 8;
        image[9] = 6;

        int start = 0, end = num.length()-1;
        while(start <= end){
            int num_start = num[start] - '0';
            int num_end = num[end] - '0';

            if(image.find(num_start) == image.end() ||
               image.find(num_end) == image.end()) return false;
            
            if(image[num_start] != num_end) return false;
            start++;
            end--;
        }

        return true;
    }
};