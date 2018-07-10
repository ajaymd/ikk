from LinkedList import LinkedList, LinkedListNode


def add_two_integers(ll1, ll2):
    if not ll1 and not ll2:
        return None
    if not ll1:
        return ll2
    if not ll2:
        return ll1

    carry = 0
    curr1 = ll1
    curr2 = ll2

    output_list_head = LinkedListNode(0)
    curr_output = output_list_head
    while curr1 or curr2 or carry:
        curr_val = carry + (curr1.val if curr1 else 0) + (curr2.val if curr2 else 0)
        curr_output.next = LinkedListNode(curr_val % 10)
        carry = int(curr_val / 10)
        curr1 = curr1.next if curr1 else None
        curr2 = curr2.next if curr2 else None
        curr_output = curr_output.next

    return output_list_head.next


n1 = LinkedListNode(1)
n2 = LinkedListNode(0)
n3 = LinkedListNode(9)
n4 = LinkedListNode(9)
n5 = LinkedListNode(9)
n6 = LinkedListNode(9)

n1.next = n2
n2.next = n3
n3.next = n4
n4.next = n5
n5.next = n6


print(LinkedList(n1))

m1 = LinkedListNode(7)
m2 = LinkedListNode(3)
m3 = LinkedListNode(2)

m1.next = m2
m2.next = m3

print(LinkedList(m1))

print(LinkedList(add_two_integers(n1, m1)))