/*Algoritmo de Kosaraju para achar componentes conexos.
O vetor cc[] guarda o componente conexo ao qual um vertice
pertence, e cc_atual, no final, vai guardar o numero de
componentes conexos. A funcao kosaraju(int n) ja comprime
e constroi o grafo gcc de componentes conexos*/
//TESTADO = FALSE

vi grafo[maxn], grafot[maxn], gcc[maxn];
int cc[maxn], cc_atual;

void dfs(int u, vb &vis, stack < int > &s) {
	vis[u]=true;
	for(int v: grafo[u])
		if(!vis[v])	dfs(v, vis, s);
	s.push(u);
}

void dfs2(int u, vb &vis) {
	vis[u]=true;
	cc[u]=cc_atual;
	for(int v: grafot[u])
		if(!vis[v])	dfs2(v, vis);

}

void kosaraju(int n) {
	vb vis(n, false);
	stack < int > s;

	for(int i=0; i<n; i++) {
		if(!vis[i])	dfs(i, vis, s);
	}

	fill(vis.begin(), vis.end(), false);
	cc_atual=0;

	while(!s.empty()) {
		int u=s.top();
		s.pop();
		if(vis[u])	continue;
		dfs2(u, vis);
		cc_atual++;
	}

	set < ii > criadas;
	for(int i=0; i<n; i++) {
		for(int j: grafo[i]) {
			if(cc[i]!=cc[j] and !criadas.count(mp(cc[i], cc[j]))) {
				gcc[cc[i]].pb(cc[j]);
				criadas.insert(mp(cc[i], cc[j]));
			}
		}
	}
}