class Solution {
public:
    //Approach-1
    //Brute force
    //pick the top milestones(if it's same as last then pick top second) and reduce 1 milestone 
    //and put them back. 
    //Time - NlogN*sum(milestone array) 
    long long numberOfWeeks(vector<int>& milestones) {
        priority_queue<pair<int,int>>pq;
        
        //Time - O(NlogN)
        for(int i=0;i<milestones.size();i++){
            pq.push({milestones[i],i});
        }
        
        int ans = 0,last=-1;
        //In worst case it will run for sum(milestone array)*(NlogN)
        while(!pq.empty()){
            if(pq.top().second!=last){
                ans++;
                auto temp = pq.top();
                last = temp.second;
                pq.pop();
                if(temp.first>1) pq.push({temp.first-1,temp.second});
            }else{
                auto temp = pq.top();
                pq.pop();
                if(pq.empty()) return ans;
                ans++;
                auto temp2 = pq.top();
                last = temp2.second;
                pq.pop();
                if(temp2.first>1) pq.push({temp2.first-1,temp2.second});
                pq.push(temp);
            }
        }
        
        return ans;
    }
    //Approach
    //Problem lies with max freq no, if it get placed then other will automatically get placed,
    //like "BCD_BCD_BCD" if the element who's frequency is more is placed first and then other no 
    //are placed inside the gap of more freq number. 
    //Total gap = maxi_freq - 1, if sum of other ele is less than gap then atleast one gap 
    //will remain unfilled so 2 same no will appear consecutively
    //Ex-> [5,2,1] -> 5_5_5_5_5 | gap = 4, no_filling_gap = 2+1=3 -> one gap will remain unfilled
    //and if no_filling_gap
    //Time - O(N)  Space - O(1)
    long long numberOfWeeks(vector<int>& milestones) {
        long long int no_filled_gap = 0,no_of_gap = 0,total_freq=0,maxi_freq=INT_MIN;
        
        for(int i=0;i<milestones.size();i++){
            maxi_freq = max(maxi_freq,(long long)milestones[i]);
            total_freq += milestones[i];
        }
        
        no_filled_gap = total_freq - maxi;
        no_of_gap = maxi-1;
        
        //then every element get placed
        if(no_filled_gap >= no_of_gap) return total_freq;
        return 2*no_filled_gap + 1;
    }
};