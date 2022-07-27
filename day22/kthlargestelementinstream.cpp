class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int p;
    KthLargest(int k, vector<int>& nums) {
        p = k;
        for(int i : nums) {
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > p) pq.pop();
        return pq.top();
    }
};