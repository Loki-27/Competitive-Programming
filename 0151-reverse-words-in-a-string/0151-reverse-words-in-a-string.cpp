class Solution {
public:
    string reverseWords( string s ) {

        int last = s.size() - 1;
        int first = s.size() - 1;

        string ans;

        for(int i = s.size()-1; i>=0;i--){
            if ( s[i]!= ' ' ){
                first--; 
            }
            else{
                if (last == first){
                    first = i-1;
                    last = first;
                }
                else {
                    for(int j = first+1; j <= last; j++) {
                        ans.push_back(s[j]);
                        }
                    // if (s[last]!= ' ')
                    ans.push_back(' ');
                    first-=1;
                    last = first;
                }
            }
        }
            if (last>=first && last>=0){
                for(int j = first+1; j <= last; j++) {
                        ans.push_back(s[j]);
                }
            }

            if (!ans.empty() && s[0]==' ')
                ans.pop_back();
        return ans;

        
    }
};