class ParkingSystem {
public:
  vector<int> parking;
    
    ParkingSystem(int big, int medium, int small) {
        parking = {big, medium, small};
    }
    
    bool addCar(int carType) {
        parking[carType-1]--;
        return parking[carType-1] >= 0;
    }

};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */