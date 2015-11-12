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
    vector<Interval> merge(vector<Interval> &intervals) {
        int l = intervals.size();
        if (l<=1) return intervals;
        struct {
            bool operator() (Interval i1, Interval i2) {
                return i1.start < i2.start;
            }  
        } comp;
        vector<Interval> r(intervals.begin(), intervals.begin()+1);
        std::sort(intervals.begin(), intervals.end(), comp);
        for (int i = 1; i != l; i++) {
            if (intervals[i].start <= r.back().end) {
                r.back().end = intervals[i].end;
            } else {
                r.push_back(intervals[i]);
            }
        }
        return r;
    }
};

int main() {
    Solution *s = new Solution();
    vector<Interval> test;
    vector<Interval> result;
    
    test.push_back(Interval(1, 3));
    test.push_back(Interval(2, 6));
    test.push_back(Interval(8, 10));
    test.push_back(Interval(15, 18));

    result = s->merge(test);

    for (int i = 0; i != result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    test.clear();
    test.push_back(Interval(1, 4));
    test.push_back(Interval(2, 3));

    result = s->merge(test);

    for (int i = 0; i != result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
