/*
Ques to ask :
    - If x sended friend req to y, then does it means that y also sended 
    frnd req to x?
    - Can a person send frnd req to themselves?
    - Is array sorted?
    - Is there any limit to how much can age go upto?

Sol :
=> Finding all pairs : [TIME - O(N^2) SPACE - O(1)]
    - Run 2 FOR loop & Create all possible pairs & check which pair 
    satisfy the criteria and include that pair. Case when ages of 2 
    people are same are dealth differently.

BEST APPROACH [If age limit is not given]
=> Using Binary Search : [TIME - O(NlogN) SPACE - O(1)]
    - When we simply the conditions give we find that for every person 
    there's a range of ages he can send frnd req to :
        Condition 1: age[y] <= age[x]
        Condition 2 : age[y] > age[x]/2 + 7 
        Combined Condition: age[y] should belong to (age[x]/2 + 7, age[x]]
    - Sort the array & traverse from L to R & for each person, calculate 
    the expected range, and use binary search to find the number of 
    elements in ages[] that sit in that range.
    - For cases with equal age, check if age[x] > age[x]/2 + 7 (i.e 
    age[x] >= 15, satisfying 2nd condition), if yes, then find how many 
    elements have equal age before idx x (say j) & now x can sent frnd 
    req to every one of them, so add 2*j (2 since y can also send req to 
    x, if x == y) to ans.


BEST APPROACH [If age limit is given]
=> Using Linear search : [TIME - O(N) SPACE - O(121)]
    - Since age range is limited to [1...120], so instead of binary search 
    we can count number of people of each age & store in a array & use it 
    to count frnd req.
    - People with age<15,can't make frnd req to anyone due to condition 2
    - From age 15 people can make req to same age people, so we'll find 
    how many elements belong to the range of (x/2+7, x] & multiply it with 
    agesFreq[i] since for people with same this count will be same & add 
    it to our answer.
    - Now, since people can't send frnd req to themselves, so subtract 
    agesFreq[i]from result.

Edge case :
    - When age/2 + 7 > age, so x can't send req to anyone
    - When age[x] == age[y]
*/
class Solution {
public:
//BEST APPROACH [If age limit is given]
//TIME - O(N) SPACE - O(121)
    int numFriendRequests(vector<int>& ages) {
        vector<int>ageLessThanOrEqualToi(121, 0);
        vector<int>agesFreq(121, 0);
        //store freq of people with age = i in ith idx
        for(int i=0;i<ages.size();i++) agesFreq[ages[i]]++;
        //finding count of how many people with age <= i
        for(int i=1;i<121;i++) 
            ageLessThanOrEqualToi[i]=ageLessThanOrEqualToi[i-1] + agesFreq[i];

        int frndReq = 0;
        for(int i=0;i<121;i++){
            //If Condition 2 is not met or no person present in ages array
            //with age = i then skip
            if(i <= i/2 + 7 || agesFreq[i] == 0) continue;
            int y = i/2 + 7;

            //freq of people belonging in range (i/2+7, i]
            int count = ageLessThanOrEqualToi[i] - ageLessThanOrEqualToi[y];
            //for all people with same age, no of frnd req sent = count
            //but here sending frnd req to self is also counted so 
            //subtracting that.
            frndReq += count*agesFreq[i] - agesFreq[i];
        }

        return frndReq;
    }


//BEST APPROACH [If age limit is not given]
//TIME - O(NlogN) SPACE - O(1)
    int idxOfElement(vector<int>&ages, int end, int target){
        int start = 0;
        while(start < end){
            int mid = start + (end - start)/2;

            if(ages[mid] >= target) end = mid;
            else start = mid+1;
        }

        if(ages[start] < target) start++;
        return start;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int frndReq = 0;

        for(int i=1;i<ages.size();i++){
            int y = ages[i]/2 + 8;
            int x = ages[i];

            //For FB interview, if x>100 then y>=100
            //if(x>100) y = min(100, y);

            int countX = 0, j = i;
            //finding idx when age of people is different than age[i]
            while(j--){
                if(ages[j] == x) countX++;
                else break;
            }
            //Binary search from [0, j] to find idx of element whose 
            //age > x/2+7
            if(j != -1) frndReq += j + 1 - idxOfElement(ages, j, y);
            //frnd req among people of same age.
            if(x >= y) frndReq += 2*(i - j - 1);
        }

        return frndReq;
    }
};