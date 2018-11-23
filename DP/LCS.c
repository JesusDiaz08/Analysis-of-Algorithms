#include <stdio.h>
#include <string.h>
#define max_string 1000

int max(int a, int b);
int LCS(char *A, char *B, int m, int n);

int LCS(char *A, char *B, int m, int n){
    int L[m + 1][n + 1];
    int i, j;

    for(i = 0; i <= m; i++){
        for(j = 0; j <= n; j++){
            if( i == 0 || j == 0)
                L[i][j] = 0;
            else if(A[i-1] == B[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int max(int a, int b) { 
    return (a > b)? a : b; 
} 

int main(){
    char A[max_string], B[max_string];
    fgets(A, max_string + 2, stdin);
    fgets(B, max_string + 2, stdin);
    int m = strlen(A) - 1, n = strlen(B) - 1;
    printf("%d",LCS(A,B,m,n));
    return 0;
}