#include <iostream>
#include <climits>

using namespace std;
typedef long long int lli;

/*  ================================================
    ================ BRUTE FORCE v2 ================
    @name: max_Subarray_Sum

    @param: int arr[]: Array with all whole elements.
    @param: int n: Length of array
    
    @return: Maximum sum of subarrays

    @compleity: O( n^2 )
    ================================================
    ================================================
*/
lli max_Subarray_Sum(lli arr[], lli n){     

    lli ans = INT_MIN;
    for( lli start_index = 0; start_index < n; start_index++){  //O(n)
        lli sum = 0;
        for( lli sub_array_size = 1; sub_array_size <= n; sub_array_size++){ //O(n)
            if( (start_index + sub_array_size ) > n )  //El subarreglo supera la cota
                break;
            
            sum += arr[ start_index + sub_array_size - 1]; //El ultimo elemento del nuevo arreglo

            ans = max( ans, sum );
        }
    }

}