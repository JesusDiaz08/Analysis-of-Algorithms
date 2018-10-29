#include <iostream>
#include <climits>

using namespace std;
typedef long long int lli;

lli max_Crossing_Sum(lli arr[], lli middle, lli n){
    
    // Minimum value of a integer is initialized 
    lli left_sum = INT_MIN, right_sum = INT_MIN;
    lli sum = 0;
    
    // Crossing find the maximum element into right array
    for(lli i = middle; i < n; i++){
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    sum = 0;

    // Crossing find the maximum element into right array
    for(lli i = (middle - 1); i >= 0; i--){
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    return left_sum + right_sum;
}

/*  ==============================================
    ============= DIVIDE AND CONQUER =============
    @name: maxSubArraySum

    @param: int arr[]: Array with all whole elements.
    @param: int n: Length of array
    
    @return: Maximum sum of subarrays

    @compleity: o( n*log(n) )
    ===============================================
    ===============================================
*/
lli maxSubArraySum(lli arr[], lli n){
    if(n == 1) return arr[0];                       //Base case

    lli middle = n >> 1;                            // Middle point
    lli left_MSS = maxSubArraySum(arr, middle);     // Recursive call left side
    lli rigth_MSS = maxSubArraySum( arr + middle,   // Recursive call right side
                                    n - middle);    

    lli cross = max_Crossing_Sum(arr, middle, n);
    lli ans = max( left_MSS, rigth_MSS );

    return max( ans, cross );
}


int main(){
    lli N, i = 0;
    cin >> N;
    lli arr[N];
    for( ; i < N; i++)
        cin >> arr[i];

    lli maxSuma = maxSubArraySum(arr, N);

    cout << maxSuma << "\n";
}