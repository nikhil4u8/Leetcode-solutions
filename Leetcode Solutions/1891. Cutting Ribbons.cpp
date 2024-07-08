/*
Ques to ask :
    - What if 0 ribbon cut possible?
    - Are we allowed to throw any excess ribbon as a result of cutting?

Sol :
SAY THIS FIRST
INTUTITON : When we are gradually increasing the length l starting from 0, 
there is a cut-off where we can cut ribbons into k ribbons with length 
l <= l_critical but cannot cut them into k ribbons with length 
l > l_critical. So it's intuitive to come up with a binary search solution 
to find such l_critical.

BEST APPROACH
=> Binary Search in max ribbon len : 
-> [TIME - O(N*log(maxRibbonLen)) SPACE - O(1)]
    - Max possible len of ribbon = max len of available ribbon in list
    Min possible len = 1, so we can do a binary search in this range and 
    find the first ribbon len such that we can extract atleast k ribbon of 
    same len.
    - To reduce the search range of BS more, we can find max possible 
    ribbon len = (sum of all ribbon len) / k

Edge case :
    - When sum of all num go out of INT bound.
    - No of ribbon cut possible = 0
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N*log(maxRibbonLen)) SPACE - O(1)
    bool isCutPossible(vector<int>&ribbons, int ribbonLen, int k){
        int totalRibbon = 0;
        for(int i=0;i<ribbons.size();i++) 
            totalRibbon += ribbons[i]/ribbonLen;
        return totalRibbon >= k;
    }
    int maxLength(vector<int>& ribbons, int k) {
        int maxRibbonLen = 0, totalRibbonLen = 0;
        /*
        This is actual logic, but totalRibbonLen can go out of bound hence
        not using it.
        for(int i=0;i<ribbons.size();i++) totalRibbonLen += ribbons[i];
        maxRibbonLen = totalRibbonLen / k;
        */
        for(int i=0;i<ribbons.size();i++) 
            maxRibbonLen += ceil((double)ribbons[i]/(double)k);

        int start = 1, end = maxRibbonLen;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(isCutPossible(ribbons, mid, k)) start = mid+1;
            else end = mid-1;
        }

        return end;
    }
};