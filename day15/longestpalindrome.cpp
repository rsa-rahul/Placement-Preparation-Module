class Solution {
public:
    string longestPalindrome(string s) {
        //base case
        if(s.length() <= 1) return s;
        int max_len = 1;
        //track the number of characters
        int n = s.length();
        //not required but it is good to keep track of the index
        int start_index = 0, end_index = 0;
        
        //odd length string
        for(int i =0;i<n-1;i++)
        {
            int l = i, r = i;
            while(l>=0 && r < n)
            {
                if(s[l] == s[r]) {
                    l--, r++;
                } else
                    break;
            }
            int len = r-l-1;
            if(len > max_len)
            {
                max_len = len;
                //l has become -1 or l != r so take the previous value before l went out of bounds 
                start_index = l+1;
                end_index = r-1;
            }
        }
        
        
        //even length string
        for(int i =0;i<n-1;i++)
        {
            int l = i, r = i + 1;
            while(l>=0 && r < n)
            {
                if(s[l] == s[r]) {
                    l--, r++;
                } else
                    break;
            }
            int len = r-l-1;
            if(len > max_len)
            {
                max_len = len;
                //l has become -1 or l != r so take the previous value before l went out of bounds 
                start_index = l+1;
                end_index = r-1;
            }
        }
        return s.substr(start_index, max_len);
    }
};