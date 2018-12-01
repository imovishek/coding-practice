/*
Suffix array O(n lg^2 n)
LCP table O(n)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

	const int MAXN = 1 << 21;
	char S[MAXN];
	int N, gap;
	int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

	bool sufCmp(int i, int j)
	{
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
	}

	void buildSA()
	{
		N = strlen(S);
		REP(i, N) sa[i] = i, pos[i] = S[i];
		for (gap = 1;; gap *= 2)
		{
			sort(sa, sa + N, sufCmp);
			REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
			REP(i, N) pos[sa[i]] = tmp[i];
			if (tmp[N - 1] == N - 1) break;
		}
	}

	void buildLCP()
	{
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
			++k;
			lcp[pos[i]] = k;
			if (k)--k;
		}
		lcp[N - 1] = 0;
	}

/*
Suffix array implementation ends here.
*/

#define INF 0x3f3f3f3f
#define DEBUG 0

// The suffixes which starts with the string C.
// That is, C is a prefix of S[i] if cmatch[i] == 1
int cmatch[MAXN];
// The maximum length of a suffix that does not contain C as a subtring.
int cdist[MAXN];

int main(int argc, char const *argv[]) {
	int t, a, b, c, i, x, y, r, l;

	scanf("%d\n", &t);
	while(t--) {
		memset(cmatch, 0, sizeof(cmatch));
		memset(cdist, 0x3f, sizeof(cdist));

		// Input the strings A, B, and C and store them in S.
		// S = A + '$' + B + '#' + C
		scanf("%s", S);
		a = strlen(S);
		S[a] = '$';
		scanf("%s", S + a + 1);
		b = strlen(S) - a - 1;
		S[a + b + 1] = '#';
		scanf("%s", S + a + b + 2);
		c = strlen(S) - a - b - 2;

		// if (DEBUG)
		// 	printf("%s %d %d %d\n", S, a, b, c);

		// The Suffix Array for S is built on sa
		buildSA();
		// The LCP for S is built on lcp
		buildLCP();

		// if (DEBUG)
		// 	for (i = 0; i < a + b + c + 2; i++)
		// 		printf("%d %d\n", sa[i], lcp[i]);

		// Compute the lexigraphical order of C in the Suffix Array
		for (i = 0; i < a + b + c + 2; i++)
			if (sa[i] == a + b + 2 /* The starting index of C in S */)
				break;

		// All suffixes which starts with C appear in a contiguous block in sa.
		// Also, all of them has lcp value greater than or equal to length of C.
		// Mark all of them in cmatch array.
		cmatch[sa[i]] = 1;
		for (; lcp[i] >= c; i++)
			cmatch[sa[i + 1]] = 1;

		// Compute the maximum length of substring starting from each index That
		// does not include C as a substring.
		// To do that we go through S in reverse order tracking the last time a
		// match with C was found in x.
		x = a + b + 2;
		for (i = a + b; i >= 0; i--) {
			if (cmatch[i])
				x = i;
			cdist[i] = x - i + c - 1;
		}

		// if (DEBUG)
		// 	for (i = 0; i < a + b + c + 2; i++)
		// 		printf("%d %d\n", cmatch[i], cdist[i]);

		// Check all pairs of suffixes in chronological order skipping suffixes of C
		for (i = r = 0; i < a + b + c + 1; i++) {
			x = sa[i];
			// Skip this iteration if the suffix start after B.
			if (x >= a + b + 1)
				continue;

			// Skip all suffixes of C.
			l = lcp[i];
			y = sa[i + 1];
			for (; i + 1 < a + b + c + 2; i++) {
				l = min(l, lcp[i]);
				y = sa[i + 1];
				if (y < a + b + 1)
					break;
			}

			if(DEBUG)
				printf("%d %d %d %d\n", i, x, y, l);

			// Sort x and y.
			if (x > y)
				swap(x, y);

			// Check suffix starting at x is in A and starting at y in B.
			if (x < a && y >= a + 1 && y < a + b + 1)
				r = max(r, min(l, cdist[x]));
		}

		// printf("%s\n", S);
		printf("%d\n", r);
	}

	return 0;
}
