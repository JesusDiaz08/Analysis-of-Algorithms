#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;

void print(vii conjunto){
    for(lli j = 0; j < conjunto.size(); j++){
        ii aux = conjunto[j];
        cout << "(x,p): (" << aux.first << "," << aux.second << ")\n";
    }
    cout << "\n";
}

bool compararValor(ii tuplaA, ii tuplaB){
    return tuplaB.first < tuplaA.first;
}

bool compararIndice(ii tuplaA, ii tuplaB){
    return tuplaB.second > tuplaA.second;
}

int main(){
    lli M,N,K,tipo,A,B,x;
    vii conjunto;

    cin >> M >> N >> K;
    
    while(N--)
        cin >> tipo >> A >> B;

    for(lli p = 1; p <= M; p++){
        cin >> x;
        ii tupla(x,p);
        conjunto.push_back(tupla);
    }

    sort(conjunto.begin(), conjunto.end(), compararValor);
    conjunto.erase(conjunto.begin() + K, conjunto.end());
    sort(conjunto.begin(), conjunto.end(), compararIndice);   

    for(lli i = 0; i < K; i++)
        cout << conjunto[i].second << " ";
    
    return 0;
}
