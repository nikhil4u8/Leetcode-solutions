class Solution {
public:
//Sorting capacity n rocks by difference between them ->
//which means sorting by less number of rocks needed to reach
//capacity. Then adding additonal rocks and incrementing ans until additonal rock become 0
//TIME - O(NlogN) SPACE - O(1)
    void pairsort(vector<int>&a, vector<int>&b, int n)
    {
        vector<pair<int, pair<int, int>>>pairt(n);
        // Storing the respective array
        // elements in pairs.
        for (int i = 0; i < n; i++){
            pairt[i].first = abs(a[i]-b[i]);
            pairt[i].second.first = b[i];
            pairt[i].second.second = a[i];
        }
    
        // Sorting the pair array.
        sort(pairt.begin(), pairt.end());
        
        // Modifying original arrays
        for (int i = 0; i < n; i++){
            b[i] = pairt[i].second.first;
            a[i] = pairt[i].second.second;
        }
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        pairsort(capacity, rocks, n);

        int ans = 0;
        for(int i=0;i<n;i++){
            if(capacity[i] == rocks[i]){
                ans++;
                continue;
            }

            if(additionalRocks >= abs(capacity[i] - rocks[i])){
                ans++;
                additionalRocks -= abs(capacity[i] - rocks[i]);
            }
        }

        return ans;
    }
};