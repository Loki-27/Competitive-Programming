class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        int n = s.size();

        for(auto& c:s){
            freq[c-'a']++;
        }
        
        int x = 0;
        for(int i = 0;i<26;i++){
            int range = freq[i]/2;
            for(int j = 0;j<range;j++){
                s[x]= (char)(i+'a');
                freq[i]-=2;
                x++;
            }
            if(x==n/2) break;
        }
        if(n%2!=0){
            for(int i = 0;i<26;i++){
                if(freq[i]!=0) {
                    s[n/2+1] = (char)('a'+i);
                    break;
                }
            }
        }

        for(int i = n-1;i>=n/2;i--){
            s[i]=s[n-1-i];
        }
        return s;
    }
};