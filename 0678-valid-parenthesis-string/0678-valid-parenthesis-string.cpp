class Solution {
public:
    bool checkValidString(string s) {
        int minopen =0;
        int maxopen =0;

        for(auto &x:s){
            if(x=='('){
                minopen++;
                maxopen++;
            }
            else if(x==')'){
                minopen--;
                maxopen--;
            }
            else{
                minopen--;
                maxopen++;
            }
            if(minopen<0) minopen=0;
            if(maxopen<0) return false;
        }

        return minopen==0;
    }
};


// class Solution {
// public:
//     bool checkValidString(string s) {
//         stack<int> open;
//         stack<int> star;

//         for(int i = 0;i<s.size();i++){
//             if(s[i]=='*') star.push(i);
//             else if(s[i]=='(') open.push(i);
//             else{
//                 if(!open.empty()) open.pop();
//                 else if(!star.empty()) star.pop();
//                 else return false;
//             }
//         }

//         while(!open.empty() &&!star.empty()){
//             if(open.top()<star.top()){
//                 open.pop();
//                 star.pop();
//             }
//             else{
//                 return false;
//             }
//         }

//         return open.empty();
//     }
// };