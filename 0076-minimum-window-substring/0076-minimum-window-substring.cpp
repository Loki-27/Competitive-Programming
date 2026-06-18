class Solution {
public:
    string minWindow(string s, string t) {
        // Use 128 to cover all standard ASCII characters without manual mapping offsets
        vector<int> target(128, 0);
        for (char c : t) target[c]++;

        int l = 0, initial = 0, minsize = INT_MAX;
        int required = t.size(); // Total character matches we still need to satisfy

        for (int r = 0; r < s.size(); r++) {
            // If we actually need s[r] to satisfy t, decrement our required count
            if (target[s[r]] > 0) {
                required--;
            }
            target[s[r]]--; // Decrement character frequency (can go negative for extra/unneeded chars)

            // When required == 0, the current window [l, r] contains all characters of t
            while (required == 0) {
                if (r - l + 1 < minsize) {
                    minsize = r - l + 1;
                    initial = l;
                }

                // Prepare to slide the left pointer out. 
                // If s[l] was a critical component of t, increment the required count.
                target[s[l]]++;
                if (target[s[l]] > 0) {
                    required++; 
                }
                l++;
            }
        }

        // If minsize was never updated, it means no valid window was found
        return minsize == INT_MAX ? "" : s.substr(initial, minsize);
    }
};





// class Solution {
//     private:
//     bool check(vector<int>& requiredfreqs,vector<int>& freq){
//             for(int i = 0;i<59;i++){
//                 if(requiredfreqs[i]>0 && freq[i]<requiredfreqs[i]){
//                     return false;
//                 }
//             }
//         return true;
//     }
// public:
//     string minWindow(string s, string t) {
//         int tsize = t.size();
//         vector<int> requiredfreqs(59,0);
//         for(auto x:t){
//             requiredfreqs[x-'A']++;
//         }

//         vector<int> freq(59,0);

//         int l = 0;
//         int initial = 0;
//         int minsize = INT_MAX;
//         bool evervalid = false;
//         for(int r=0;r<s.size();r++){
//             freq[s[r]-'A']++;

//             bool isvalid = check(requiredfreqs,freq);

//             while(isvalid){
//                 if(minsize>r-l+1){
//                         initial = l;
//                         minsize = min(minsize,r-l+1);
//                     }
//                 if(requiredfreqs[s[l]-'A']>0 && requiredfreqs[s[l]-'A']==freq[s[l]-'A']){
//                     isvalid = false;
//                     break;
//                 }
//                 freq[s[l]-'A']--;
//                 l++;
                
//             }
//         }
//         return (minsize==INT_MAX) ?  "" :s.substr(initial,minsize);
//     }
// };