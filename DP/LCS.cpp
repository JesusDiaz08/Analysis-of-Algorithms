#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B, int n, int m){
    int L[n + 1][m + 1];

    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            
            if( i == 0 && j == 0) // Caso base
                L[i][j] = 0;
            else if(A[i - 1] == B[j - 1])
                L[i][j] = 1 + L[ i - 1][ j - 1];
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[n][m];
}


int main(){

    return 0;
}