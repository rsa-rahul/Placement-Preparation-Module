int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	     int sm[n],
    ans = 0;
    for(int i=0; i<n; i++){
        int res = 0;
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                res = max(res, sm[j]);
            }
        }
        sm[i] = res + arr[i];
        ans = max(ans, sm[i]);
    }
    return ans;
	}  