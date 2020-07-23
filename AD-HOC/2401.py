N = int(input())
divisor = 1
numerador = 1

while (1) :
	try:
		a, b = input().split()
		a = int(a)
		if b == '*':
			numerador = numerador * a
		elif b == '/':
			divisor = divisor * a
	except EOFError:
		break;
print(numerador//divisor)