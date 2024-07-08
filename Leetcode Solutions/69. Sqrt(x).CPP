class Solution {
public:
// TIME - O(logN) SPACE - O(1)
    int mySqrt(int x) {
        if(x < 2) return x;

        int start = 2, end = x/2;
        while(start <= end){
            long long int mid = start + (end - start)/2;
            long long int num = mid*mid;
            if(num == (long long int)x) return mid;
            else if(num > (long long int)x) end = mid-1;
            else start = mid+1;
        }

        return end;
    }
};