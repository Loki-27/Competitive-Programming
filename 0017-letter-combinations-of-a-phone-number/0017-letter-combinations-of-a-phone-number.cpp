class Solution {
public:
    vector<string> res;
    void helper(string &digi,int idx,string &sub,vector<string>& keys){
        if(idx==digi.size()){
            res.push_back(sub);
            return;
        }

        
        string s = keys[digi[idx]-'2'];
        int size = s.size();

        for(int i = 0;i<size;i++){
            sub.push_back(s[i]);
            helper(digi,idx+1,sub,keys);
            sub.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> keys = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string sub="";
        
        helper(digits,0,sub,keys);
        return res;
    }
};