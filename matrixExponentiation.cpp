#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define imprime(x, Y)                              \
		for (int X = 0; X < Y; X++) cerr << x[X] << " "; \
cerr << endl;
#define ler freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

vector< vector<ll> > multiply( vector< vector<ll> > matrizA, vector< vector<ll> > matrizB ) {
    ll i, j, k, n = matrizA.size();

    vector< vector<ll> > res(n, vector<ll>(n,0));
    
    for( i=0; i<n; i++ ) {
        for( j=0; j<n; j++ ) {
            
            for( k=0; k<n; k++ ) {
                res[i][j] += matrizA[i][k] * matrizB[k][j];  
            }

        }
    } 
     
    return res;
} 


vector< vector<ll> > eleva( vector< vector<ll> > matrizA, ll num ) {
    if( num == 0 ) {
        ll i, j, n = matrizA.size();

        vector< vector<ll> > matriz(n,vector<ll>(n,0));


        for( i=0; i<n; i++ ) {
            for( j=0; j<n; j++ ) {
                if( i==j ) matriz[i][j] = 1;
            }
        }
        return matriz;  
    }
    
    if( num%2 == 0 ) {
        return eleva( multiply(matrizA,matrizA), num/2 );    
    } else { 
        return multiply( matrizA, eleva(matrizA,num-1) );
    }
}



int main() {
     

	return 0;
}
