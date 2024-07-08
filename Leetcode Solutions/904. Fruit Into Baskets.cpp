/*Loop all fruit c in tree,
Note that a and b are the last two different types of fruit that we met,
c is the current fruit type,
so it's something like "....aaabbbc..."

Case 1 c == b:
fruit c already in the basket,
and it's same as the last type of fruit
cur += 1
count_b += 1

Case 2 c == a:
fruit c already in the basket,
but it's not same as the last type of fruit
cur += 1
count_b = 1
a = b, b = c

Case 3 c != b && c!= a:
fruit c not in the basket,
cur = count_b + 1
count_b = 1
a = b, b = c

Of course, in each turn we need to update res = max(res, cur) */

//TIME - O(N) SPACE - O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=-1,second=-1, first_count = 0, second_count = 0,ans = 0, last_first_count = 0, last_second_count = 0;

        for(int i=0;i<fruits.size();i++){
            if(first == -1 || first == fruits[i]){
                last_second_count = 0;
                last_first_count++;
                first_count++;
                if(first == -1) first = fruits[i];
            }else if(second == -1 || second == fruits[i]){
                second_count++;
                last_second_count++;
                last_first_count = 0;
                if(second == -1) second = fruits[i];
            }else{
                ans = max(ans, first_count + second_count);

                if(second == fruits[i-1]){
                    first = second;
                    first_count = last_second_count;
                }else first_count = last_first_count;

                second = fruits[i];
                last_second_count = 1;
                second_count = 1;
                last_first_count = 0;
            }
        }
        
        ans=max(ans,first_count+second_count);
        return ans;
    }
};