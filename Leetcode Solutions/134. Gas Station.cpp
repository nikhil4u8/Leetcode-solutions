class Solution {
public:
//TIME - O(N) SPACE - O(1)
/*
Every time a fail happens, accumulate the amount of gas that is 
needed to overcome the fail. After looping through the stations, 
if the gas left is more than gas needed, then we have a solution, 
otherwise not.
*/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_gas_left = 0, required_gas = 0, idx = 0;

        for(int i=0;i<gas.size();i++){
            curr_gas_left += gas[i] - cost[i];
            if(curr_gas_left < 0){
                idx = i+1;
                required_gas += curr_gas_left;
                curr_gas_left = 0;
            }
        }

        if(curr_gas_left + required_gas >= 0) return idx;
        return -1;
    }
};