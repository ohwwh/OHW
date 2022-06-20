from queue import PriorityQueue
import math

N, L = map(int, input().split())

arr = list(map(int, input().split()))

q = []

D = math.inf


D = 2
if arr[1] == 2 