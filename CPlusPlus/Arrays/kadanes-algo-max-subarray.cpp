  #include<bits/stdc++.h>
  using namespace std;
  class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
         int sum=0,ans=arr[0];
         for(int i=0;i<n;i++){
             sum+=arr[i];
             sum=max(sum,arr[i]);
             ans=max(ans,sum);
         } 
         return ans;
       
        
    }
};
int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

/*
Using Kadane's algorithm:

Initialize two variables, currSum (current sum) and maxSum (maximum sum).
Run a for loop for whole length of the array.
In each iteration of the for loop - 
Add the arr[i] (current element) to currSum.
Put currSum equal to the maximum of currSum and a[i] (This step is Kadane's algorithm, which states that local_maxima = maximum((local_maxima + current_element), current_element), where local_maxima is the maximum sub array sum before the current_element).
Put maxSum equal to maximum of maxSum and currSum.
Return maxSum.
*/