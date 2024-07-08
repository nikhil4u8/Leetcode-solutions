/*
Ques to ask : 
    - Can k == 0 or k > n?
    - Is the array already sorted?
    - We're give integer array?

Sol :
=> Simple Sorting : [TIME - O((N-K)*KlogK*K) SPACE - O(K)]
    - Maintain a vector of size k & sort it to find the median. 
    - To move it to second window, either create a new vector & copy 
    elements from next window or from current vector delete the first 
    element of prev window & add last element of next window.
    - Keep on updating vector and sorting it to find median

BEST APPROACH
=> Using 2 Multiset : 
-> [TIME - O((n-k)logK) = O(nlogK) SPACE - O(k)] : explanation below
    - Push k/2 elements in both multiset, st. l0 stores first half & h0 
    stores second half
    - While removing a element from window, check in which multiset it's 
    present and remove it.
    - Now when adding a new element check in which half it'll belong it 
    and add it there.
    - Balance both multiset st. they both contains first / second half of 
    window
    - Median will be sum of (largest element in l0 + smallest element in 
    h0)/2 or just largest element in l0

Edge case :
    - Window size > nums.length
    - empty nums
*/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k){
        vector<double> medians;
        multiset<int> lo, hi;

        for (int i = 0; i < nums.size(); i++) {
            //remove outgoing element
            if (i >= k) {
                if (nums[i - k] <= *lo.rbegin()) lo.erase(lo.find(nums[i - k]));
                else hi.erase(hi.find(nums[i - k]));
            }

            // insert incoming element
            lo.insert(nums[i]);

            // balance the sets
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
            // balance the sets
            if (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

            // get median
            if (i >= k - 1) {
                double ans = 0;
                if(k % 2 == 1) ans = *lo.begin();
                else ans = ((double)(*lo.rbegin()) + (double)(*hi.begin()))/2;
                medians.push_back(ans);
            }
        }

        return medians;
    }
};

/*
1. At max there will be 3 deletion + 3 insertion in set of size = k/2, 
which will take O(6*log(k/2)) = O(logK) time.
2. Find median takes O(1) time since accessing start / end of multiset 
takes O(1)
3. For loop runs for N-K times, so O(N-K)

Hence TC = O((n-k)*6*logK) = O(nlogk)
SPACE = O(K) -> to store elements in window
*/