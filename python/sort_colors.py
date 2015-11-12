class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        i = 0
        actuall_loop = 0
        while True:
            if i >= len(A) or actuall_loop >= len(A):
                break
            if A[i] == 0:
                #print '0'
                A.pop(i)
                A.insert(0, 0)
                i += 1
            elif A[i] == 2:
                should_proceed = True if (i+1 < len(A) and A[i+1] == 1) or (i+1 == len(A)) else False
                A.pop(i)
                A.append(2)
                if should_proceed:
                    i += 1
            elif A[i] == 1:
                i += 1
            actuall_loop += 1

        print 'final:'+str(A)+str(len(A))




if __name__ == '__main__':
    #a = []
    #a = [1,2,0]
    a = [0,2,0,1,1,2,0,1,0,2,0,1,0,0,1,0,2,1,2,2,1,0,2,1,0,2,1,0,0,0,0,0,0,1,1,1,1,2,2,1,0,0,1,0,1,1,0,1,0,1]
    #a = [1,0]
    Solution().sortColors(a)