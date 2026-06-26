
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        int l = 0,r=0;

        vector<vector<int>> res;

        while(l<n && r<n){
            int end = intervals[r][1];

            while(r<n-1 && intervals[r+1][0]<=end){
                r++;
                end = max(intervals[r][1],end);
            }
            res.push_back({intervals[l][0],end});

            l = r+1;
            r = r+1;
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int> > ans;
//         int l = intervals.size();

//         vector<int> ent;

//         sort(intervals.begin(),intervals.end());
//         int st = -1;
//         int last = 0;
//         int end = intervals[0][1];
//         for(int i =0;i<l-1;i++){
//             if (st==-1) st=intervals[i][0];
//             if (end >=intervals[i+1][0]){
//                 end = max(end,intervals[i+1][1]);
//                 if (i==l-2){
//                     ent.push_back(st);ent.push_back(end);
//                     ans.push_back(ent);
//                     last =1;
//                 }
//             }
//             else{
//                 ent.push_back(st);ent.push_back(end);
//                 ans.push_back(ent);
//                 st = -1;
//                 end = intervals[i+1][1];
//                 ent.clear();
//             }
//         }
//         if(last==0){
//                     ent.push_back(intervals[l-1][0]);ent.push_back(intervals[l-1][1]);
//                     ans.push_back(ent);
//             }

//         return ans;
//     }
// };


// int n = intervals.size();
// sort(intervals.begin(),intervals.end());
// vector<vector<int>> mergedIntervals;
// for(int i=0;i<n;i++){
//     if(mergedIntervals.empty()||mergedIntervals.back()[1]<intervals[i][0]){
//         mergedIntervals.push_back(intervals[i]); 
//     }
//     else{
//         // mergedIntervals.back()[0]=min(mergedIntervals.back()[0],intervals[i][0]);
//         mergedIntervals.back()[1]=max(mergedIntervals.back()[1],intervals[i][1]);
//     }
// }
// return mergedIntervals;
