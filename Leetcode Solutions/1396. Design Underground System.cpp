/*
TIME - O(1) O(1) O(1) | SPACE - O(P+S^2) 
P -> no of passenger making journey concurrently during peak time 
S -> no of station on network

Ques to ask / Edge cases :-
    - Is there any invalid case like someone didn't checkOut ever?
    - What is checkIn / checkOut station for a user is same?
    - Do we need to be really accurate while returning avg or there can be some error expected too?
    - Do we need to treat from 'station1 -> station2' different from 'station2 -> station1'?
*/
/*
Issue with GetAverageTime function :- / Ask these too :-
1. If total number of users = 0
2. If the sum of all the time overflow -> sol is to store the average 
instead of total sum of time, but this will increase inaccuracy.
*/

class UndergroundSystem {
public:
    //id -> {starting_station,time_of_arrival_at_starting_station}
    unordered_map<int, pair<string, int>> store;
    //starting_station+'-'+ending_station as a key is mapped to
//-> {time_spend_b/w_starting_and_ending_station,total_user_on_same_path}
    unordered_map<string, pair<int, int>> getTime;
    //instead of getTime we can also use -> unordered_map<string,unordered_map<string,pair<int,int>>>
    UndergroundSystem() {
        store = unordered_map<int,pair<string,int>>();
        getTime = unordered_map<string,pair<int,int>>();
    }
    
    void checkIn(int id, string stationName, int t) {
        store[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string dest = store[id].first+'-'+stationName;
        
        int time = t-store[id].second;
        getTime[dest].first += time;
        getTime[dest].second++;
        
        store.remove(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string dest = startStation+'-'+endStation;
        if(getTime.find(dest) == getTime.end()) return -1;
        return (double)getTime[dest].first/getTime[dest].second;
    }
};