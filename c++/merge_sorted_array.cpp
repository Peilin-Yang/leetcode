#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
      int *mirror_A = new int[m];
      memcpy(mirror_A, A, m*sizeof(int));
      
      int i=0,j=0,k=0;
      while(i<m || j<n) {
        if(i >= m && j < n) {
          A[k] = B[j];
          j++;
        }
        else if(i < m && j >= n) {
          A[k] = mirror_A[i];
          i++;
        } else {
          if (mirror_A[i] <= B[j]) {
            A[k] = mirror_A[i];
            i++;
          } else {
            A[k] = B[j];
            j++;
          }
        }
        k++;
      }
    }
};

int main() {
  Solution s;


  int *A = new int[10] {1,2,4,5,0,0,0,0,0,0};
  int B[] = {3,6};
  s.merge(A, 4, B, 2);

  for (int i = 0; i != 10; i++)
   cout << A[i] << ",";
  cout << endl;
  return 0;
}
