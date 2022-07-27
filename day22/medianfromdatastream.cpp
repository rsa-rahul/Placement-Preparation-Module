class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.size()>0 && minHeap.top()<num){
            minHeap.push(num);
            if(minHeap.size()>1+maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else{
            maxHeap.push(num);
            if(maxHeap.size()>1+minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if((minHeap.size()-maxHeap.size())==0){
            return (double)(minHeap.top()+maxHeap.top())/2.0;
        }
        else{
            if(minHeap.size()>maxHeap.size()) return minHeap.top();
            else return maxHeap.top();
        }
    }
};