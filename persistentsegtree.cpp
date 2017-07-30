/*PERSISTENT SEG TREE:
essa eh muito bolada... ensinada pelo rei vazekson vinicius
guarda informacoes pelo tempo e em range;
filhos de uma posicao sao dados em vetor;
tem que multiplicar o sz pelo log do numero de queries;
serve para fazer problemas em que alguma ordem de avaliacao
simula o timestamp.*/
//TESTADO = TRUE


class PersistentSegTree {
	private: int n;
		int next_free_node;
		vi L, R, st, root;

		int meio(int e, int d) {
			return (e+d)/2;
		}

		int build(int e, int d) {
			int node=next_free_node++;
			if(e>=d) {
				st[node]=v[e];
				return node;
			}
			int m=meio(e, d);
			L[node]=build(e, m);
			R[node]=build(m+1, d);
			st[node]=st[L[node]]+st[R[node]];
			return node;
		}

		int update(int oldnode, int e, int d, int pos, int val) {
			int node=next_free_node++;
			if(e==d) {
				st[node]=val;
				return node;
			}
			int m=meio(e, d);
			if(pos<=m) {
				R[node]=R[oldnode];
				L[node]=update(L[oldnode], e, m, pos, val);
			}
			else {
				L[node]=L[oldnode];
				R[node]=update(R[oldnode], m+1, d, pos, val);
			}
			st[node]=st[L[node]]+st[R[node]];
			return node;
		}

		int query(int node, int e, int d, int i, int j) {
			if(e>j or d<i)	return 0;
			if(e>=i and d<=j)	return st[node];
			int m=meio(e, d);
			int q1=query(L[node], e, m, i, j);
			int q2=query(R[node], m+1, d, i, j);
			return q1+q2;
		}

	public:
		PersistentSegTree(int N) {
			n=N;
			next_free_node=0;
			L.resize(30*maxn), R.resize(30*maxn);
			st.resize(30*maxn), root.resize(30*maxn);
			root[0]=build(1, n);
		}

		void update(int tempo, int pos, int val) {
			root[tempo]=update(root[tempo-1], 1, n, pos, val);
		}

		int query(int tempo, int i, int j) {
			return query(root[tempo], 1, n, i, j);
		}
};