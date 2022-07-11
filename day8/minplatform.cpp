int findPlatform(int arr[], int dep[], int n)
    {
    sort(arr,arr+n);
    sort(dep,dep+n);
    int count=1,ans=1;
    int j=0,i=1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        if(count>ans) ans=count;
    }
    return ans;
    }