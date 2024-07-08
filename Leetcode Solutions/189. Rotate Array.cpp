class Solution {
public:
    //TIME - O(N)  SPACE - O(N)
    void rotate(vector<int>& nums, int k) {
        vector<int>temp = nums;
        int n = nums.size();
        k = k%n;
        for(int i=0;i<n;i++)  nums[i] = temp[(n-k+i)%n];
    }
    //TIME - O(N) SPACE - O(1)
    //Nums - [1,2,3,4,5,6,7] k=3
    //step1 -> [7,6,5,4,3,2,1]
    //step2 -> [5,6,7,1,2,3,4]
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    //TIME - O(N)  SPACE - O(1)
    //IN-PLACE 
    //we pick a number and then place it at a gap of k then pick another num at i+k index and place it after k gap, repeat this cycle until you reach the index at which you started, then pick i+1 index num
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return;
        k = k%n;
        
        int i=0,start=0,temp=nums[0],count=0;
        while(start<k){
            int t = nums[(i+k)%n];
            nums[(i+k)%n] = temp;
            temp = t;
            i = (i+k)%n;
            count++;
            
            if(i==start){
                if(count==n) break;
                start++;
                i=start;
                temp = nums[start];
            }
        }
    }
};