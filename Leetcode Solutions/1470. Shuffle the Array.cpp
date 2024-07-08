class Solution {
public:
    //Basic approach
    //TIME - O(N) SPACE - O(N)
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res(2*n,0);
        int j=0;
        
        for(int i=0;i<n;i++,j+=2){
            res[j] = nums[i];
            res[j+1] = nums[i+n];
        }
        
        return res;
    }
    //In-place approach
    //time - O(n) space - O(1)
    /*lets say we have our ans array same as size of nums
ans = [ _ , _ , _ , _ , _ , _ , _ , _ ]

what will be even indices in ans array, they are just first half of our ans array from index (0, 3) inclusive
ok now what will odd indices in ans array would be holding, its second half of our nums array (4, 7) inclusive

we know now what will be our answer only thing we need to do is to do in constant space
let iterate from last (7 index in this case)

INDEX 7: since this is odd index we know value will be from left half and what show be the corrert 
value at index 7, it should be last value of nums array.

INDEX 6: since this is even index, what will be the value here, it will be last index of first half 
i.e 6/2 = 3 ok swap nums[3] and nums[6] , nums arr is now [1,2,3,2,4,3,4,1]

INDEX 5: this is odd index what should be the value here, second last value in nums array but notice 
we just swaped the value at index 6 if we swap with that index we get wrong ans, ok so what so we do? 
where is second last element of left half its in last of first half so we go there (This was 
the main logic behind the solution..), this is what we are doing inside do while loop if index (k) 
is odd*/
    vector<int> shuffle(vector<int>& a, int n) {
        for(int i=2*n-1; i>=0; --i) {
            int k = i;
            do {
                if(k%2 == 1) {
                    k = k/2+n;
					// why adding n, notice for odd indeces we take element from second part of 
					// nums array (a in code implementation) we are traversing right to left so we are
                    // adding n
                } else k = k/2;
                //K>i done bcoz the element which will replace i will always come from index less than k
            } while(k > i);
            swap(a[i], a[k]);
        }
        return a;
    }
};