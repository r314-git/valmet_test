import random
n = 1000000
M = 1000000000000000
print(n)
for i in range(0, 555555):
	print(random.randint(1, 18446744072), random.randint(1, 999999999), random.randint(-1000, 1000), random.randint(0, 2))

for i in range(555555, n):
	print(random.randint(1, M), random.randint(1, M), random.randint(-M, M), random.randint(-M, M))
		