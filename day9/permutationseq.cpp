class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>nums;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string s="";
        k--;      // 0 based indexing so we have to find the (k-1)th permutation/
        while(1)
        {
            s+=to_string(nums[k/fact]);         // no at the k/fact index is the required no and we iterate for further index.
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0)break;
            
            k=k%fact;
            fact=fact/nums.size();
        }
        return s;
    }
};