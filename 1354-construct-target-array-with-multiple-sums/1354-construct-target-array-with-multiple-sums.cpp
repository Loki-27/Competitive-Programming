class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(),target.end());
        long long sum = 0;

        for(int i =0;i<target.size();i++){
            sum+=target[i];
        }

        while(pq.top()!=1){
            int maxi = pq.top();pq.pop();

            long long diff = sum-maxi;
            if(diff==1) return true;
            if(diff > maxi || diff == 0 || maxi%diff==0) return false;

            maxi = maxi%diff;
            pq.push(maxi);
            sum = diff+maxi;
        }

        return true;
    }
};