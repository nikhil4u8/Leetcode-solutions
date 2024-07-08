/*
Ques to ask :
    - What if next permutation is not possible?
    - Do we've negative or double digit number in array?

Sol :
=> Brute Force - [TIME - O(N!) SPACE - O(N)]
    - Generate every possible permutation of list and find permutation 
    which is greater than num


=> SAY THIS BEFORE PROCEEDING FURTHER
    - General trends - 123 -> 124 -> 129 -> 130 -> 131 -> 199 -> 200 i.e
    incrementing ones until we reach end (i.e 9), then move to incrementing 
    tenth position(& reset all digits after tenth position) then to 
    hundredth position.
    - This happens when you're allowed to use all digits from 0-9, but 
    in this case we're not allowed to use all digits.
    - So we can't increment digits here rather we've to swap digits & 
    while swapping we've to considering that after swapping we obtain a 
    bigger num i.e num at lower position must have higher val than num 
    present at higher position
    

=> Swapping Lower with higher num - [TIME - O(N^2) SPACE - O(1)]
    - Start traversing str from backways & for every idx, we'll find the 
    smallest number which is greater than nums[i] to swap with it. 
    - If there exist such num, then swap it & sort string from (i+1, end) & 
    return
    - If there doesn't exist such num, then decrement ith pointer & 
    repeat step 2


BEST APPROACH
=> Array + Two Pointer - [TIME - O(N) SPACE - O(1)]
    - Instead of fixing each idx & traversing in str (i+1, end) & finding 
    smallest num greater than nums[i]. We're traversing through same str 
    again & again.
    - Rather, traverse backwards & keep track of max num from [i+1...n] idx
    & for every ith idx, if it's < max_element then there exist some num
    from [i+1...n] which is smallest num greater than nums[i].
    - So, traverse from (i+1, end) & find smallest num which is greater 
    than pivot & swap both & sort (i+1, end) & return

Follow up :
    - Find previous permutation

Similar Ques : Ref 556. Next Greater Element III
*/
class Solution {
public:
//BEST APPROACH
//APPROACH - 3
//TIME - O(N) SPACE - O(1)
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;

        int maxi = nums[n-1];
        for(int i=nums.size()-2;i>=0;i--){
            int curr = nums[i];

            if(curr < maxi){
                int minNum = INT_MAX, minIdx = -1;

                for(int j=i+1;j<n;j++){
                    if(nums[j] > curr && minNum > nums[j]){
                        minNum = nums[j];
                        minIdx = j;
                    }
                }
                
                if(minIdx != -1){
                    swap(nums[minIdx], nums[i]);
                    sort(nums.begin()+i+1, nums.end());
                    return;
                }
            }
            maxi = max(maxi, curr);
        }

        sort(nums.begin(), nums.end());
    }

//APPROACH - 2
//TIME - O(N^2) SPACE - O(1)
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=n-2;i>=0;i--){
            int last = INT_MAX,index=-1;
            //In follow up interchange sign
            if(nums[i]>=nums[i+1]) continue;
            
            for(int j=i+1;j<n;j++){
                //in follow up change sign and also find max number 
                //which is smaller than num
                if(nums[j]>nums[i]){
                    last = min(last,nums[j]);
                    index = j;
                }
            }
            if(index!=-1){
                swap(nums[index],nums[i]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};