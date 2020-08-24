lat = 2;
pnt_cnt = 4;
sqr_cnt = 1;
n = int(input());
while n: 
	pnt_cnt += 2*(lat-1)*(lat) + sqr_cnt;
	sqr_cnt = sqr_cnt * 4;
	lat += (lat-1);
	n -= 1;
print(pnt_cnt);
