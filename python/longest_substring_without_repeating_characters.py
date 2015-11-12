class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def lengthOfLongestSubstring(self, s):
        """
        Declare a list to hold characters in current examined substring.
        If next character in s occured in current substring, pop up characters 
        from the beginning of current substring until we poped up the duplicated 
        character.
        """
        hash_list = [False] * 1000 #initilizes a list. The index of the list is the ascii of the character, the value indicates whether this character contains in current examined substring.
        max_len = -1
        r = [] # current examined substring.
        for c in s:
            ascii_of_c = ord(c)
            if hash_list[ascii_of_c]:
                if len(r) > max_len:
                    max_len = len(r)

                while r[0] != c:
                    hash_list[ord(r[0])] = False
                    r.pop(0)
                    
                r.pop(0)
            hash_list[ascii_of_c] = True
            r.append(c)

        if len(r) > max_len:
            max_len = len(r)
        return max_len

if __name__ == '__main__':
    l = ['abcabcbb', 'bbbbbbbbb', '', 'wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco']
    for ele in l:
        print ele, Solution().lengthOfLongestSubstring(ele)