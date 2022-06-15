N = int(input())
arr = []

for _ in range(N):
	iarr = list(map(int, input().split()))
	arr.append(iarr)

'''def find_max_in_two(arr):
	max = 0
	for i in range(3):
		if i == 0:'''


max(
max(arr[0][0] + arr[1][0], arr[0][0] + arr[1][1]),
max(arr[0][1] + arr[1][0], arr[0][1] + arr[1][1], arr[0][1] + arr[1][2]),
max(arr[0][2] + arr[1][2], arr[0][2] + arr[1][1])
)



sum_max = 0
sum_min = 0

sum_max += max(arr[0])


print(arr)