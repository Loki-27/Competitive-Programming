class Solution {
public:
    void pusher(string& ans,int idx,int n,string& s,int k){
        int t = 0;
        for(int i = idx;i<n;i++){
                if(s[i]=='-') continue;
                if(s[i]>=97 && s[i]<=122) ans.push_back((char)('A'+ s[i] -'a'));
                else ans.push_back(s[i]);
                t++;
                if(t==k){ans.push_back('-'); t=0;}
            }
    }
    string licenseKeyFormatting(string s, int k) {
        int size = s.size();
        int dash = 0;

        for(char& c:s){
            if(c=='-') dash++;
        }

        int chars = size-dash;
        if(chars==0) return "";
        string ans = "";
        int f = chars%k;
        int i = 0;
        while(f>0 && i<size){
            if(s[i]=='-') {i++;continue;}

            if(s[i]>=97 && s[i]<=122) ans.push_back((char)('A'+ s[i] -'a'));
            else ans.push_back(s[i]);
            f--;
            i++;
        }
        if(ans.size()>0) ans.push_back('-');
        pusher(ans,i,size,s,k);

        if(ans.back()=='-') ans.pop_back();
        return ans;
    }
};