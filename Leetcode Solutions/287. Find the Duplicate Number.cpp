class Solution {
public:
    //Approach 1 - sorting
    //Approach 2 - use set
    //Approach 3 - using hashmap
    //Approach 4 -> Sum of Set Bits

    //mark negative index
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicate;
    }
    
    //using hashmap
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }

    //Hare n tortoise
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

//Approach 4
/*
Consider an example [3,1,3,2,4] This has n+1 elements where n = 4. 
If we did not have the duplicate, and instead had every number from 1-4, 
this base array would have been [1,2,3,4]. 
​
Initially, base_count = [0,0,0]
After 1 - [0,0,1]
After 2 - [0,1,1]
After 3 - [0,2,2]
After 4 - [1,2,2]

Now in our example :-
Initially - [0,0,0]
After 3 - [0,1,1]
After 1 - [0,1,2]
After 3 - [0,2,3]
After 2 - [0,3,3]
After 4 - [1,3,3]
Comparing both, the bit count difference is [1,3,3] - [1,2,2] = [0,1,1]. 
Which is 3, the duplicate number
*/