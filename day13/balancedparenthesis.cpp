class MyQueue {
public:
    stack<int>s1;
stack<int>s2;

MyQueue() {
    
}

void push(int x) {
    s1.push(x);
}

int pop() {
    int ans;
    
    if(!s2.empty()){
        ans=s2.top();
        s2.pop();
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        if(!s2.empty()){
            ans=s2.top();
            s2.pop();
        }
    }
    return ans;
}

int peek() {
    int ans;
    if(!s2.empty()){
        ans=s2.top();
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        if(!s2.empty()){
            ans=s2.top();
        }
    }
    return ans;
}

bool empty() {
    return s1.empty() && s2.empty();
}
};
