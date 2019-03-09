class Solution {
    func rangeSumBST(_ root: TreeNode?, _ L: Int, _ R: Int) -> Int {
        guard let root = root else {
            return 0
        }
        if root.val < L {
            return rangeSumBST(root.right, L, R)
        }
        if root.val > R {
            return rangeSumBST(root.left, L, R)
        }
        return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R)
    }
}
