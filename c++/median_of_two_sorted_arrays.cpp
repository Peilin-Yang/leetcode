#include  <iostream>
using namespace std;

bool _print = false;
class Solution {
public:
    double get_median(int A[], int m, int B[], int n, int k){
        int len_a = m;
        int len_b = n;

        if (_print){
            cout << "A:" << endl;
            for (int i = 0; i != m; ++i){
                cout << A[i] << " ";
            }
            cout << endl;
            cout << "B:" << endl;
            for (int i = 0; i != n; ++i){
                cout << B[i] << " ";
            }
            cout << endl;
        }

        if (len_a == 0) {
            if (_print){
                cout << "len_a == 0" << endl;
                cout << "-----------" << endl;
            }
            return B[k];
        } else if (len_b == 0) {
            if (_print){
                cout << "len_a == 0" << endl;
                cout << "-----------" << endl;
            }
            return A[k];
        }
        if (k <= 0) {
            if (_print){
                cout << "k <= 0" << endl;
                cout << "-----------" << endl;
            }
            if (A[0] <= B[0]) {
                return A[0];
            }
            else {
                return B[0];
            }
        }
  
        int middle_A = len_a %2==0?len_a/2-1:len_a/2;
        int middle_B = len_b %2==0?len_b/2-1:len_b/2;

        if (_print){
            cout << "middle_A:" << middle_A << endl;
            cout << "middle_B:" << middle_B << endl;
            cout << "A[middle_A]:" << A[middle_A] << endl;
            cout << "B[middle_B]:" << B[middle_B] << endl;
            cout << "k:" << k << endl;
        }

        if (A[middle_A] >= B[middle_B]) {
            if (middle_A+middle_B >= k) {
                int sub_A[middle_A];
                copy(A, A+middle_A, sub_A);
                if (_print){
                    cout << "A[middle_A] >= B[middle_B] && middle_A+middle_B>=k" << endl;
                    cin.ignore();
                }
                return get_median(sub_A, middle_A, B, n, k);
            } else {
                int sub_B[len_b-middle_B-1];
                copy(B+middle_B+1, B+len_b, sub_B);
                if (_print){
                    cout << "A[middle_A] >= B[middle_B] && middle_A+middle_B<k" << endl;
                    cin.ignore();
                }
                return get_median(A, m, sub_B, len_b-middle_B-1, k-middle_B-1);
            }
        } else {
            if (middle_A+middle_B >= k) {
                int sub_B[middle_B];
                copy(B, B+middle_B, sub_B);
                if (_print){
                    cout << "A[middle_A] < B[middle_B] && middle_A+middle_B>=k" << endl;
                    cin.ignore();
                }
                return get_median(A, m, sub_B, middle_B, k);
            } else {
                int sub_A[len_a-middle_A-1];
                copy(A+middle_A+1, A+len_a, sub_A);
                if (_print){
                    cout << "A[middle_A] < B[middle_B] && middle_A+middle_B<k" << endl;
                    cin.ignore();
                }
                return get_median(sub_A, len_a-middle_A-1, B, n, k-middle_A-1);
            }
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total_length = m+n;
        
        if (total_length % 2 == 0){
            return (get_median(A, m, B, n, total_length/2-1) + get_median(A, m, B, n, total_length/2)) / 2;
        }
        else{
            return get_median(A, m, B, n, total_length/2);
        }
    }
};

int main()
{
    Solution *s = new Solution();

    int A1[] = {1,4,7,9}; int B1[] = {};
    int A2[] = {1,4,5,7,9}; int B2[] = {};
    int A3[] = {2,58,78,130}; int B3[] = {-3,-2,-1};
    int A4[] = {2,5,7,9,11,17,19,21,38}; int B4[] = {1,2,3,4,5,6,7,8,9,10,12,13,14};

    double r;
    r = s->findMedianSortedArrays(A1, sizeof(A1)/sizeof(int), B1, sizeof(B1)/sizeof(int));
    cout << r << endl;
    r = s->findMedianSortedArrays(A2, sizeof(A2)/sizeof(int), B2, sizeof(B2)/sizeof(int));
    cout << r << endl;
    r = s->findMedianSortedArrays(A3, sizeof(A3)/sizeof(int), B3, sizeof(B3)/sizeof(int));
    cout << r << endl;
    r = s->findMedianSortedArrays(A4, sizeof(A4)/sizeof(int), B4, sizeof(B4)/sizeof(int));
    cout << r << endl;
    return 0;
}


