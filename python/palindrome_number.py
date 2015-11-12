class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False
        if x < 10:
            return True
        if x > 10 and x < 100:
            if x%11 == 0:
                return True
            else:
                return False
        i = 10
        while x/i != 0:
            i *= 10
        i /= 10

        while i > 0:
            #print i
            if x/i != x%(x/10):
                return False
            #print x % i
            x = x % i
            #print x
            x /= 10
            if x < 10:
                return True
            if x > 10 and x < 100:
                if x%11 == 0:
                    return True
                else:
                    return False
            #print x
            i /= 100
            #raw_input()


if __name__ == '__main__':
    a = 1235679844489765321
    #a = 1234321
    a = 233
    print Solution().isPalindrome(a)