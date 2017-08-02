/*MergeSort Tree
cada nodulo tem um intervalo e guarda
o subvetor correspondente ordenado.
A query responde por quantos numeros em
um intervalo sao maiores ou iguais a um
valor dado.
- Para valores menores ou iguais, mudar
o retorno da query.
- Para valores estritamente maiores ou
estritamente menores, passar x+1.
- Para descobrir o k-esimo maior valor
em um intervalo, fazer busca binaria no
valor usando a query como parametro*/
//TESTADO = TRUE

class MergeSortTree {
	private: int n;
		vvi tree;

		int meio(int e, int d) {
			return (e+d)/2;
		}

		void mergesort(vi &v, vi &v1, vi &v2) {
			int i=0, j=0, n=v1.size(), m=v2.size();
			while(i<n and j<m) {
				if(v1[i] < v2[j])	v.pb(v1[i++]);
				else	v.pb(v2[j++]);
			}
			while(i<n)	v.pb(v1[i++]);
			while(j<m)	v.pb(v2[j++]);
		}

		void build(int p, int e, int d) {
			if(e == d)	tree[p].pb(v[e]);
			else {
				int m = meio(e, d);
				build(p+p, e, m);
				build(p+p+1, m+1, d);
				mergesort(tree[p], tree[p+p], tree[p+p+1]);
			}
		}

		int query(int p, int e, int d, int i, int j, int x) {
			if(e > j or d < i)	return 0;
			else if(e >= i and d <= j) {
				vi::iterator it1=tree[p].begin(), it2=tree[p].end();
				int qntmenor = lower_bound(it1, it2, x) - it1;
				return d-e+1-qntmenor;
			}
			else {
				int m = meio(e, d);
				int q1 = query(p+p, e, m, i, j, x);
				int q2 = query(p+p+1, m+1, d, i, j, x);
				return q1 + q2;
			}
		}

	public:
		MergeSortTree(int N) {
			n=N;
			tree.resize(4*n);
			build(1, 0, n-1);
		}

		int query(int i, int j, int x) {
			return query(1, 0, n-1, i, j, x);
		}
};