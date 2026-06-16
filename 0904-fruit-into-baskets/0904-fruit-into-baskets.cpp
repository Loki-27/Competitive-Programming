class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> num(2,0);
        vector <int> freq(2,0);
        int i=0,j=0;
        int ans=0;
        while(j<n){
            if(freq[0]==0 || freq[1]==0){
                if(freq[0]==0){
                    if(fruits[j]==num[1]){
                        freq[1]++;
                    }
                    else{
                        num[0]=fruits[j];
                        freq[0]++;
                    }
                }
                else{
                    if(fruits[j]==num[0]){
                        freq[0]++;
                    }
                    else{
                        num[1]=fruits[j];
                        freq[1]++;
                    }
                }
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                if(fruits[j]==num[0]||fruits[j]==num[1]){
                    if(fruits[j]==num[0]){
                        freq[0]++; 
                    }
                    else{
                        freq[1]++;
                    }
                    ans = max(ans,j-i+1);
                    j++;
                }
                else{
                    while(freq[0]!=0 && freq[1]!=0){
                        if(num[0]==fruits[i]){
                            freq[0]--;
                            i++;
                        }
                        else{
                            freq[1]--;
                            i++;
                        }
                        ans = max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};