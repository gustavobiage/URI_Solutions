while True:
	values_str = input().split()
	a = int(values_str[0])
	b = int(values_str[1])
	c = int(values_str[2])
	if a == 0:
		break

	is_set = False
	is_pair = False
	not_pair = False
	aux = ''
	pair_value = -1
	set_value = -1

	if a == b and b == c:
		is_set = True
		set_value = a
	elif a == b:
		is_pair = True
		pair_value = a
		diff = c
	elif b == c:
		is_pair = True
		pair_value = b
		diff = a
	elif a == c:
		is_pair = True
		pair_value = a
		diff = b
	else:
		not_pair = True
		diff = -1

	if is_set:
		if set_value != 13:
			aux = str(set_value + 1)
			print(' '.join([aux, aux, aux]))
		else:
			print('*')
	elif is_pair:
		increase_pair = False
		if diff == pair_value - 1:
			next_value = diff + 2
		else:
			next_value = diff + 1

		if next_value > 13:
			increase_pair = True
			next_value = pair_value + 1

		aux = str(next_value)

		if next_value > 13:
			print(' '.join(['1', '1', '1']))
		elif increase_pair:
			print(' '.join(['1', aux, aux,]))
		else:
			val_str = str(pair_value)
			if pair_value > next_value:
				print(' '.join([aux, val_str, val_str]))
			else:
				print(' '.join([val_str, val_str, aux]))
	elif not_pair:
		print(' '.join(['1', '1', '2']))

