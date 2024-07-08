class Solution {
public:
//We always put the next heaviest person on the boat, plus the lightest person 
//if combined weight is within the limit.
//TIME - O(NlogN) SPACE - O(1)
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i = 0, j = people.size()-1, ans = 0;

        while(i <= j){
            int sum = people[j--];
            if(sum + people[i] <= limit) sum += people[i++];
            ans++;
        }

        return ans;
    }
};