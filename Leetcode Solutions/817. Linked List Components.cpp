class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]] = i;
        
        int count = mp.size();
        
        while(head && head->next){
            if(mp.find(head->val) != mp.end() && mp.find(head->next->val) != mp.end())
                count--;
            head = head->next;
        }
        
        return count;
    }
};