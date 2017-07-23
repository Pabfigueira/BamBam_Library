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


// Calculate the sum of two strings
string soma( string one, string two ) {

    if( one.size() < two.size() ) swap(one,two); 

    reverse(one.begin(),one.end());
    reverse(two.begin(),two.end());

    int eleva, i, tam = two.size();
        
    eleva = 0;
    string res = "";

    for( i=0; i<tam; i++ ) {
        if( (two[i]-'0') + (one[i]-'0') + eleva < 10 ) {
            res += ((two[i]-'0') + (one[i]-'0') + eleva + '0');
            eleva = 0;
        } else { 
            res += (((two[i]-'0')+(one[i]-'0')+eleva)%10)+'0';
            eleva = ((two[i]-'0')+(one[i]-'0')+eleva)/10;
        }
    }
    tam = one.size();
    for( ;i<tam;i++ ) {
        if( (one[i]-'0') + eleva < 10 ) {
            res += ((one[i]-'0') + eleva + '0');
            eleva = 0;
        } else {
            res += (((one[i]-'0')+eleva)%10)+'0';
            eleva = ((one[i]-'0')+eleva)/10;
        }
    }
    if( eleva ) (res+= eleva+'0');
    reverse(res.begin(),res.end());
    return res;
}


// Divide string one by number
string divide( string one, ll number ) {
    ll i, sobra, tam = one.size();
    string res, fim;  

    sobra = 0;

    for( i=0; i<tam; i++ ) {
        sobra *= 10;
        sobra += (one[i] - '0');
        if( sobra >= number ) {
            res += ((sobra/number)+'0');
            sobra %= number; 
        } else if( i!=0 ) {
            res += '0';
        }
    }
    if( res.size() == 0 ) res = "0";
    return res;
}

// Verify if one is greater than two
bool isGreater( string one, string two ) {  
    if( one.size() > two.size() ) return true;
    if( one.size() < two.size() ) return false;
    
    int tam = one.size();

    for( int i=0; i<tam; i++ ) {
        if( one[i] > two[i] ) return true;
        if( one[i] < two[i] ) return false;
    }  
    return false;
}


int main() {

    return 0;
}
