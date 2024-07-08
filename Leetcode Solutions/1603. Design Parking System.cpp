class ParkingSystem {
public:
//TIME - O(1) SPACE - O(1)
    int one,two,three;
    ParkingSystem(int big, int medium, int small) {
        one = big;
        two = medium;
        three = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            one--;
            return one>=0;
        }
        if(carType == 2){
            two--;
            return two>=0;
        }
        if(carType == 3){
            three--;
            return three>=0;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */