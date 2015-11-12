class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        """
        use a flag to indicate whether we have an additional '1' to add 
        due to sum of lower bit.
        """
        a_list = list(a)
        b_list = list(b)
        longer_list = a_list if len(a_list) > len(b_list) else b_list
        shorter_list = b_list if len(a_list) > len(b_list) else a_list
        longer_list.reverse()
        shorter_list.reverse()
        r = []
        flag = 0
        for i in range(len(longer_list)):
            if i < len(shorter_list):
                s = int(longer_list[i]) + int(shorter_list[i]) + flag
            else:
                s = int(longer_list[i]) + flag

            if s == 3:
                this_bit = 1
                flag = 1
            elif s == 2:
                this_bit = 0
                flag = 1
            elif s == 1:
                this_bit = 1
                flag = 0
            elif s == 0:
                this_bit = 0
                flag = 0
            r.insert(0, str(this_bit))
        if flag == 1:
            r.insert(0, str(1))
        return ''.join(r)


if __name__ == '__main__':
    a = '1111111111'
    b = '1'
    print Solution().addBinary(a, b)