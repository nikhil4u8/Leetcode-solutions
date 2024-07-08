#define ppi pair<int,pair<int,int>> 
class Solution {
public:
    //Time - O(KlogK)  Space - O(K)
    //Intution - Fixing the first array and moving in second array
    //When we pop out element from queue then we have 2 option -> 
    //to push (i+1,j)/(i,j+1) element, since we already have (i+1,j) in queue 
    //so we push (i,j+1) element in queue
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        
        for(int i=0;i<k && i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0],{i,0}});   
        }
        
        while(k-- && !pq.empty()){
            auto temp = pq.top();
            int i = temp.second.first;
            int j = temp.second.second;
            ans.push_back({nums1[i],nums2[j]});
            
            pq.pop();
            if(j+1<nums2.size()) pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        
        return ans;
    }
};