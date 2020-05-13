def isBissexto(n):
	if (n >= 400 and n % 400 == 0 or n % 4 == 0 and n % 100 != 0):
		return 1;
	return 0;

def isBulukulu(n, bs):
	if (bs and n % 55 == 0):
		return True;
	return False;

def isHuluculu(n):
	if n % 15 == 0:
		return True;
	return False;

def eval(n):
	prt = True
	bs = isBissexto(n);
	if bs:
		print("This is leap year.")
		prt = False

	if isHuluculu(n):
		print("This is huluculu festival year.")
		prt = False
	
	if isBulukulu(n, bs):
		print("This is bulukulu festival year.")
		prt = False
	
	if prt:
		print("This is an ordinary year.")


first = True

while (True):
	try:
		N = int(input())
		if first:
			first = False
		else:
			print("")
		eval(N)
	except EOFError:
		break;

