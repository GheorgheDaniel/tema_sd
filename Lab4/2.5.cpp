//https://leetcode.com/problems/find-median-from-data-stream/post-solution/?submissionId=2007651677
class MedianFinder {
public:
    priority_queue<int>pq, pq1;
    int cnt;
    MedianFinder() {
        cnt = 0;
    }
    
    void addNum(int num) {
        cnt++;
        pq.push(num);

        while(!pq.empty() && !pq1.empty() && pq.top() > -pq1.top()) {
            int val = pq.top();
            pq.pop();
            pq1.push(-val);
        }

        while(pq.size() > pq1.size()) {
            int val = pq.top();
            pq.pop();
            pq1.push(-val);
        }


        while(pq.size() + 1 < (int)pq1.size()) {
            int val = pq1.top();
            pq1.pop();
            pq.push(-val);
        }
    }
    
    double findMedian() {
        if(cnt % 2 == 0) {
            //assert(pq.top() >= 0 && pq1.top() <= 0);
            double val1 = pq.top() - pq1.top();
            val1 /= 2;
            return val1;
        }
        else {
            return (double) -pq1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */