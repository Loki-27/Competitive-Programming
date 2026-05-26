class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> maper;

        for(int i =0;i<s.size();i++){
            if (maper.find(s[i]) !=maper.end())
                maper[s[i]] += 1;
            else maper[s[i]] = 1;
        }
        
        vector<vector<char>> buckets(s.size()+1);

        for(auto& a:maper){
            buckets[a.second].push_back(a.first);
        }

        string ans;
        for (int i = buckets.size()-1;i>=0;i--){
            if (!buckets[i].empty()){
                for(int j = 0; j<buckets[i].size();j++){
                        ans.append(i,buckets[i][j]);   
                }
            }
        }

        return ans;
    }
};