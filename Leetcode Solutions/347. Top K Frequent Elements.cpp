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
    that elements before pivot are <pivot & element after pivot are >pivot
    - Now our search space also get's reduce, so we need to find pivot
    whose position is k

NOTE : The avg time complexity of Quick select is O(N), since we're reducing
search space after every pivot is placed, but in worst cast time complexity
is O(N^2) i.e in case of constantly bas chosen pivot, the search space is
not divided in half at each step, it just become one element less this leads
to O(N^2)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        unordered_map<int,int>freq;
        
        for(int i=0;i<nums.size();i++) freq[nums[i]]++;
        
        for(auto it : freq){
            min_heap.push({it.second,it.first});
            if(min_heap.size()>k) min_heap.pop();
        }
        
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return ans;
    }
};


//QUICK SELECT
//TIME - O(N) SPACE - O(N)
Map<Integer, Integer> map;

vector<int> topKFrequent(vector<int> nums, int k) {
    map = new HashMap<>();
    for (int num : nums) {
        map.put(num, map.getOrDefault(num, 0) + 1);
    }
    vector<int> elements = new int[map.size()];
    int i = 0;
    for (int num : map.keySet()) {
        elements[i] = num;
        i++;
    }

    int n = elements.length;
    // here n - k so that n - k elements are at the start of the array and
    // the top k elements are pushed at the end of the array after quickselect
    quickSelect(elements, 0, n - 1, n - k);
    // from n - k to n as the top k elements are at the end of the array
    return Arrays.copyOfRange(elements, n - k, n);
}

// unlike quickSort, quickSelect traverses into one side – the side with the element it is searching for
void quickSelect(vector<int> a, int start, int end, int k) {
    while (start < end) {
        int pIndex = partition(a, start, end);
        if (pIndex < k) start = pIndex + 1;
        else if (pIndex > k) end = pIndex - 1;
        else return;
    }
}

// partition function is the same as in quick sort
int partition(vector<int> a, int start, int end) {
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (map.get(a[i]) <= map.get(pivot)) {
            swap(a, i, pIndex);
            pIndex++;
        }
    }
    swap(a, pIndex, end);
    return pIndex;
}

void swap(vector<int> a, int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}