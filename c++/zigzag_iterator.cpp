#include<vector>
#include<iostream>

using namespace std;

class ZigzagIterator {
private:
    vector<int> _v1, _v2;
    int len_v1, len_v2;
    int cur_v1, cur_v2;
    int cur_list = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        _v1 = v1;
        _v2 = v2;
        len_v1 = _v1.size();
        len_v2 = _v2.size();
        cur_v1 = cur_v2 = 0;
    }

    int next() {
        if (cur_list == 0) {
            if (cur_v1<len_v1) {
                if (cur_v2 < len_v2) cur_list = 1;
                return _v1[cur_v1++];
            } else {
                cur_list = 1;
                return _v2[cur_v2++];
            }
        } else if (cur_list == 1) {
            if (cur_v2<len_v2) {
                if (cur_v1 < len_v1) cur_list = 0;
                return _v2[cur_v2++];
            } else {
                cur_list = 0;
                return _v1[cur_v1++];
            }
        }
        
    }

    bool hasNext() {
        return cur_v1<len_v1 || cur_v2<len_v2;
    }
};


int main() {
  vector<int> v1 = {1,2};
  vector<int> v2 = {3,4,5,6};

  ZigzagIterator i = ZigzagIterator(v1, v2);
  while (i.hasNext()) {
    cout << i.next() << "->";
  }
  cout << endl;


  return 0;
}
