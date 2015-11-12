# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def __str__(self):
        '''converting the list to a string'''
        r = []
        while True:
            r.append(str(self.val))
            self = self.next
            if not self:
                break
        return '->'.join(r)

    def add_node(self, x):
        a = ListNode(x)
        #print a
        a.next = self
        self = a
        return self


class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        carry = 0
        r = []
        while l1 or l2:
            s = 0
            if l1:
                #print 'l1:'+str(l1.val)
                s += l1.val
                l1 = l1.next
            if l2:
                #print 'l2:'+str(l2.val)
                s += l2.val
                l2 = l2.next

            s += carry
            this_bit = s%10
            carry = s/10

            r.insert(0, this_bit)

        if carry > 0:
            r.insert(0, carry)

        r_link = None
        for i in range(len(r)):
            if i == 0:
                r_link = ListNode(r[i])
            else:
                tmp = ListNode(r[i])
                tmp.next = r_link
                r_link = tmp
        return r_link


if __name__ == '__main__':
    l1 = ListNode(5).add_node(4).add_node(3)
    l2 = ListNode(5).add_node(6).add_node(4)
    #l1 = ListNode(5)
    #l2 = ListNode(5)
    #l1 = ListNode(8).add_node(1)
    #l2 = ListNode(0)
    print l1, l2
    print Solution().addTwoNumbers(l1, l2)