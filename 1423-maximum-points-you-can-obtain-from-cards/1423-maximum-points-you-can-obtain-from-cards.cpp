class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curruntsum = 0;

        for(int i = 0;i<k;i++){
            curruntsum += cardPoints[i];
        }
        int maxscore = curruntsum;

        for(int i =0;i<k;i++){
            curruntsum -= cardPoints[k-1-i];
            curruntsum += cardPoints[n-1-i];
            maxscore = max(maxscore,curruntsum);
        }

        return maxscore;
    }
};