//the logic being that the left part will be maxHeap and the right part will be minHeap
//there are 4 rules for insersion
    //if both are empty then insert it right(minHeap)
    //elseif both are the same size then 
        //if ele>median then right(minHeap) else left(maxHeap)
    //elseif left.size() > right.size() then 
        //if ele>median insert right else pop->top->left->insert->right and insert->ele->left
    //else  ~~left.size() < right.size()~~ then 
        //if ele<median insert left else pop->top->right->insert->left and insert->ele->right
//there are 4 rules for finding median
    //if both are empty then return 0.0
    //elseif both are of the same size then (top->left + top->right)/2.0
    //elseif left.size() > right.size() return top->left
    //else ~~left.size() < right.size() return top->right
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        double median = findMedian();
        if(maxHeap.size() == 0 && minHeap.size() == 0) minHeap.push(num);
        else if(maxHeap.size()==minHeap.size()) {
            if(num>median) minHeap.push(num);
            else maxHeap.push(num);
        }
        else if (maxHeap.size() > minHeap.size()){
            if(num>median) minHeap.push(num);
            else{ //num<median
                int front = maxHeap.top(); maxHeap.pop();
                minHeap.push(front);
                maxHeap.push(num);
            }
        }
        else{ //maxHeap.size() < minHeap.size()
            if(num<median) maxHeap.push(num);
            else{ //num>median
                int front = minHeap.top(); minHeap.pop();
                maxHeap.push(front);
                minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.empty() && minHeap.empty()) return 0.0;
        else if(maxHeap.size() == minHeap.size()) return ((maxHeap.top() + minHeap.top())/2.0);
        else if(maxHeap.size()>minHeap.size()) return maxHeap.top();
        else return minHeap.top(); //maxHeap.size()<minHeap.size()
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */