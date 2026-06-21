class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26);

        int maxi = 0;
        int maxCount = 0;
        for(auto x:tasks){
            counter[x-'A']++;
            if(maxi==counter[x-'A']) maxCount++;
            else if(maxi<counter[x-'A']){
                maxi = counter[x-'A'];
                maxCount =1;
            }
        }

        int partCount = maxi-1;
        int partLength = n-(maxCount-1);
        int emptySlots = partCount * partLength;
        int availabletasks = tasks.size()-maxi*maxCount;
        int idles = max(0,emptySlots-availabletasks);


        return tasks.size()+idles;
    }   
};