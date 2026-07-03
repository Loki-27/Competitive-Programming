class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0,n=word.size();
        for(auto& x:word) if(x<='Z') c++;

        if(c==0 || c    ==n) return true;
        if(c==1 && word[0]<='Z') return true;
        return false;
    }
};