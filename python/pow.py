class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        """
        We want to make this O(log(n)).
        Some specical cases should be examed first, e.g. pow(0,0), pow(x, 0), pow(0, x).
        Otherwise, we iterate dividing x by 2 to get a list of "indexes".
        Starting from smallest index, the next value can be calculated by multiple 
        the current value by itself.
        """
        if n == 0:
            #print 'return 1'
            return 1.
        if x == 0:
            #print 'return 2'
            return 0.
        if x == 1:
            #print 'return 3'
            return 1.
        if x == -1:
            if n%2 == 0:
                #print 'return 4'
                return 1.
            else:
                #print 'return 5'
                return -1.

        # we want to make it as log(n)
        if n > 0:
            c = n
        else:
            c = (-1)*n

        log_n_list = [c]
        while True:
            c = c/2
            if c == 0:
                break
            log_n_list.append(c)

        log_n_list.reverse()
        r = x
        for i in range(len(log_n_list)-1):
            r = r*r
            if log_n_list[i+1] == log_n_list[i]*2+1:
                # for example, [15, 7, 3, 1], we need multiple one more 'x'
                r *= x

        if n > 0:
            return r
        if n < 0:
            return 1./r



if __name__ == '__main__':
    import math
    t = [(0,0), (-1, -234234234435456), (-1, 234324342345), (1, 2342323545), \
        (0, 234234234234), (242543543543,0), (2, 5), (2, 1000), (23,56), \
        (34, 21), (34,-21), (-21, 78), (-47,-39), (0.00001, 2147483647), (8.88023, 3)]

    for ele in t:
        print ele[0], ele[1], Solution().pow(ele[0], ele[1]), math.pow(ele[0], ele[1])
        print '*'*20