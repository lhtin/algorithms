class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums, int start, int end) {
      if (start > end) {
        return nullptr;
      }
      int maxI = start;
      for (int i = start + 1; i <= end; i += 1) {
        if (nums[i] > nums[maxI]) {
          maxI = i;
        }
      }
      TreeNode *left = constructMaximumBinaryTree(nums, start, maxI - 1);
      TreeNode *right = constructMaximumBinaryTree(nums, maxI + 1, end);
      return new TreeNode(nums[maxI], left, right);
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
      return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};