class Solution {
public:
    void findcomb(string s,vector<string>& res,int i){
        if(i>=s.size()) return;
        s[i] = '0';
        i+=2;
        res.push_back(s);
        while(i<s.size()){
            findcomb(s,res,i);
            i++;
        }
    }
    vector<string> validStrings(int n) {
        string s = "";
        for(int i = 0;i<n;i++){
            s.push_back('1');
        }
        vector<string> res;
        res.push_back(s);
        
        int i = 0;
        for(int i =0;i<n;i++){
            findcomb(s,res,i);
        }
        return res;
    }
};