class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        """
        Use a hash list to store existing numbers.
        The length of the hash list equals to max_positive+max_negative+1 (0 is categorized to positive)
        Initilize the hash list with 0. (indexes of original list starts from 1)
        Iterate the number list, 
        if 'current number' is positive, 
        make the value of hash list at index 'current number' as the 
        index(starting from 1) of the number list; 
        if 'current number' is negative, 
        make the value of hash list at index (-1)*'current number'+max_positive 
        as the index(starting from 1) of the number list;
        """
        max_positive = -1
        max_negative = 0
        for n in num:
            if n > max_positive:
                max_positive = n
            if n < max_negative:
                max_negative = n
        total = max_positive - max_negative

        possible = [0] * (total+1)
        #print len(possible)

        idx = 1
        for n in num:
            match = target - n
            if match < 0:
                match = (-1)*match+max_positive
            #print n, match, total
            #raw_input()
            if match > total:
                idx += 1
                continue 
            if possible[match] != 0:
                return possible[match], idx
            this_one = n
            if this_one < 0:
                this_one = (-1)*this_one+max_positive
            possible[this_one] = idx
            idx += 1


if __name__ == '__main__':
    a = [1,-3,0,-41,5,36,3,50,13]
    #a = [5,75,25]
    target = 9
    print Solution().twoSum(a, target)