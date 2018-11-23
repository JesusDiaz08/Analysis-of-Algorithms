#include <stdio.h>
#include <algorithm>
using namespace std;

int LIS( int *A, int n){
    int lis[n];
    lis[0] = 1;

    for(int j = 1 ; j < n; j++){
        lis[j] = 1;
        for(int k = 0 ; k < j; k++)
            if( A[j] > A[k] && lis[j] < lis[k] + 1)
                lis[j] = lis[k] + 1;  
    }

    return *max_element(lis, lis+n); 
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&A[i]); 
    
    printf("%d\n",LIS(A, n)); 

    return 0;
}
