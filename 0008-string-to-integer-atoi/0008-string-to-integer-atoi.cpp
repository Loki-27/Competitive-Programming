class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        if (i==s.size()) return 0;

        bool ispositive = true;
        if (s[i]=='-' || s[i]=='+'){
            ispositive = s[i]=='-' ? false : true;
            i++;
        }
        long long ans = 0;
        while(i<s.size())
            if ( s[i]-'0'>=0 && s[i]-'0'<10){
                // if (ans > INT_MAX) {
                //     break;
                // }
            ans = ans *10 + (s[i]-'0');

            if (ispositive && ans > INT_MAX)
                return INT_MAX;
            if (!ispositive && -ans<INT_MIN)
                return INT_MIN;
            i++;
            }
            else break;

        return (ispositive==true) ? (int)ans :(int)(-ans);
    }

};