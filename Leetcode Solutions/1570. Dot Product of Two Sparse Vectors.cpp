/*
Ques to ask :
    - What is a sparse vector?
    - How to access elements in a sparse vector?
    - Can we have negative value?
    - Are both vector sparse? or just one? And if only one then which one?

Sol :
=> Brute force : Simple vector multiplication

BEST APPROACH : ONLY USE WHEN BOTH VECTOR ARE SPARSE
=> 2 Pointer : Compress sparse vector using map / vector
-> [TIME - O(len(nums)) O(L1) SPACE - O(L1)]
-> L1 : non zero element in nums
    - It's inefficient to store a sparse vector as 1-D array, instead for 
    both vector we can store all non zero values & their indexes in a map 
    / vector
    - Traverse the smaller map & compute dot product. 

BEST APPROACH : ONLY USE WHEN ONE VECTOR IS DENSE AND LONG
=> Binary Search using Array (Index, Val) pair - 
-> [TIME - O(len(nums)), O(min(L1,L2)*log(max(L1,L2))) SPACE - O(L1+L2)]
-> L1 : non zero element in vec1
-> L2 : non zero element in vec2
    - Use Binary search to find index of vec1, in vec2 & multiply both.
    - This approach is better than prev one becoz in ques it's written 
    that you should store the sparse vector efficiently, so it's better 
    to not save the whole array as it is.

Follow up :
    - Can you do it without using Hashmap?
        -> Yes, use array instead & use 2 pointer / binary search.

    - What if only one vector is sparse and the other is full of non-zero 
    values?
        -> Use Binary Search : we'll still use idx_val pair to form new 
        vector, but instead of using 2 pointer approach, pick up the 
        vector which is sparse & do binary search to get matching idx in 
        second (non sparse) vector. [TIME - O(KlogN) SPACE - O(N)] where 
        K : non zero element in sparse vector & N : non zero element in 
        non sparse vector

    - Instead of vectors being sparse, he asked me if the vectors are a 
    compressed version as follows and asked me to calculate the dot 
    product 
    [1,1,1,3,3,3,3,6,6]
    [0:3] 1
    [3:7] 3
    [7:9] 6
        -> Ref - 1868. Product of Two Run-Length Encoded Arrays

IMP : If interviewer says :
    - When to use Binary Search over 2 pointer?
    (ONLY WHEN ONE IS SPARSE AND OTHER IS DENSE)
        => If both vector have less amount of non zero element then using 
        2 pointer make sense, since it's TC - O(L1+L2), but when we've a 
        non sparse but very long vector & another highly sparse vector 
        (very less non zero elements), then using binary search in non 
        sparse vector makes sense rather than traversing in both vector 
        using 2 pointer, since it's TC - O(min(L1,L2)*log(max(L1,L2))) << 
        O(L1+L2)

    - Why use Array instead of hashmap? 
    (ONLY WHEN ONE IS SPARSE AND OTHER IS DENSE)
        => 1. In array, we store elements in continous memory, whenever 
        there is a cache miss, then OS interally loads next block of 
        memory to RAM & uses it, this results in lot less cache miss, 
        while in hash map, elements aren't place one after another in 
        memory, so we can expect large number of cache miss resulting in 
        higher overall memory access time & application run time.
           2. Since sparse vector can have large size, so high chances of 
        hash collision when we hit memory allocation limit (when the hash 
        table load factor exceeds the pre-defined load factor i.e 0.75), 
        the hash map will resize and will rehash everything & b/w the 
        resizing & collision, the hash map approach isn't going to scale 
        very well for very large vectors and then the amortized time 
        complexity for add/access in hash map becomes O(n) instead of O(1) 
        as linked lists for collisions get longer. Also, we've to 
        calculate hash value which takes overhead. Also, using array, we 
        don't have to worry about collision / resizing
*/
class SparseVector {
public:
//BEST SOLUTION
//USING Array + 2 pointer
//ONLY USE WHEN BOTH VECTOR ARE SPARSE
//TIME - O(len(nums)) O(L1+L2) SPACE - O(L1+L2)
    vector<<vector<int>> list;
    
    SparseVector(vector<int>&nums) {
        for(int i=0; i<nums.length; i++){
            if(nums[i] != 0) list.push_back({i, nums[i]});
        }
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int dotProduct = 0;
        int p = 0, q = 0;
        
        while(p < list.size() && q < vec.list.size()) {
            if(list.get(p)[0] == vec.list.get(q)[0]){
                dotProduct += list.get(p)[1] * vec.list.get(q)[1];
                p++;
                q++;
            }
            else if(list.get(p)[0] < vec.list.get(q)[0]) p++;
            else q++;
        }
        return dotProduct;
    }
//USING VECTOR + BINARY SEARCH
//Use only when one vector is long and dense & another is highly sparse
//TIME - O(len(nums)) O(min(L1,L2)*log(max(L1,L2))) SPACE - O(L1+L2)
    vector<pair<int, int>> pairs;
    int binary_search(int index, int left, int right) {
        while(left <= right) {
            int mid = left + (right - left)/2;
            if (pairs[mid].first == index) return pairs[mid].second;
            else if (pairs[mid].first < index) left = mid + 1;
            else right = mid - 1;
        }
        return 0;
    }    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) 
                pairs.push_back({i, nums[i]});
        }
    }
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        if (vec.pairs.size() > pairs.size()) {
            for (int i = 0; i < pairs.size(); ++i) {
                int key = pairs[i].first;
                int val = pairs[i].second;
                sum += val * vec.binary_search(key, 0, vec.pairs.size()-1);
            }
        } else {
            for (int i = 0; i < vec.pairs.size(); ++i) {
                int key = vec.pairs[i].first;
                int val = vec.pairs[i].second;

                sum += val * binary_search(key, 0, pairs.size()-1);
            }
        } 
        
        return sum;
    }
};