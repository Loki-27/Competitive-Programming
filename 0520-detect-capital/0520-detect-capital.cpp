class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1) return true;

        bool iscap0 = (word[0]-'A'<=25);
        bool second = (word[1]-'A' <=25);
        for(int i =2;i<word.size();i++){
            if(iscap0 && second) {
                if (word[i]-'A'>25) return false;
            }
            else if(!second){
                if(word[i]-'A'<=25) return false;
            }
            else return false;
        }
        if(!iscap0 && second) return false;
        
        return true;
    }
};