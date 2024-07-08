/*
Desc : A array is given which is nearly sorted i.e each element is at most 
K away from its target position. Sort this array in TIME - O(NlogK)
Ex :  Inpurt - {6, 5, 3, 2, 8, 10, 9}, K = 3 
      Output - {2, 3, 5, 6, 8, 9, 10}

Ques to ask:
    - Can the dist be [i-k, i+k]?
    - Can k == 0?

Sol :
=> Insertion sort : [TIME - O(N*K) SPACE - O(1)]
    - Start from first index & find the smallest from [i, i+k] element &
    place it at ith position then move to i+1th & find min from [i+1,i+k+1]
    & repeat this until all elements are placed

BEST APPROACH
=> Using heap : [TIME - O(KLogK + (N-K)logK) SPACE - O(K)]
    - Instead of going through K elements to find min val, we'll create
    a min heap of size k+1 & put initial K+1 elements in it & one by one
    remove min element from it put it in result array & add a new element 
    to the heap from the remaining elements.
*/
void sortK(vector<int>nums, int k){   
    int n = nums.size(), idx = 0;
    int tempSize = (n == k) ? k : k+1;
    priority_queue<int, vector<int>, greater<int> > pq();
    
    // Insert first k+1 items in heap
    for(int i=0;i<tempSize;i++) pq.push(nums[i]);

    //moving window to right so adding last element of window & popping
    //min element
    for(int i=k+1;i<n;i++){
        nums[idx++] = pq.top(); pq.pop();
        pq.push(nums[i]);
    }

    while (!pq.empty()) {
        nums[idx++] = pq.top(); pq.pop();
    }
}