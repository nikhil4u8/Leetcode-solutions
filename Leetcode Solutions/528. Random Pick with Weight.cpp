/*
Ques to ask :
    - Can the weight be -ve / 0 ?
    - If -ve / 0 weight is there, then what if sum became 0, then how to
    find probablity?
    
Sol : 
    - We can simply find array sum, and find a random number b/w 0 - sum, 
        - Expand the weight array i.e wt = [1,5,3] = [1,1,1,1,1,1,1,1,1]
        now traverse this array to find where random num belongs to, here
        idx will be returned according to weight
        - Maintain a prefix sum array find where that sum falls in prefix 
        array using either linear search or binary search
            - Linear search : TIME - O(N) O(N) SPACE - O(N) O(1)
            - Binary Search : TIME - O(N) O(logN) SPACE - O(N) O(1)

Follow up : Implement UpdateWeightArray fun, and adjust pick index accordingly
*/
class Solution {
public:
    vector<int>prefix_sum;
    int sum = 0;
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            sum += w[i];
            prefix_sum.push_back(sum);
        }
    }
    //Ex- Arr - [1,5,2] -> construct a array -> [0,1,1,1,1,1,2] -> choose one index among these 
    //and return value at that index....this method not feasible for big numbers
    //Instead we construct a sum array and choose number b/w [1,sum] and find that num in 
    //prefix_sum and return that index
    //TIME - O(N)
    int pickIndex() {
        float random_index = (float)rand()/RAND_MAX;
        float target_num = random_index*prefix_sum.back();
        
        //Instead of this use binary search for O(logN) time
        for(int i=0;i<prefix_sum.size();i++){
            if(target_num<(float)prefix_sum[i]) return i;
        }
        
        return prefix_sum.size()-1;
    }
    //TIME - O(logN) -> Binary Search
    int pickIndex() {
        int num = rand()%sum + 1;

        int start = 0, end = weight.size()-1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(weight[mid] >= num) end = mid;
            else start = mid+1;
        }

        return end;
    }
    //TIME - O(N) -> Linear Search
    int pickIndex() {
        int random_index = (rand()%sum) + 1;
        int num = -1;
        //Instead of this use binary search for O(logN) time
        for(int i=0;i<prefix_sum.size();i++){
            if(random_index <= prefix_sum[i]) return i;
        }
        
        return prefix_sum.size()-1;
    }
};

***FOLLOW-UP
    1. if we updated the weight array use segment tree to update

class Solution {
	int[] nums;
	int[] bits;
	Random rand;

	public Solution(int[] w) {
		bits = new int[w.length + 1];
		nums = new int[w.length];
		rand = new Random();
		for (int i = 0; i < w.length; i++) {
			update(i, w[i]);
		}
	}

	public void update(int i, int val) {
		int diff = val - nums[i];
                nums[i] = val;
		for (int j = i + 1; j < bits.length; j += j & -j) {
			bits[j] += diff;
		}
	}

	public int getSum(int i) {
		int result = 0;
		for (int j = i + 1; j > 0; j -= j & -j) {
			result += bits[j];
		}
		return result;
	}

	public int pickIndex() {
		int x = rand.nextInt(getSum(nums.length - 1));
		int l = 0, r = nums.length - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (getSum(m) <= x) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		return l;
	}
} 