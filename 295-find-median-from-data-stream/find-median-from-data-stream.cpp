class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
priority_queue<int, vector<int> , greater<int> > min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int i) {
        	if(max_heap.empty() || i < max_heap.top() )
		{
			max_heap.push(i);
		}
		else
		{
			min_heap.push(i);
		}

		if(max_heap.size()> min_heap.size()+1)
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		else if(max_heap.size() < min_heap.size())
		{
			max_heap.push(min_heap.top());
			min_heap.pop();
		}

        
    }
    
    double findMedian() {
        	if(max_heap.size()==min_heap.size())
	{
	   return (double)(max_heap.top() + min_heap.top() )/2;
	}

	return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */