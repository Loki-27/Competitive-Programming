class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);

        int c = 1;

        for(int j=0;j<32;j++){
            for(int i = 0;i<nums.size();i++){
                if(nums[i]&c) bits[j]++;
            }
            c = c<<1;
        }
        int ans = 0;

        for(int i = 0;i<32;i++){
            if(bits[i]%3!=0) ans+= (1<<i);
        }
        return ans;
    }
};