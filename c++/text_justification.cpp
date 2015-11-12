#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, k=0, l=0;
        vector<string> r;
        int s = words.size();
        for (; i < s; i+=k) {
            for (l=0,k=0; i+k<s && l+k+words[i+k].size()<=maxWidth; k++) {
                l += words[i+k].size();
            }
            string tmp = words[i];
            for (int j = 0; j < k-1; j++) {
                if (i+k>=s) tmp+=" ";
                else tmp += string((maxWidth-l)/(k-1)+(j<(maxWidth-l)%(k-1)), ' ');
                tmp += words[i+j+1];
            }
            tmp += string(maxWidth-tmp.size(), ' ');
            r.push_back(tmp);
        }
        return r;
    }
};

void print_r(vector<string> &r) {
  for(int i = 0; i != r.size(); i++) {
    cout << r[i] << endl;
  }
}

int main() {
  Solution s;

  /*
  string a[] = {"This", "is", "an", "example", "of", "text", "justification."};
  vector<string> n(a,a+sizeof(a)/sizeof(string));
  vector<string> r = s.fullJustify(n, 16);
  print_r(r);
  
  string a[] = {""};
  vector<string> n(a,a+sizeof(a)/sizeof(string));
  vector<string> r = s.fullJustify(n, 2);
  print_r(r);
  */
  
  string a[] = {"a", "b", "c", "d", "e"};
  vector<string> n(a,a+sizeof(a)/sizeof(string));
  vector<string> r = s.fullJustify(n, 3);
  print_r(r);
  return 0;
}
