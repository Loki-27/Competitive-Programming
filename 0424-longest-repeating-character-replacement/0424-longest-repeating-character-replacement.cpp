class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26,0);
        int n = s.size();
        if(n==0) return 0;
        int maxfreq = 0,maxsame = 1;
        int i = 0;
        for(int j = 0;j<n;j++){
            freq[s[j]-'A']++;

            maxfreq = max(maxfreq,freq[s[j]-'A']);

            while((j-i+1)-maxfreq >k){
                freq[s[i]-'A']--;
                i++;
            }
            maxsame = max(maxsame,j-i+1);
        }
        return maxsame;
    }
};

