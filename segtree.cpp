/*SegTree padrao, de soma
se vc quer uma segtree que nao seja de soma
e nao sabe onde mudar, voce nao merece usar
essa estrutura... heuheuehuehue */
//TESTADO = TRUE

class SegTree {
	private: int n;
		vector < ll > st;

		int meio(int e, int d) {
			return (e+d)/2;
		}

		void build(int p, int e, int d) {
			if(e==d) {
				st[p]=v[e];
			}
			else {
				int m=meio(e, d);
				build(p+p, e, m);
				build(p+p+1, m+1, d);
				st[p]=st[p+p]+st[p+p+1];
			}
		}

		void update(int p, int e, int d, int pos, int val) {
			if(e>pos or d<pos)	return;

			if(e==pos and d==pos) {
				st[p]=val;
			}
			else {
				int m=meio(e, d);
				update(p+p, e, m, pos, val);
				update(p+p+1, m+1, d, pos, val);
				st[p]=st[p+p]+st[p+p+1];
			}
		}

		ll query(int p, int e, int d, int i, int j) {
			if(e>j or d<i)	return 0;
			if(e>=i and d<=j)	return st[p];
			int m=meio(e, d);
			ll q1=query(p+p, e, m, i, j);
			ll q2=query(p+p+1, m+1, d, i, j);
			return q1+q2;
		}

	public:		
		SegTree(int N) {
			n=N;
			st.assign(4*n, 0);
			build(1, 0, n-1);
		}

		void update(int pos, int val) {
			update(1, 0, n-1, pos, val);
		}

		ll query(int i, int j) {
			return query(1, 0, n-1, i, j);
		}
};