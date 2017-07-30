/*Dinic para fluxo maximo
Fonte: biblioteca de Stanford
"Stanford University ICPC Team Notebook (2015-16)", pg1
se eh de stanford, deve ser bom*/
//TESTADO = TRUE

struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap):
		u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int n;
	vector < Edge > e;
	vvi g;
	vi pt, d;

	Dinic(int N):
		n(N), e(0), g(n), d(n), pt(n) {}

	void AddEdge(int u, int v, ll cap) {
		if(u != v) {
			e.pb(Edge(u, v, cap));
			g[u].pb(e.size()-1);
			e.pb(Edge(v, u, 0));
			g[v].pb(e.size()-1);
		}
	}

	bool bfs(int s, int t) {
		queue < int > q({s});
		d.assign(n, n+1);
		d[s] = true;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(u==t)	return true;
			for(int k: g[u]) {
				Edge &ed = e[k];
				if(ed.flow < ed.cap and d[ed.v] > d[ed.u] + 1) {
					d[ed.v] = d[ed.u] + 1;
					q.push(ed.v);
				}
			}
		}
		return false;
	}

	ll dfs(int u, int t, ll flow = -1) {
		if(u==t or flow==0)	return flow;
		for(int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &ed1 = e[g[u][i]], &ed2=e[g[u][i]^1];
			if(d[ed1.v] == d[ed1.u] + 1) {
				ll aux = ed1.cap - ed1.flow;
				if(flow != -1 and aux > flow)	aux = flow;
				if(ll pushed = dfs(ed1.v, t, aux)) {
					ed1.flow += pushed;
					ed2.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	ll MaxFlow(int s, int t) {
		ll r=0;
		while(bfs(s, t)) {
			fill(pt.begin(), pt.end(), 0);
			while(ll flow = dfs(s, t)) {
				r+=flow;
			}
		}
		return r;
	}
};

int main()
{
	buff;

	Dinic d(6);

	d.AddEdge(0, 1, 1);
	d.AddEdge(0, 2, 1);
	d.AddEdge(1, 3, 1);
	d.AddEdge(1, 4, 1);
	d.AddEdge(2, 3, 1);
	d.AddEdge(3, 5, 1);
	d.AddEdge(4, 5, 1);

	db(d.MaxFlow(0, 5));
	
	return 0;
}