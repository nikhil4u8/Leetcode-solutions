class Solution {
public:
//     //TIME - O(N) SPACE - O(N)
//     //Create a list of number who are not in blacklist and generate a random number among them
//     vector<int>num;
//     Solution(int n, vector<int>& blacklist) {
//         sort(blacklist.begin(), blacklist.end());
//         int j = 0;
        
//         for(int i=0;i<n;i++){
//             if(j < blacklist.size() && blacklist[j] == i) j++;
//             else num.push_back(i);
//         }
//     }
//     int pick() {
//         int size = num.size();
//         int random_num = rand()%size;
//         return num[random_num];
//     }
//     //TIME - O(BlogB) O(N-B) SPACE - O(B)
//     //Linear search can be converted to binary search to reduce complexity -> O(BlogB) O(log(N-B))
//     vector<int>black_list;
//     int limit;
//     Solution(int n, vector<int>& blacklist) {
//         sort(blacklist.begin(), blacklist.end());
//         black_list = blacklist;
//         limit = n - blacklist.size();
//     }
//     int pick() {
//         int random_num = rand()%limit + 1;
//         if(black_list.size() == 0) return random_num - 1;
        
//         int total = black_list[0];
//         if(total >= random_num) return random_num - 1;
        
//         for(int i=1;i<black_list.size();i++){
//             total += black_list[i] - black_list[i-1] - 1;
//             if(total >= random_num)  return black_list[i-1] + (total - random_num) + 1;
//         }
        
//         return black_list[black_list.size()-1] + (random_num-total);
//     }
    //We can remap all the blacklist element to the last element then find random element in first N-B element, if blacklist element comes then return remapped element else return random element
    unordered_map<int, int>mp;
    int limit;
    Solution(int n, vector<int>& blacklist) {
        limit = n - blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        int j = n-1;
        for(int i=0;i<blacklist.size();i++) mp[blacklist[i]] = -1;
        for(int i=0;i<blacklist.size();i++){ 
            //if(blacklist[i] == j) continue;
            
            while(mp.find(j) != mp.end()) j--;
            mp[blacklist[i]] = j--;
        }
    }
    int pick() {
        int random_num = rand()%limit;//cout<<mp[0]<<" "<<mp[2]<<"\n";
        if(mp.find(random_num) == mp.end()) return random_num;
        return mp[random_num];
    }
};
