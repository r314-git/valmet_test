import random
n = 1000000
M = 1000000000000000
print(n)
for i in range(n):
	print(random.randint(1, M), random.randint(1, M), random.randint(-M, M), random.randint(-M, M))
		