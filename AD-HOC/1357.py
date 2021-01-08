def numberFromBraille(c11, c12, c21, c22):
	if c11 == '.' and c12 == '*' and c21 == '*' and c22 == '*':
		# 0
		return 0
	elif c11 == '*' and c12 == '.' and c21 == '.' and c22 == '.':
		#1
		return 1
	elif c11 == '*' and c12 == '.' and c21 == '*' and c22 == '.':
		#2
		return 2
	elif c11 == '*' and c12 == '*' and c21 == '.' and c22 == '.':
		#3
		return 3
	elif c11 == '*' and c12 == '*' and c21 == '.' and c22 == '*':
		#4
		return 4
	elif c11 == '*' and c12 == '.' and c21 == '.' and c22 == '*':
		#5
		return 5
	elif c11 == '*' and c12 == '*' and c21 == '*' and c22 == '.':
		#6
		return 6
	elif c11 == '*' and c12 == '*' and c21 == '*' and c22 == '*':
		#7
		return 7
	elif c11 == '*' and c12 == '.' and c21 == '*' and c22 == '*':
		#8
		return 8
	elif c11 == '.' and c12 == '*' and c21 == '*' and c22 == '.':
		#9
		return 9
	return -1

def brailleLn1(n):
	if n == 1 or n == 2 or n == 5 or n == 8:
		return '*.'
	elif n == 3 or n == 4 or n == 6 or n == 7:
		return '**'
	elif n == 9 or n == 0:
		return '.*'
	return '--'

def brailleLn2(n):
	if n == 1 or n == 3:
		return '..'
	elif n == 2 or n == 6 or n == 9:
		return '*.'
	elif n == 4 or n == 5:
		return '.*'
	elif n == 7 or n == 8 or n == 0:
		return '**'
	return '--'

while True:
	nstr = input()
	n = int(nstr)
	if n == 0:
		break
	t = input()

	if t == 'S':
		ln = [[], [], []]
		m = input()
		for i in range(n):
			ln[0].append(brailleLn1(int(m[i])))
			ln[1].append(brailleLn2(int(m[i])))
			ln[2].append('..')
		print(" ".join(ln[0]))
		print(" ".join(ln[1]))
		print(" ".join(ln[2]))
	else:
		ln = []
		ln.append(input())
		ln.append(input())
		ln.append(input())
		ln[0] = ln[0].split()
		ln[1] = ln[1].split()
		for i in range(n):
			fromBraille = numberFromBraille(ln[0][i][0], ln[0][i][1], ln[1][i][0], ln[1][i][1])
			print(fromBraille, end='')
		print()
