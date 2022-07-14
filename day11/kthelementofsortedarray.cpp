int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {int i=0, j=0, element;
       
       while(i<n && j<m)
        {
            if(arr1[i] < arr2[j] )
              {
                  element=arr1[i];
                  k--, i++;
              }
            else
              {
                  element=arr2[j];
                  k--, j++;
              }
              
              if(k==0)
               return element;
        }
        if(i<n)
          return arr1[i+k-1];
        if(j<m)
          return arr2[j+k-1];
   }