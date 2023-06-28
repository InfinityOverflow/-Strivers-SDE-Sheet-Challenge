class MedianFinder {
private:
    priority_queue<int>small;
    priority_queue<int,vector<int>,greater<int>>large;
    int n;
public:
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        n++;
        small.push(num);
        if(small.size()>large.size()+1)
        {
            int temp=small.top();
            small.pop();
            large.push(temp);
           
        }
        if( large.size() and large.top()<small.top())
            {
                int a=small.top();
                int b=large.top();
                small.pop();large.pop();
                swap(a,b);
                small.push(a);large.push(b);
            }

    }
    
    double findMedian() {
        if(n%2)
        {
            return small.top();
        }
        else
        {
            return ( (double)small.top()+(double)large.top() )/double(2);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */