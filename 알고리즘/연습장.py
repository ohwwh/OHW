import sys

lst1 = list(map(int, sys.stdin.readline().split()))
lst2 = list(map(int, sys.stdin.readline().split()))
lst3 = list(map(int, sys.stdin.readline().split()))
lst4 = list(map(int, sys.stdin.readline().split()))

def type(lst):
    if lst[4] > lst[2] or lst[5] > lst[3]:
        return 'd'
    elif (lst[2] > lst[4] >= lst[0] and lst[5] == lst[3]) or (lst[4] == lst[2] and lst[3] > lst[5] >= lst[1]):
        return 'b'
    elif lst[4] == lst[2] and lst[5] == lst[3]:
        return 'c'
    elif lst[4] < lst[0] and lst[5] == lst[3]:
        if lst[6] < lst[0]:
            return 'd'
        elif lst[6] == lst[0]:
            return 'c'
        elif lst[6] > lst[0]:
            return 'b'
    elif lst[5] < lst[1] and lst[4] == lst[2]:
        if lst[7] < lst[1]:
            return 'd'
        elif lst[7] == lst[1]:
            return 'c'
        elif lst[7] > lst[1]:
            return 'b'

