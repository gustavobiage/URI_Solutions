def fac(n):
	res = 1
	for i in range(n):
		res = res * (i+1)
	return res

while (1):
	try:
		line = input().split()
		N = int(line[0])
		M = int(line[1])
		print(fac(N) + fac(M))
	except EOFError:
		break

