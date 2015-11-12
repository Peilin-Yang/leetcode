class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        """
        if the lowest digit is 9, iterate make digits as 0 until we get a non 9.
        If we reach the head, insert 1 before the list.
        """
        if digits[-1] == 9:
            found_non_9 = False
            for i in reversed(range(len(digits))):
                if digits[i] == 9:
                    digits[i] = 0
                else:
                    digits[i] += 1
                    found_non_9 = True
                    break
            if not found_non_9:
                digits.insert(0, 1)
        else:
            digits[-1] += 1
        return digits


if __name__ == '__main__':
    t = [9, 9, 9, 9, 9]

    print Solution().plusOne(t)
