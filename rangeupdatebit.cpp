/*BIT com range update
faz umas maracutaias e da bem certinho
tem que ser 1-based*/
//TESTADO = TRUE

class RUBit {
	private: int n;
		vll bit1, bit2;

		ll sum(vll &bit, int i) {
			ll r = 0;
			while(i > 0) {
				r += bit[i];
				i -= i&-i;
			}
			return r;
		}

		void add(vll &bit, int pos, ll val) {
			while(pos < n) {
				bit[pos] += val;
				pos += pos&-pos;
			}
		}

	public:
		RUBit(int N) {
			n=N+10;
			bit1.assign(n, 0);
			bit2.assign(n, 0);
		}

		void update(int i, int j, ll val) {
			add(bit1, i, val);
			add(bit1, j+1, -val);
			add(bit2, i, (i-1)*val);
			add(bit2, j+1, -j*val);
		}

		ll sum(int i) {
			return sum(bit1, i)*i - sum(bit2, i);
		}

		ll query(int i, int j) {
			return sum(j) - sum(i-1);
		}
};