/*
Ques to ask :
    - What is num itself is maximum possible & no swap possible?
    - Does num contains leading 0s?
    - What's the range of num? -> used to find size of array?
    - What if after swapping number went out of range?

Sol :
=> Generate all combination : [TIME - O(N^2) SPACE - O(1)]
    - Convert the num to string
    - Start traversing from L to R & for every idx, we'll use a FOR loop 
    to find the highest number on the right of i & swap both, meanwhile 
    keep maintaing max val of num in a variable & return it in end

=> 2 pass approach, by storing max val after ith idx: 
-> [TIME - O(N) SPACE - O(N)]
    - Instead of traversing the string again & again to find max val for 
    every index, for every we can precompute maximum value (along with 
    it's idx in nums) present in right of ith idx & store it in a array.
    - Start traversing from start again & swap val at first idx with max 
    val present in array, if in case max_val == val at first idx, then 
    move to swap val at next idx.


BEST APPROACH
=> One pass without using space : [TIME - O(N) SPACE - O(1)]
    - Traverse in backward, and during scan record the largest digit 
    (maxi) found & it's corresponding index.
    - If current digit is smaller than largest digit, then currDigit & 
    largest digit are best candidate to swap to obtain max num so far if 
    there is no more such situation on left side. Meanwhile we'll record 
    this pair too.

Edge case :
    - What if after swapping number went out of range?
    - "1993", multiple max number are present, which one to swap with?
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N) SPACE - O(1)
    int maximumSwap(int num) {
        string tempN = to_string(num);

        int maxIdx = -1, maxDigit = -1;
        int leftIdx = -1, rightIdx = -1;

        for(int i=tempN.length()-1;i>=0;i--){
            int currDigit = tempN[i] - '0';
            // current digit is the largest by far
            if(currDigit > maxDigit){
                maxDigit = currDigit;
                maxIdx = i;
                continue;
            }
            // best candidate for max swap if there is no more 
            // such situation on the left side
            if(currDigit < maxDigit){
                leftIdx = i;
                rightIdx = maxIdx;
            }
        }

        // num is not in order
        if(leftIdx != -1) swap(tempN[leftIdx], tempN[rightIdx]);
        return stoi(tempN);
    }
//Approach - 2
//TIME - O(N) SPACE - O(N)
    int maximumSwap(int num) {
        //mainting max num after index i
        vector<pair<int, int>>maxNumAfterThisIndex(9);
        int maxi = 0, idx = 0;
        string tempN = to_string(num);

        //storing max num from [i+1, end] along with it's idx
        for(int i=tempN.length()-1; i>=0 ;i--){
            if(maxi < tempN[i] - '0'){
                maxi = max(maxi, tempN[i] - '0');
                idx = i;
            }
            maxNumAfterThisIndex[i] = {maxi, idx};
        }
        
        //start traversing from L to R, since swap at first place will yield highest num.
        //For each idx, if the max num b/w [i+1, end] is greater than currDigit then swap both
        //Else move to next idx
        for(int i=0;i<tempN.length();i++){
            int currDigit = tempN[i] - '0';
            if(maxNumAfterThisIndex[i].first > currDigit){
                int swapIdx = maxNumAfterThisIndex[i].second;
                swap(tempN[i], tempN[swapIdx]);
                break;
            }
        }

        return stoi(tempN);
    }
};