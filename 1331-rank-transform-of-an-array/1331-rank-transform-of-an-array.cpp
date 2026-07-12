class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> m;
        // vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        
        int c =1;
        for(auto& x:m){
            for(auto& a:x.second){
                arr[a] = c;
            }
            c++;
        }

        return arr;
    }
};