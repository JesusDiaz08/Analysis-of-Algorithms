#include <bits/stdc++.h>
using namespace std;

int func_bacterias(int matriz[][], int dp[][], int m, int n){
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            
            if (i == 0 && j == 0)
                dp[i][j] = matriz[i][j];
            else if(j == 0)
                dp[i][j] = dp[i - 1][j] + matriz[i][j];
            else if(i == 0)
                dp[i][j] = dp[i][j - 1] + matriz[i][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matriz[i][j];
               
        }
    }
    return dp[m - 1][n - 1];   
}

int main(){
    int m, n;

    cin >> m >> n;
    int matriz[m][n], dp[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
            dp[i][j] = 0;
        }
    }

    cout << func_bacterias(matriz, dp, m, n) << "\n";

    return 0;
}