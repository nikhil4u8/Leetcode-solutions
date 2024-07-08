/*
Ques to ask:
    - What if array contains multiple peak elements?
    - What if all element in array are equal & there is no peak element?
    - What happens in case of corner element? how to find if they're peak 
    or not? since they've only one neighbor to compare to?

Sol :
=> Linear traversal : [TIME - O(N) SPACE - O(1)]
    - Linearly traversal the array until we find a element who is peak 
    element.

=> Binary search : [TIME - O(logN) SPACE - O(1)]
    - For corner elements to compare to, we append the array starting / 
    ending idx with INT_MIN.
    - Instead of linearly traversing, we can use binary search. We've few 
    cases:
        1. If mid element is the peak, then return it
        2. If (mid-1)th > (mid)th element, meaning there is a possiblity 
        that num[0...i-1] can contain peak element.
        3. If (mid+1)th > (mid)th element, meaning there is a possiblity 
        that num[i+1...n-1] can contain peak element.
        4. If (mid-1)>(mid)<(mid+1), that means both side can have peak 
        element.
    - In any case, the corner element will be peak element, since 
    nums[-1] = nums[n] = INT_MIN

Edge case :
    - All increasing / decresing elements
    - All equal elements
    - Nums is empty
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(logN) SPACE - O(1)
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN);
        nums.push_back(INT_MIN);

        int start = 1, end = nums.size()-2;
        while(start <= end){
            int mid = start + (end - start)/2;

            //If true, we are on any one of the peaks
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid - 1;
            //We are on the left of the peak(any one of the peak close to mid)
            if(nums[mid] < nums[mid-1]) end = mid - 1;
            else start = mid + 1; // we are on the right of the peak
        }
        cout<<"dd";
        return end - 1;
    }
};