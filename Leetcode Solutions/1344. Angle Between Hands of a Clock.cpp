//TIME - O(1) SPACE - O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {
//         60 min - 360 deg
//         1 min - 6 degree
//         min hand - min*6 deg
//         30 deg - 60 min hr hand
//         0.5 deg - 1 min hr hand
//         hour hand - 5*hour*6 + 0.5*min
            
//         total = min*6 - 30*hour - min*0.5
        
        if(hour >= 12) hour -= 12;
        return min({abs((double)minutes*5.5 - (double)30*hour), 
                   360 - (double)minutes*6 + (double)30*hour + (double)0.5*minutes,
                   360 - (double)(30*hour + 0.5*minutes) + (double)minutes*6});
    }
};