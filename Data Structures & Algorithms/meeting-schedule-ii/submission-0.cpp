/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class IntervalComparator {
public:
    bool operator() (Interval& a, Interval& b) const {
        return a.start < b.start;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), IntervalComparator());
        pq.push(intervals[0].end);
        for(int i=1; i<n; i++) {
            auto p = pq.top();
            if(intervals[i].start >= p) {
                pq.pop();
                pq.push(intervals[i].end);
            } else {
                pq.push(intervals[i].end);
            }
        }
        return pq.size();
    }
};
