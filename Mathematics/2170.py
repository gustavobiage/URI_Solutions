c = 0
while (True):
	try:
		N, M = input().split()
		if N.find('.'):
			N = float(N)
		else:
			N = int(N)
		if M.find('.'):
			M = float(M)
		else:
			M = int(M)
		
		c += 1
		print("Projeto %d:" % c)
		print("Percentual dos juros da aplicacao: %0.2lf %c" % (100*(M - N)/N, '%'))
		print()
	except EOFError:
		break

