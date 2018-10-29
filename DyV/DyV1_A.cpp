#include <iostream>
#include <climits>

using namespace std;
typedef long long int lli;



/*  ================================================
    ================ BRUTE FORCE v1 ================
    @name: max_Subarray_Sum

    @param: int arr[]: Array with all whole elements.
    @param: int n: Length of array
    
    @return: Maximum sum of subarrays

    @compleity: o( n^3 )
    ================================================
    ================================================
*/
lli max_Subarray_Sum(lli arr[], lli n){     

    lli ans = INT_MIN;
    for(lli sub_array_size = 1; sub_array_size <= n; sub_array_size++){ // O(n)
        for(lli start_index = 0; start_index < n; start_index++){       // O(n)
            if( (start_index + sub_array_size) > n ) break;
            lli sum = 0;

            for(int i = start_index; i < (start_index + sub_array_size); i++ ) //O(n)
                sum += arr[i];
            
            ans = max( ans, sum);
        }
    }

}