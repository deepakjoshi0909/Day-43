class Solution {
public:
    void mergeSort(vector<int>& indices, vector<int>& nums, vector<int>& result, int left, int right) {
        if (right - left <= 1) return;

        int mid = left + (right - left) / 2;
        mergeSort(indices, nums, result, left, mid);
        mergeSort(indices, nums, result, mid, right);

        vector<int> temp;
        int i = left, j = mid;
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                result[indices[i]] += (j - mid);
                temp.push_back(indices[i++]);
            } else {
                temp.push_back(indices[j++]);
            }
        }

        while (i < mid) {
            result[indices[i]] += (j - mid);
            temp.push_back(indices[i++]);
        }

        while (j < right) {
            temp.push_back(indices[j++]);
        }

        for (int k = left; k < right; ++k) {
            indices[k] = temp[k - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<int> indices(n, 0);
        
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        mergeSort(indices, nums, result, 0, n);
        return result;
    }
};
