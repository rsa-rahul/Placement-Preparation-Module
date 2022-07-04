class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>vec;
        sort(intervals.begin(),intervals.end());
        int res=0;
        for(int i=1;i<intervals.size();++i){
            if(intervals[res][1]>=intervals[i][0]){
                intervals[res][0]=min(intervals[res][0],intervals[i][0]);
                intervals[res][1]=max(intervals[res][1],intervals[i][1]);
            }else{
                res++;
                swap(intervals[res],intervals[i]);
            }
        }
        for(int j=0;j<=res;++j){
            vec.push_back({intervals[j][0],intervals[j][1]});
        }
        return vec;
    }
};