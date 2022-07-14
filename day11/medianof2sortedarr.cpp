class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int beg = 0;
        int end = nums1.size();
        while(beg <= end){
            int part1 = (beg + end)/2;
            int part2 = ((nums1.size() + nums2.size() + 1)/2 - part1);
            int maxL1 = part1 == 0 ? INT_MIN : nums1[part1 - 1];
            int minR1 = part1 == nums1.size() ? INT_MAX : nums1[part1];
            int maxL2 = part2 == 0 ? INT_MIN : nums2[part2 - 1];
            int minR2 = part2 == nums2.size() ? INT_MAX : nums2[part2];
            if(maxL1 <= minR2 && maxL2 <= minR1){
                if((nums1.size() + nums2.size())%2 == 0) return double(max(maxL1, maxL2) + min(minR1, minR2))/2;
                else return double(max(maxL1, maxL2));
            }
            else if (maxL1 > minR2) end = part1 - 1;
            else beg = part1 + 1;
        }
        return 1;
    }
};