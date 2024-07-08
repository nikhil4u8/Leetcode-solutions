/*
Ques to ask:
    - What if subarray has only 1 element which is removed?
    - Are there -ve int?
    - Is subarray sorted?

Sol :
=> Brute Force : [TIME - O(N^4) SPACE - O(1)]
    - Generate all subarray & remove each element from subarray once & 
    calculate the max sum of remaining elements, subarray may not be empty 
    after deleting the element, so we've to check for that, so we generate 
    subarray spanning over 2 or more elements & finally check for maximum 
    subarray sum & return it.

=> Storing cumulative sum : [TIME - O(N^3) SPACE - O(N)]
    - In above approach instead of running a loop to calculate sum again 
    & again, we'll store the cumulative sum in a array & use it for avoid 
    last for loop


BEST APPROACH
=> Check sum after removing each num : [TIME - O(N) SPACE - O(N)]
    - We can think that every index is a part of some subarray, and if 
    get's eliminated then it forms 2 subarray ending at prev idx & 
    starting at next idx, so we've to find max sum of these 2 subarray & 
    sum it both & maintain maximum too
    - If we maintain 2 array storing maximum subarray sum in forward & 
    backward direction, then for every ith idx, we can calculate 
    forward[i-1] + backward[i+1] & find maintain max sum of that.
    - The case when we're not deleting anything can be easily solved while 
    calculating prefix sum array.

=> Kadane algo : [TIME - O(N) SPACE - O(1)]
    - See below

Edge case :
    - When all number are negative
    - When array has 1 element
    - 
Follow up :
    - Solve with k deletion
*/
class Solution {
public:
//BEST APPROACH : Check sum after removing each num 
//TIME - O(N) SPACE - O(N)
    //Using 2 array + 2 pass sol
    int maximumSum(vector<int>& arr) 
    {
        int n = arr.size();
        int cur_max = arr[0], overall_max = arr[0];
        vector<int> forwardSum(n), backwardSum(n);
        forwardSum[0] = arr[0];
        
        //kadane algo : curr_max represent continious sum of subarray, wheather next element will get added to it or it'll be reset to next element (arr[i])
        for(int i = 1; i < n; i++){
            cur_max = max(arr[i], cur_max + arr[i]); 
            //case when we're not deleting anything
            overall_max = max(overall_max, cur_max); 
  
            forwardSum[i] = cur_max; 
        }
        
        cur_max = overall_max = backwardSum[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(arr[i], cur_max + arr[i]);
            //case when we're not deleting anything
            overall_max = max(overall_max, cur_max); 

            backwardSum[i] = cur_max; 
        }
        
        //case when we're deleting ith element
        for(int i = 1; i < n - 1; i++)
            overall_max = max(overall_max, forwardSum[i - 1] + backwardSum[i + 1]);
            
        return overall_max;
    }

//KADANE ALGO
//TIME - O(N) SPACE - O(1)
/*
ignoredSum : store contiguous cursum by ignoring any 1 element
notignoredSum : stores contiguous sum by not ignoring any value so far

- For each i, we'll calculate ignoredSum & notignoredSum and keep track 
of max of it & return.
- To calculate ignoredSum / notignoredSum : 

case 1 : If num[i] >= 0 -> simply add it to ingoredSum & notignoredSum

case 2 : If num[i] < 0 -> notignoredSum is still obtained by adding 
negative value to it. The ignoredSum can be two things.
1) We choose to ignore the cur value, so ignoredSum = notignoredSum from 
before
2) We choose to include the cur value, so ignoredSum += cur value.
We'll store the maximum of both.
*/
    int maximumSum(int[] arr) {
        int gmax = arr[0], max1 = arr[0]; 
        int ignoredSum = 0, notignoredSum = 0;
        for(int i=0; i<arr.size(); i++){
            ignoredSum = max(notignoredSum, ignoredSum+arr[i]);
            notignoredSum = max(arr[i], arr[i]+notignoredSum);

            gmax = max({gmax, ignoredSum, notignoredSum});
            max1 = max(max1, arr[i]);
        }

        // if all elements are -ve return max element(max1 here) else 
        // subarray max(gmax here)  
        return max1<0 ? max1 : gmax;
    }
};