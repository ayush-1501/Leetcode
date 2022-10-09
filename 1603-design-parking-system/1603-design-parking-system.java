class ParkingSystem {
    int big;
    int medium;
    int small;
    public ParkingSystem(int big, int medium, int small) {
        this.big = big;
        this.medium = medium;
        this.small = small;

    }
    
    public boolean addCar(int carType) {
        boolean result=false;
        if (carType == 1) {
            if (big > 0) {
                result = true;
                big--;
            }
        } else if (carType == 2) {
            if (medium > 0) {
                result = true;
                medium--;
            }
        } else {
            if (small > 0) {
                result = true;
                small--;
            }
        }
        return result;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */