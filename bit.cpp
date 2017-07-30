/*Fenwick tree padrao de soma
muda em log, query em log
TEM QUE SER 1-BASED*/
//TESTADO = TRUE

class BIT {
	private: int n;
		vector < ll > bit;

		ll sum(int pos) {
			ll r=0;
			while(pos>0) {
				r+=bit[pos];
				pos-=pos&-pos;
			}
			return r;
		}

	public:
		BIT(int N) {
			n=N+10;
			bit.assign(n, 0);
		}

		void assign(int N) {
			n=N+10;
			bit.assign(n, 0);
		}

		void add(int pos, ll val) {
			while(pos<=n) {
				bit[pos]+=val;
				pos+=pos&-pos;
			}
		}

		ll query(int i, int j) {
			return sum(j)-sum(i-1);
		}
};

int main() {
	BIT b(5);

	b.add(1, 1);
	b.add(2, 1);
	b.add(3, 1);
	b.add(4, 1);
	b.add(5, 1);
	
	cout<<b.query(1, 5)<<endl;
}