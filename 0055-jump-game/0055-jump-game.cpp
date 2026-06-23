class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>maxidx) return false;

            maxidx = max(maxidx,i+nums[i]);
            if(maxidx>=n-1) return true;
        }
        return true;
    }
};

// if(nums.size()==1) return true;

//         if(nums[0]==0) return false;

//         int n = nums.size();
//         int j = 0;
//         while(j<n){
//             if(j==n-1) return true;
//             if(nums[j]==0){
//                 int t = j-1;
//                 while(j<n && nums[j]==0){
//                     j++;
//                 }
//                 while(t>=0){
//                     if(n-1 <= nums[t]+t){
//                         return true;
//                     }
//                     if(j <= nums[t]+t){
//                         if(n-1 <= nums[t]+t){
//                             return true;
//                         }
//                         break;
//                     }
//                     t--;
//                     if(t<0) return false;
//                 }
//             }
//             else{
//                 j++;
//             }
//         }
//         return false;