#include<cstdlib>
#include<iostream>

using namespace std;
int main() {
  cout << strtod("9.", NULL) << endl;
  cout << strtod("1.8e-", NULL) << endl;
  cout << strtod("1.8e+-10", NULL) << endl;
  cout << strtod("1.e+", NULL) << endl;
  return 0;
}
