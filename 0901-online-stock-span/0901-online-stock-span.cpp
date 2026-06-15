class StockSpanner {
private:
    stack<pair<int,int>> pge;
    int i = 0;
public:
    StockSpanner() {
    }
    int next(int price){
        while(!pge.empty() && pge.top().second <= price){
            pge.pop();
        }
        if(pge.empty()){
            pge.emplace(i,price);
            i++;
            return i;
        }
        
        int previous = pge.top().first;
        pge.emplace(pge.emplace(i,price));
        i++;
        return i-1-previous ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */