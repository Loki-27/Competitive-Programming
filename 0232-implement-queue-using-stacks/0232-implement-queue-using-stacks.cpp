class myStack {
  private:
    int capacity;
    int *arr;
  public:
  int top;
    myStack(int n) {
            capacity = n;
            top = -1;
            arr = new int[capacity];
    }

    ~myStack(){
        delete[] arr;
    }
    void swap_class(myStack& other){
        swap(capacity,other.capacity);
        swap(top,other.top);
        swap(arr,other.arr);
    }

    bool isEmpty() {
        return (top==-1)  ? true : false;
    }

    bool isFull() {
        return (top+1==capacity) ? true : false;
    }

    void push(int x) {
        if (top+1<capacity){
        top+=1;
        arr[top]=x;
        }
    }

    int pop(){
        if (top>-1){ 
            top-=1;
            return arr[top+1];
        }
        return -1;
    }

    int peek() {
        if (top>-1) return arr[top];
        else return -1;
    }
};


class MyQueue {
public:
    myStack s1;
    myStack s2;
    MyQueue():s1(101),s2(101) {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            } 
        }
    if (s2.isEmpty()) return -1;

    return s2.pop();

    }
    
    int peek() {
        if (s2.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            } 
        }
        if (s2.isEmpty()) return -1;

        return s2.peek();
    }
    
    bool empty() {
        return (s1.isEmpty() && s2.isEmpty());
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */