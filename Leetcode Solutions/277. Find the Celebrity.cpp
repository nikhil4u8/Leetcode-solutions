
/*
Ques to ask :
    - We Can't have multiple celebrity, right?
    - Is there a limit to number of call made to knows() API?

Sol :
=> Brute force : Checking for every person - [TIME - O(N^2) SPACE - O(1)]
    - Loop for every person (i) as a potential celebrity, so run 2 for 
    loop to check if for all pairs(i, j) -> knows(i, j) == 0 && 
    knows(j, i) == 1. If condition satisfied then person i is celebrity. 
    Else move to next person (i+1)


BEST APPROACH
=> Eliminating people - [TIME - O(N) SPACE - O(1)]
    - Instead of checking for every person, we'll maintain a potential_celebrity 
    variable and eliminate all but one of people as celebrity & in end we 
    can run brute-force verification on potential_celeb to check it it's 
    a actual celeb.
    - To eliminiate people we use knows API. Let's say we call knows(a, b) 
    [a!=b]
        - Case 1 : knows(a, b) is False. This means b can't be celebrity 
        since 'a' doesn't know them.
        - Case 2 : knows(a, b) is True. This means a can't be celebrity 
        since 'b' doesn't know them.
    In both the cases, we can eliminate 1 person.
    - Let's initialize potential_candidate = 0, and start comparing it 
    with other people and eliminate one of them (as per above cases) & 
    upgrade potential_candidate & move to another candidate & compare 
    again to find winner potential_celeb & do this until we traverse 
    whole array. 


NOTE : To find potential candidate we're not comparing every elements 
before potential_celeb, becoz jab unka chance tha potential_Celeb banne 
ka tab vo loose kar gaye kisi aur celeb ke liye, toh current celeb ke 
liye bhi loose hi karenge.
*/
class Solution {
public:
    int findCelebrity(int n) {
        //person_1 -> {person_2, knows / not knows}
        //used for caching relationship, used to reduce API calls while 
        //verifying potential_celeb is actual celeb or not
        unordered_map<int, unordered_map<int, bool>>cache;
        //start with picking any person as a celeb
        int potential_celeb = 0;

        //narrowing down to one potential celeb
        for(int i=0;i<n;i++){
            //Do not compare a person to themselves
            if(i == potential_celeb) continue;
            //Compare and eliminate one that is not celebrity.
            //If potential_celeb knows "i", then it can't be celeb
            //though there are chances that "i" can be celeb
            if(knows(potential_celeb, i)){
                potential_celeb = i;
                cache[potential_celeb][i] = true;
            }
        }

        // Check if the final candidate is the celebrity
        for(int i=0;i<n;i++){
            if(i == potential_celeb) continue;
            //If i doesn't know potential_celeb then potential_celeb is 
            //not actual celeb
            if((cache[i].find(potential_celeb) != cache[i].end() && 
            !cache[i][potential_celeb]) || !knows(i, potential_celeb)) return -1;

            //If potential_celeb knows i, then it can't be actual celeb.
            if((cache[potential_celeb].find(i) != cache[potential_celeb].end() && 
            cache[potential_celeb][i]) || knows(potential_celeb, i)) return -1;
        }

        return potential_celeb;
    }
};