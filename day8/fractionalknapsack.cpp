bool cmp(Item a.Item b)
    {
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr,arr+n,cmp);
       int curr_weight=0;
       double final_val=0.0;
       for(int i=0;i<n;i++){
           if(curr_weight+arr[i].weight<=W){
           curr_weight+=arr[i].weight;
           final_val+=arr[i].value;
           }
           else
           {
               int remain=W-curr_weight;
               final_val+=(arr[i].value/(double)arr[i].weight)*(double)remain;
               break;
           }
       }
     return final_val;  
    }