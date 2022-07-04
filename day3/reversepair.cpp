class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int* arr = &nums[0];
        return mergesort(arr , 0,nums.size()-1);
    }
    
    int mergesort(int a[] ,int s,int e){
        if(s>=e)return 0;
        int mid = (s+e)/2; 
        int count =  mergesort(a,s,mid) + mergesort(a,mid+1,e);
        int i=s;
        int j = mid+1;
        //counting pairs
        while(j<=e){
            if(a[j]>1073741823)break;
            if(a[j]<-1073741824){count+=(mid+1-s);j++;continue;}
            while(a[i]<=2*a[j] && i<=mid)i++;
            if(i==mid+1)break;
            count+=(mid-i+1); 
            j++;
        }
        //merging the array(sorting)
        int n1 = mid-s+1;
        int n2 = e-mid;
        int *left = new int[n1] , *right = new int[n2]; 
        for (auto i = 0; i < n1; i++)left[i] = a[s + i];
        for (auto j = 0; j < n2; j++)right[j] = a[mid+1+j];
        i=0;j=0;int k =s;
        while(i<n1 && j<n2){
            if(left[i]<right[j]){a[k]=left[i];i++;}
            else{a[k]=right[j];j++;}
            k++;
        }
        while(i<n1){
            a[k] = left[i];
            i++;k++;
        }
        while(j<n2){
            a[k] = right[j];
            j++;k++;
        }
        return count;
        }
};