class Solution {
public:
//First Approach (Wrong Approach)
//b/w L and R, find max and min element which will work as starting n ending element of AP,
//(r-l+1)*(mini+maxi)/2 => sum of AP, and equate this sum to prefix_sum[r+1]-prefix_sum[l],if matched
//then it is Arthematic sequence

//Right one
    //TIME - O(M*N*logN) ->M is no of query and n is size of temp  Space - O(N)
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>ans(n,false);
        
        for(int i=0;i<n;i++){
            if(r[i]-l[i]<=1){
                ans[i] = true;
                continue;
            }
            
            vector<int>temp;
            temp.assign(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(temp.begin(),temp.end());
            
            bool flag = true;
            int diff = temp[1] - temp[0];
            for(int j=2;j<temp.size();j++){
                if(temp[j]-temp[j-1] != diff) flag = false;
            }
            
            ans[i] = flag;
        }
        
        return ans;
    }
};