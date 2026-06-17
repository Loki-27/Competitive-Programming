class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> abc(3,0);
        int l=0,r=0;

        int subs = 0;

        while(r<n){
            abc[s[r]-'a']++;

            while(abc[0]>=1 && abc[1]>=1 && abc[2]>=1){
                subs+= n-r;
                abc[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return subs;
    }
};