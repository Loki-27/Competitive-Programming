class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  = matrix.size();
        int n = matrix[0].size();

        if (target > matrix[m-1][n-1]) return false;

        int low = 0;
        int high = m;

        while(low<=high){
            int mid = low+(high-low)/2;

            if (target > matrix[mid][n-1] ){
                low = mid+1;
            }
            else high = mid-1;
        }
        int row = low;
        low = 0,high = n;

        while(low<=high){
            int mid = low+(high-low)/2;

            if (target > matrix[row][mid] ){
                low = mid+1;
            }
            else high = mid-1;
        }

        if (target == matrix[row][low]) return true;
        else return false;
    }
};