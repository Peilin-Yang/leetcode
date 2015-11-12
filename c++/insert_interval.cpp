#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    friend ostream& operator << (ostream& oStream, const Interval& i) {
        cout << "[" << i.start << "," << i.end << "]";
        return oStream;
    }
};

class Solution {
public:
    void findInsertPosition(vector<Interval> &intervals, Interval newInterval) {
      int l = intervals.size();
      int start = 0, end = l - 1;
      while(start<=end) {
        int mid = (start+end)/2;
        if (intervals[mid].start == newInterval.start) {
          while(mid-1 >= 0 && intervals[mid-1].start == newInterval.start) {
            mid--;
          }
          start = mid;
          break;
        } else if (intervals[mid].start < newInterval.start) {
          start = mid+1;
        } else if (intervals[mid].start > newInterval.start) {
          end = mid-1;
        }
      }
      cout << "insert position:" << start << endl;
      intervals.insert(intervals.begin()+start, newInterval);
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        findInsertPosition(intervals, newInterval);
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i != intervals.size(); ++i) {
            if (ret.back().end >= intervals[i].start) {
                ret.back().end = max(ret.back().end, intervals[i].end);
            } else {
                ret.push_back(intervals[i]);
            }
        }
        
        return ret;
    }
};

int main() {
    Solution *s = new Solution();
    vector<Interval> test;
    vector<Interval> result;
    
    test.push_back(Interval(0, 3));
    test.push_back(Interval(5, 8));
    test.push_back(Interval(9, 11));

    Interval a(9, 18); 
    result = s->insert(test, a);

    for (int i = 0; i != result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
