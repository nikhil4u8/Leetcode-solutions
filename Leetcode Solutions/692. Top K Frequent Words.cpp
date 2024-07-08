/*Sol : 
=> Brute Force - [TIME - O(NlogN) SPACE - O(N)]
    - Store dist of all points in array mapped to their idx & sort the 
    array & return first K elements

=> BEST APPROACH - Heap Sort - [TIME - O(NlogK) SPACE - O(K)]
    - Use max heap to store all elements & find K closest.
   
BEST APPROACH : [If asked to optimize more]
=> Quick Select : [TIME - O(N) SPACE - O(N)]
    - Firstly, we select a pivot (last element of array) then traverse the
    array & swap all elements one by one & find a position for pivot such
    that elements before pivot are < pivot & element after pivot are > pivot
    - We'll stop our search if pivot idx == k, if pivot_idx > k then we
    reduce search space to second half of array, if pivot_idx < k then we
    reduce search space to first half of array.
    - Once we find pivot with idx == k, then we'll return element of first
    half of array in sorted manner.

NOTE : The avg time complexity of Quick select is O(N), since we're reducing
search space after every pivot is placed, but in worst cast time complexity
is O(N^2) i.e in case of constantly bad chosen pivot, the search space is
not divided in half at each step, it just become one element less this leads
to O(N^2)
*/
struct compare{
    bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(int i=0;i<words.size();i++) freq[words[i]]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        
        for(auto it : freq){
            pq.push({it.second,it.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//QUICK SELECT
//TIME - O(N) 
//SPACE - O(N) -> for using duplicate dist array
    public int[][] kClosest(vector<int>nums, int K) {
        int numsLen = nums.length;
        
        quickSelect(K, nums, 0, numsLen - 1);
        
        // Get first K
        int[] result = new int[K];
        for (int i = 0; i < K; i++) result[i] = nums[i];

        return result;
    }
    
    // Find smallest K distances
    private void quickSelect(int K, vector<int>nums, int start, int end) {
        if (start >= end) return;
        
        // Choose the element at start as pivot.
        int pivot = nums[start];
        // Put pivot into right position wall
        int wall = end + 1;
        for (int i = end; i > start; i--) {
            if (nums[i] >= pivot) {
                wall--;
                swap(nums[wall], nums[i]);
            }
        }
        wall--;
        swap(nums[wall], nums[start]);
        
        if (wall + 1 == K) return;
        else if (wall + 1 < K) quickSelect(K, nums, wall + 1, end);
        else quickSelect(K, nums, start, wall - 1);
    }