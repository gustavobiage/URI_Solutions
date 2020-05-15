R = int(input())
MOD = 2**31 -1
def power(a, b, m):
	if (b == 0):
		return 1
	half = power(a, b // 2, m)
	res = half*half
	if (b % 2 != 0):
		res = res * a
	
	res = res % m
	return res

print(power(3, R, MOD))