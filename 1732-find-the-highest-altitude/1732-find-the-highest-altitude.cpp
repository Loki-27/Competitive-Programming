class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxheight = 0;

        int sum = 0;

        for(auto x:gain){
            sum+=x;
            maxheight=max(maxheight,sum);
        }
        return maxheight;
    }
};