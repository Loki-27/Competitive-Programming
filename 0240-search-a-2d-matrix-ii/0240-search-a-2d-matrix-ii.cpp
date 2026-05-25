class Solution {
public:

    bool BS(vector<vector<int>>& matrix,int t,int Clow ,int Chigh,int Rlow ,int Rhigh){
        
        if (Rlow>Rhigh || Clow>Chigh){
            return false;
        }

        int Cmid = Clow+ (Chigh-Clow)/2;
        int Rmid = Rlow + (Rhigh-Rlow)/2;

        if (matrix[Cmid][Rmid]==t) return true; 

        bool f1,f2,f3;
        if (matrix[Cmid][Rmid]>t){
            f1 = BS(matrix,t ,Clow ,Cmid-1 ,Rlow ,Rhigh);
            
            f2 = BS(matrix,t ,Cmid ,Chigh ,Rlow, Rmid-1);

            f3 = false;
            
        }
        else{
            f1 = BS(matrix,t ,Clow ,Chigh ,Rmid+1 ,Rhigh);
            
            f2 = false;

            f3 = BS(matrix,t ,Cmid+1 ,Chigh ,Rlow, Rmid);
        }

        return f1||f2||f3;

    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int Clow  = 0; 
        int Chigh = m-1;
        int Rlow = 0;
        int Rhigh = n-1;
        
        int Cmid = Clow+ (Chigh-Clow)/2;

        int Rmid = Rlow+ (Rhigh-Rlow)/2;

        return BS(matrix,target,Clow,Chigh,Rlow,Rhigh);

    }
};