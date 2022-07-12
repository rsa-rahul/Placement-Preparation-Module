void fun(vector<int> arr, int N,vector<int> &ans)
  {   
      if(N==0)
      {ans.push_back(0);return;}
      fun(arr,N-1,ans);
      int n=ans.size();
      for(int i=0;i<n;i++)
      ans.push_back(ans[i]+arr[N-1]);
  }
   vector<int> subsetSums(vector<int> arr, int N)
   {
       // Write Your Code here
       vector<int> ans;
       fun(arr,N,ans);
       return ans;
   }