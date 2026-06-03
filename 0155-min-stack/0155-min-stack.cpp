class MinStack {
    private:
        int top1;
        long long *arr;
        int cap = 3e4+7;
        long long mini = INT_MAX;
public:
    MinStack() {
        top1 = -1;
        arr = new long long[cap];
    }
    
    void push(int val) {
        if (top1==-1){
            top1+=1;
            arr[top1]=val;
            mini = val;
        }
        else if (top1<cap){
            if (val < mini){
                top1+=1;
                arr[top1] = 2LL * val-mini;
                mini = val;
            }
            else{
                top1++;
                arr[top1]= val;
            }
        }
    }
    
    void pop() {
        if (top1 > -1){
            if (arr[top1] > mini){
                top1--;
            }
            else{
                mini = 2*mini-arr[top1];
                top1--;
            }
        }
    }
    
    int top() {
        if (top1<0) return -1;

        if (arr[top1] > mini){
                return arr[top1];
            }
        else return mini;
        return 0;
    }
    
    int getMin() {
        if (top1<0) return -1;
        return mini;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */