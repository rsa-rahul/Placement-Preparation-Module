class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
 int n = heights.size();
	int ans = 0;
	vector<int> ll(n, -1), rl(n,n);
	int prev;
	for(int i=1;i<n;i++) {
		prev = i-1;
		while(prev != -1 && heights[prev] >= heights[i]) prev= ll[prev];
		ll[i] = prev;
	}
	for(int i = n-2;i>=0;i--) {
		prev=i+1;
		while(prev != n && heights[prev] >= heights[i]) prev = rl[prev];
		rl[i] = prev;
	}
	
	for(int i=0;i<n;i++) {
		
		
		ans = max(ans, heights[i]*(rl[i]-ll[i]-1));
	}
        return ans;
    }

};