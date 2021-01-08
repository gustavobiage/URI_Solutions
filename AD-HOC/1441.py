while 1:
	hstr = input()
	h = int(hstr)
	if h == 0:
		break
	m = 1
	while h != 1:
		if h > m:
			m = h
		if h % 2 == 1:
			h = 3 * h + 1
		else:
			h = h / 2
		h = int(h)
	print(m)