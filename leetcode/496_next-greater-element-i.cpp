

// code_start

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); ++i)
            umap[nums1[i]] = i;

        stack<int> s;
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); ++i) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                if (umap.count(nums2[s.top()]) > 0) {
                    res[umap[nums2[s.top()]]] = nums2[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

// code_end
