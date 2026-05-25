class Solution {

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        // if (m>n){
            int low = 0,high = m-1;
            int idx = 0;
            while(low < high){
                int mid = low+(high-low)/2;
                auto maxi = max_element(mat[mid].begin(),mat[mid].end());

                idx = distance(mat[mid].begin(),maxi);
                if (*maxi > mat[mid+1][idx]){
                    high = mid;
                }
                else low= mid+1;
            }
            
            auto maxi = max_element(mat[low].begin(),mat[low].end());
            idx = distance(mat[low].begin(),maxi);
            return {low,idx};
        // }

    }

};