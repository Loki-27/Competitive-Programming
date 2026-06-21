class KthLargest {
    private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int kin, vector<int>& nums) {
        k = kin;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        vector<int> store;
        pq.push(val);


        while(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */