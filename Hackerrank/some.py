# your code goes here
a = input("")
while a>=1:
	n = int(input(""))
	cnt = 0
	while n>=1:
		n/=2
		cnt += 1
	print(cnt)
	if(cnt%2==1):
		print("Richard")
	else:
		print("Louise")
	a-=1
		