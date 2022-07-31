class NumArray {
public:
  vector<int>store;
    int sum=0;
    NumArray(vector<int>& nums) {
        store=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum-=store[index];
        store[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int temp=sum;
        for(int i=0;i<left;i++) temp-=store[i];
        for(int i=right+1;i<store.size();i++) temp-=store[i];
        return temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */