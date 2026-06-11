class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;

        vector<int> ans(n, 0);

        int previous_end = -1;
        for (const string& log : logs) {
            
            int firstcol = log.find(':');
            int secondcol = log.find(':',firstcol+1);

            int id = stoi(log.substr(0,firstcol));
            string opr = log.substr(firstcol+1,secondcol-firstcol-1);
            int time = stoi(log.substr(secondcol+1));

            if (opr=="start"){
                if (!st.empty()){
                    ans[st.top()]+= time-previous_end;
                }
                st.push(id);
                previous_end = time;
            }
            else{
                ans[id] += time-previous_end +1;
                st.pop();
                previous_end = time+1;
            }
        }
        return ans;
    }
};


// if (!st.empty()) {
//                 if ((st.top()).first == tk) {
//                     if (opr == "start") {
//                         st.emplace(tk, time);
//                         previous_end = -1;
//                     } else {
//                         if (previous_end != -1) {
//                             ans[st.top().first] += time - previous_end;
//                             previous_end = time;
//                             st.pop();
//                         } else {
//                             ans[tk] += time + 1 - st.top().second;
//                             previous_end = time;
//                             st.pop();
//                         }
//                     }
//                 } else {
//                     ans[st.top().first] += time - st.top().second;
//                     st.emplace(tk, time);
//                     previous_end = -1;
//                 }
//             } else {
//                 st.emplace(tk, time);
//                 previous_end = -1;
//             }