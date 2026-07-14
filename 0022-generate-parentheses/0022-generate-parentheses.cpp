class Solution {
public:
    void helper(vector<string>& res,string& s,int n,int m){
        if(n==0 && m==0 ){
            res.push_back(s);
            // s.pop_back();
            return;
        }
        if(n>0){
            s.push_back('(');
            helper(res,s,n-1,m);
            s.pop_back();
        }
        if(m>0 && m>n){
            s.push_back(')');
            helper(res,s,n,m-1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        string s = "";
        vector<string> res;
        helper(res,s,open,close);
        return res;
    }
};