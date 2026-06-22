class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26,0);
        vector<int> bal = {0,1,11,14,13}; // a b l o n;
        
        for(auto& x:text){
            v[x-'a']++;
        }
        
        v['l'-'a'] = v['l'-'a']/2;
        v['o'-'a'] = v['o'-'a']/2;


        int mini = INT_MAX;
        for(int &x:bal){
            mini = min(mini,v[x]);
        }
        return mini;
    }
};