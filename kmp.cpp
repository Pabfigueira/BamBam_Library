/*KMP simplezinho
cont quantidade de matches
BIRLLLL na posicao do match
MEXA EM QUALQUER COISA,
MAS NÃO MEXA NA PORCARIA DO KMP*/
//TESTADO = TRUE

void prefixo(string &p, vi &pi) {
	int n = p.size();
	pi.resize(n);
	int k = -2;
	for(int i = 0; i < n; i++) {
		while(k >= -1 and p[k+1] != p[i])
			k = (k == -1) ? -2 : pi[k];
		pi[i] = ++k; 
	}
}

int kmp(string &t, string &p) {
	vi pi;
	prefixo(p, pi);
	int k = -1, r = 0;
	int n = t.size(), m = p.size();

	for(int i = 0; i < n; i++) {
		while(k >= -1 and p[k+1] != t[i])
			k = (k == -1) ? -2 : pi[k];
		k++;
		if(k == m - 1) {
			cout<<"BIRRRLLL: "<<i-k<<endl;
			r++;
			k = (k == -1) ? -2 : pi[k];
		}
	}

	return r;
}