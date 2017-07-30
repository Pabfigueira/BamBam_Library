/*Essa segtree eh especial, ela guarda duas informacoes:
a soma em um intervalo, e o prefixo de maior soma comecando
em um cara. Para calcular o prefixo de maior soma a partir de um
cara i, chame st.query(i, n-1)*/
//TESTADO = TRUE

class SegTree {
	private: int n;
		vector < ll > soma, ps;

		int meio(int e, int d) {
			return (e+d)/2;
		}

		void build(int p, int e, int d) {
			if(e==d) {
				soma[p]=ps[p]=0;
			}
			else {
				int m=meio(e, d);
				build(p+p, e, m);
				build(p+p+1, m+1, d);
			}
		}

		void update(int p, int e, int d, int pos, int val) {
			if(e>pos or d<pos)	return;

			if(e==pos and d==pos) {
				soma[p]=ps[p]=val;
			}
			else {
				int m=meio(e, d);
				update(p+p, e, m, pos, val);
				update(p+p+1, m+1, d, pos, val);
				soma[p]=soma[p+p]+soma[p+p+1];
				ps[p]=max(ps[p+p], soma[p+p]+ps[p+p+1]);
			}
		}

		pair < ll, ll > query(int p, int e, int d, int i, int j) {
			if(e>j or d<i)	return mp(0, 0);
			if(e>=i and d<=j)	return mp(soma[p], ps[p]);
			int m=meio(e, d);
			pair < ll, ll > q1=query(p+p, e, m, i, j);
			pair < ll, ll > q2=query(p+p+1, m+1, d, i, j);
			pair < ll, ll > r;
			r.f=q1.f+q2.f;
			r.s=max(q1.s, q1.f+q2.s);
			return r;
		}

	public:		
		SegTree(int N) {
			n=N;
			soma.resize(4*n);
			ps.resize(4*n);
			build(1, 0, n-1);
		}

		void update(int pos, int val) {
			update(1, 0, n-1, pos, val);
		}

		ll query(int i, int j) {
			return query(1, 0, n-1, i, j).s;
		}
};