n = int(input())
somearray = map(int, raw_input().split())
mul = 1

for i in range(0, n):
	mul = mul * somearray[i]

print mul


