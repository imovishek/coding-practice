import java.io.*;
import java.util.*;

public class E {
	long mod;

	class MedInt {
		long a;
		long b;

		public MedInt(long x) {
			this.a = x / mod;
			this.b = x % mod;
		}
		public MedInt(long a, long b) {
			this.a = a;
			this.b = b;
		}

		public MedInt addEq(MedInt r) {
			a += r.a;
			b += r.b;
			if (b >= mod) {
				b -= mod;
				a++;
			}
			return this;
		}
		public MedInt add(MedInt r) {
			return new MedInt(a, b).addEq(r);
		}
		public MedInt mul(int n) {
			MedInt res = new MedInt(0);
			MedInt t = new MedInt(a, b);
			for (int i = n; i > 0; i >>= 1) {
				if (i % 2 == 1) {
					res.addEq(t);
				}
				t.addEq(t);
			}
			return res;
		}

		@Override
		public String toString() {
			return "[" + new Long(a).toString() + ", " + new Long(b).toString() + "]";
		}
	}

	MedInt[] pow10;

	MedInt getF(long n) {
		int a_n = 0;
		int[] a = new int[20];
		for (long i = n; i > 0; i /= 10) {
			a[a_n++] = (int)(i % 10);
		}

		int sum = 0;
		MedInt res = new MedInt(0);
		for (int i = a_n - 1; i >= 0; i--) {
			res.addEq(pow10[i].mul(sum * a[i] + a[i] * (a[i] - 1) / 2));
			if (i > 0) {
				res.addEq(pow10[i - 1].mul(45 * i * a[i]));
			}
			sum += a[i];
		}
		return res;
	}

	InputReader re = new InputReader(System.in);
	PrintWriter wr = new PrintWriter(System.out);

	public void main() {
		mod = re.nextLong();

		long[] bot = new long[19 * 9];
		for (int i = 0; i < 19 * 9; i++) {
			bot[i] = -1;
		}

		pow10 = new MedInt[19];
		pow10[0] = new MedInt(1);
		for (int i = 1; i <= 18; i++) {
			pow10[i] = pow10[i - 1].mul(10);
		}

		int lim = 0;
		while (true) {
			long le = 1, ri = 4000000000000000001l;
			while (le != ri) {
				long mid = (le + ri) / 2;
				if (getF(mid).a < lim) {
					le = mid + 1;
				} else {
					ri = mid;
				}
			}
			int r = (int)getF(le).b;
			if (bot[r] == -1) {
				bot[r] = le;
			} else if (bot[r] != le) {
				wr.printf("%d %d\n", bot[r], le - 1);
				break;
			}

			lim++;
		}

		wr.close();
	}

	static public void main(String[] args) {
		new E().main();
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
	public long nextLong() {
		return Long.parseLong(next());
	}
}
