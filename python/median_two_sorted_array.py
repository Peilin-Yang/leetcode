class Solution:
    def __init__(self):
        self.print_ = False

    def get_median(self, A, B, k):
        if self.print_:
            print 'A:',A,'len A:',len(A)
            print 'B:',B,'len B:',len(B)
        if not A:
            if self.print_:
                print 'not A'
            return B[k]
        if not B:
            if self.print_:
                print 'not B'
            return A[k]

        if k <= 0:
            if self.print_:
                print 'k <= 0'
                print 'return:',min(A[0],B[0])
                print '-'*30
            return min(A[0],B[0])

        middle_A = len(A)/2-1 if len(A)%2 == 0 else len(A)/2
        middle_B = len(B)/2-1 if len(B)%2 == 0 else len(B)/2

        if self.print_:
            print 'middle_A:',middle_A
            print 'middle_B:',middle_B
            print 'A[middle_A]:',A[middle_A]
            print 'B[middle_B]:',B[middle_B]
            print 'k:',k
        if A[middle_A] >= B[middle_B]:
            if middle_A+middle_B>=k:
                if self.print_:
                    print 'A[middle_A] >= B[middle_B] && middle_A+middle_B>=k'
                    raw_input()
                return self.get_median(A[:middle_A], B, k)
            else:
                if self.print_:
                    print 'A[middle_A] >= B[middle_B] && middle_A+middle_B<k'
                    raw_input()
                return self.get_median(A, B[middle_B+1:], k-middle_B-1)
        else:
            if middle_A+middle_B>=k:
                if self.print_:
                    print 'A[middle_A] < B[middle_B] && middle_A+middle_B>=k'
                    raw_input()
                return self.get_median(A, B[:middle_B], k)
            else:
                if self.print_:
                    print 'A[middle_A] < B[middle_B] && middle_A+middle_B<k'
                    raw_input()
                return self.get_median(A[middle_A+1:], B, k-middle_A-1)

    # @return a float
    def findMedianSortedArrays(self, A, B):
        if self.print_:
            print 'len A:',len(A),'len B:',len(B)
        total_len = len(A)+len(B)
        if total_len%2 == 0:
            return (self.get_median(A,B,total_len/2-1)+self.get_median(A,B,total_len/2))/2.
        else:
            return self.get_median(A,B,total_len/2)


if __name__ == '__main__':
    test_cases = []
    test_cases.append(([1,4,7,9],[]))
    test_cases.append(([1,4,5,7,9],[]))
    test_cases.append(([2,58,78,130],[-3,-2,-1]))
    test_cases.append(([2,5,7,9,11,17,19,21,38],[1,2,3,4,5,6,7,8,9,10,12,13,14]))

    for ele in test_cases:
        print ele
        print Solution().findMedianSortedArrays(ele[0], ele[1])
        print '*'*30
