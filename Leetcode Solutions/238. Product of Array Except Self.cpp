/*
Ques to ask:
    - Can we use division operator?

Sol : 
=> For every idx loop through array : [TIME - O(N^2) SPACE - O(1)]
    - For every i idx, loop through array using j pointer and whenever 
    j == i, then skip that element, else calculate product of all array & 
    put the prodcut at ith idx.

BEST APPROACH [When using '/' is allowed]
=> Find product first, then divide : [TIME - O(N) SPACE - O(1)] 
    - First find product of all array & then for every ith idx, in ans 
    array store productArray / nums[i].
    - if in case nums[i] == 0, then skip division and simply add 
    productArray to ans[i], If in case there are multiple 0 in array at 
    different position then ans array will be 0 overall. So keep track of 
    number of 0 in array, if there are multiple 0 then return ans 
    array = {0,0,0..0}

=> Finding prefix product & suffix product : [TIME - O(N) SPACE - O(N)]
    - We can precompute prefix / suffix product array, where prefix[i] 
    means product of element from [0..i] & suffix[i] means product from 
    [i...n-1], then in ans[i] = prefix[i-1]*suffix[i+1]

BEST APPROACH [When using '/' is not allowed]
=> Storing prefix / suffix product array in ans array : 
-> [TIME - O(N) SPACE - O(1)]
    - We don't need seperate array to store prefix / suffix product, we 
    can store it in ans array itself, by first looping in forward dir & 
    then in backward dir
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), backwardProduct = 1;
        vector<int>ans(n, 0);
        
        for(int i=0;i<n;i++){
            if(i == 0) ans[i] = 1;
            else ans[i] = ans[i-1]*nums[i-1];
        }

        for(int i=n-1;i>=0;i--){
            ans[i] *= backwardProduct;
            backwardProduct *= nums[i];
        }

        return ans;
    }
};