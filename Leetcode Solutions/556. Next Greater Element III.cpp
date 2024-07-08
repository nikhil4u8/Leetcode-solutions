/*
Ques to ask :
    - What if next permutation is not possible?
    - Do we've negative or double digit number in array?

Sol :
=> Brute Force - [TIME - O(N!) SPACE - O(N)]
    - Generate every possible permutation of list and find permutation 
    which is greater than num


=> SAY THIS BEFORE PROCEEDING FURTHER
    - General trends - 123 -> 124 -> 129 -> 130 -> 131 -> 199 -> 200 i.e
    incrementing ones until we reach end (i.e 9), then move to incrementing 
    tenth position(& reset all digits after tenth position) then to 
    hundredth position.
    - This happens when you're allowed to use all digits from 0-9, but 
    in this case we're not allowed to use all digits.
    - So we can't increment digits here rather we've to swap digits & 
    while swapping we've to considering that after swapping we obtain a 
    bigger num i.e num at lower position must have higher val than num 
    present at higher position
    

=> Swapping Lower with higher num - [TIME - O(N^2) SPACE - O(1)]
    - Fix one idx, then traverse string after that index & find the 
    smallest number which is greater than nums[i] to swap with it. 
    - If there exist such num, then swap it & sort string from (i+1, end) & 
    return
    - If there doesn't exist such num, then decrement ith pointer & 
    repeat step 2


BEST APPROACH
=> Array + Two Pointer - [TIME - O(N) SPACE - O(1)]
    - Instead of fixing each idx & traversing in str (i+1, end) & finding 
    smallest num greater than nums[i]. We're traversing through same str 
    again & again.
    - Rather, traverse backwards & keep track of max num from [i+1...n] idx
    & for every ith idx, if it's < max_element then there exist some num
    from [i+1...n] which is smallest num greater than nums[i].
    - So, traverse from (i+1, end) & find smallest num which is greater 
    than pivot & swap both & sort (i+1, end) & return

Follow up :
    - Find previous permutation

Similar Ques : Ref 31. Next permutation
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        for(int i=str.length()-2;i>=0;i--){
            if(str[i] < str[i+1]){
                int mini = INT_MAX;
                int idx = 0;

                for(int j=i+1;j<str.length();j++){
                    if(str[j] > str[i]){
                        mini = min(mini, str[j] - '0');
                        idx = j;
                    }
                }

                swap(str[i], str[idx]);
                sort(str.begin() + i + 1, str.end());
                break;
            }
        }

        long long int tempAns = stol(str);
        if(tempAns == n || tempAns > INT_MAX || tempAns < INT_MIN) return -1;
        return tempAns;
    }
};