class Solution {
    var nums: [Int]!
    func constructMaximumBinaryTree(_ nums: [Int]) -> TreeNode? {
        self.nums = nums
        return generate(0, nums.count)
    }
    func generate(_ L: Int, _ R: Int) -> TreeNode? {
        guard L < R else {
            return nil
        }
        var root: TreeNode!
        var idx = -1
        var maxVal = Int.min
        for i in L ..< R {
            if nums[i] > maxVal {
                maxVal = nums[i]
                idx = i
            }
        }
        root = TreeNode(maxVal)
        root.left = generate(L, idx)
        root.right = generate(idx + 1, R)
        return root
    }
}
