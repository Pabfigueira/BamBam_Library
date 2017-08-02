/*Algoritmo de Tarjan:
Encontra pontes em um grafo
Meio cagado, mas a ideia ta certa
de acordo com o MP heuhuehuehue
PARA ACHAR PONTO DE ARTICULAÇÃO:
olhar para os filhos de u;
Basta ver se algum dos filhos
vai para estritamente antes de u
(usando mnivel)
*/
//TESTADO = TRUE

vi grafo[maxn], pontes[maxn];
int nivel[maxn], mnivel[maxn];

void dfs(int u, int h=0) {
	nivel[u]=h;
	for(int v: grafo[u]) {
		if(nivel[v]==-1) {
			dfs(v, h+1);
		}
	}
}

void dfs_t(int u) {
	mnivel[u]=nivel[u];
	for(int v: grafo[u]) {
		if(nivel[v]==nivel[u]-1)	continue;
		if(nivel[v]==nivel[u]+1) {
			dfs_t(v);
		}
		mnivel[u]=min(mnivel[u], mnivel[v]);
		if(mnivel[v]>nivel[u]) {
			cout<<"Ponte: "<<u<<' '<<v<<endl;
		}
	}
}

void tarjan(int raiz) {
	memset(nivel, -1, sizeof(nivel));
	dfs(raiz);
	memset(mnivel, inf, sizeof(mnivel));
	dfs_t(raiz);
}