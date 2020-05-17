
def fac(n):
	res = 1
	for i in range(n):
		res = res * (i+1)
	return res

MOD = 1000000007

while (True):
	try :
		line = input()
		m = {}
		for c in line:
			if c not in m:
				m[c] = 0
			m[c] = m[c] + 1;

		a = fac(len(line))
		b = 1
		for key in m:
			b = b * fac(m[key])
		print((a//b) % MOD)
	except EOFError:
		break;