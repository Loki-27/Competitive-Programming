class Solution {
    private:
    bool check(vector<int>& requiredfreqs,vector<int>& freq){
        bool isvalid = true;
            for(int i = 0;i<59;i++){
                if(requiredfreqs[i]>0 && freq[i]<requiredfreqs[i]){
                    isvalid = false;
                    break;
                }
            }
        return isvalid;
    }
public:
    string minWindow(string s, string t) {
        int tsize = t.size();
        vector<int> requiredfreqs(59,0);
        for(auto x:t){
            requiredfreqs[x-'A']++;
        }

        vector<int> freq(59,0);

        int l = 0;
        int initial = 0;
        int minsize = s.size();
        bool evervalid = false;
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;

            bool isvalid = check(requiredfreqs,freq);

            if(isvalid){
                evervalid = true;
                // initial = l;
                // minsize = min(minsize,r-l+1);
            }

            while(isvalid){
                if(requiredfreqs[s[l]-'A']>0 && requiredfreqs[s[l]-'A']==freq[s[l]-'A']){
                    if(minsize>r-l+1){
                        initial = l;
                        minsize = min(minsize,r-l+1);
                    }
                    isvalid = false;
                    break;
                }
                if(minsize>r-l+1){
                        initial = l;
                        minsize = min(minsize,r-l+1);
                }
                freq[s[l]-'A']--;
                l++;
                
            }
        }
        cout<<initial ;
        return (minsize>=tsize && evervalid) ? s.substr(initial,minsize): "";
    }
};