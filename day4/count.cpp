int Solution::solve(vector<int> &arr, int target)
{
    int n = arr.size();
    int curr_xor = 0;
    int total_subarray = 0;
    unordered_map<int,int> mp;
   
    for(int i=0;i<n;i++)
    {
        curr_xor ^= arr[i];
       
        if(curr_xor == target)
           total_subarray++;
       
        if(mp.count(curr_xor ^ target))
                total_subarray+= mp[curr_xor ^ target];
       
        mp[curr_xor]++;
    }
    return total_subarray;
}