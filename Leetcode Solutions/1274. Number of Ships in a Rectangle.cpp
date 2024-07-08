/*
Desc:- 
    - At most 10 ships can be in a rectangle
    - Max 400 calls to hasShip can be made
    - Return true if there is atleast 1 ship in rectangle
    - ship will be present at interger points only

Ques to ask:-
    - What is the range of cordinate provided?
    - is there any restriction to number of calls made to hasShip fun?
    - Can topRight == bottomLeft?
    - Is ship present on the boundary of plane as well?

Ques interviewer ask:-
    - Why divide it into 4 parts? Why not 2/8?
    - Why not allowing overlap?

Sol:-
    - Finding ship on every interger point
    - Eliminate places where ship might not be present

Edge Cases:- 
    - Ship is present on the boundary (overlapping case).
    - At every point in square there is a ship and we don't have enough 
    calls to make to hasShips?


TIME - O(S*log4(N*M))
SPACE - O(1) | recursive tree -> O(log2(max(N, M)))

N/M -> max value of cordinate
S -> Max no of possible ships (10 in this case)

log_4(N*M) [in this case log4(1000000)] = 10 so basically if we divide our 
rectanle into 4 parts, the recursion tree could be AT MOST be 10 levels down, 
and since we've only 10 ships so at max we've to iterate for 10*log4(1000000)
i.e S*log4(N*M)
*/
class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if(!(topRight[0] >= bottomLeft[0] && topRight[1] >= bottomLeft[1]))
            return 0;

        if(!sea.hasShips(topRight, bottomLeft)) return 0;

        if(topRight == bottomLeft) return 1;

        int mid_x = (topRight[0] + bottomLeft[0])/2;
        int mid_y = (topRight[1] + bottomLeft[1])/2;

        return countShips(sea, {mid_x, mid_y}, bottomLeft) +    
               countShips(sea, topRight, {mid_x+1, mid_y+1}) + 
               countShips(sea, {mid_x, topRight[1]}, {bottomLeft[0], mid_y+1}) +
               countShips(sea, {topRight[0], mid_y}, {mid_x+1, bottomLeft[1]});
    }
};

/*
Sol to interviewe ques:-
    - Why divide it into 4 parts? Why not 2/8?
        => Dividing into 4 makes it easy to recurse, ultimately we've to divide 
        until we reach a single point, if we're able to do that with 8 then 
        that split is also fine. 
        If you've 2, you need to figure out which way to split (vertical or horizontal) 
        at every recursion, even if you split it horizontal once then vertical, 
        then also at second recrusion it'll form a quadtree i.e splited into 4.

    - Why not allowing overlap in countShips call?
        => If in case a ship is present at boundary, then overlap call will lead 
        to counting that ship multiple time.
*/