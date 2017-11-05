#define gc getchar_unlocked
#define pc putchar_unlocked

inline  int get_num()                     
{
	register  int n=0,c=gc();
	while(c<'0'||c>'9')
		c=gc();
	while(c<='9'&&c>='0')
	{
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}

inline void print_num(int a)
{
 	int i=0;
	char S[20];
	while(a>0)
	{
	    S[i++]=a%10+'0';
		a=a/10;
	}
	--i;
	while(i>=0)
		pc(S[i--]);
	pc('\n');
}
