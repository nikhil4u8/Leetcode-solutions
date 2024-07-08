/*
Ques to ask :
    - Can k == 0 or k > nums.size()?
    - What if k = 2 & array = [1,1,2] then ans = 1? Wanted to confirm 
    what happens in case of duplicates?

Sol :
=> Brute force - [TIME - O(NlogN) SPACE - O(1)]
    - Simply sort the array & return element at kth index

BEST APPROACH
=> Using Heap - [TIME - O(NlogK) SPACE - O(k)]
    - Traverse the array & use min heap to store all elements one by 
    one & once the size of min heap becomes > K, then pop the top most 
    element as heap will store top K largest elements so dropping all 
    elements who are less than topK elements.

BEST APPROACH : [If asked to optimize more]
=> Quick Select : [TIME - O(N) SPACE - O(N)]
    - Firstly, we select a pivot (last element of array) then traverse the
    array & swap all elements one by one & find a position for pivot such
    that elements before pivot are <pivot & element after pivot are >pivot
    - Now our search space also get's reduce, so we need to find pivot
    whose position is k

NOTE : The avg time complexity of Quick select is O(N), since we're reducing
search space after every pivot is placed, but in worst cast time complexity
is O(N^2) i.e in case of constantly bad chosen pivot, the search space is
not divided in half at each step, it just become one element less this leads
to O(N^2)
*/
class Solution {
public:
//APPROACH - 2
//TIME - O(NlogK) SPACE - O(K)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);

            if(pq.size() > k) pq.pop();
        }

        return pq.top();
    }
};
//BEST SOLUTION
//Approach - 3
//QUICK SELECT
class Solution {
public:
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        
        for (int num: nums) {
            if (num > pivot) left.push_back(num);
            else if (num < pivot) right.push_back(num);
            else mid.push_back(num);
        }
        
        if (k <= left.size()) return quickSelect(left, k);
        if (left.size() + mid.size() < k)
            return quickSelect(right, k - left.size() - mid.size());
        
        return pivot;   
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};