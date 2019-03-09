class Solution {
    func maxIncreaseKeepingSkyline(_ grid: [[Int]]) -> Int {
        let n = grid.count
        var maxRow = [Int](repeating: 0, count: n)
        var maxCol = [Int](repeating: 0, count: n)
        var ans = 0
        for r in 0 ..< n {
            for c in 0 ..< n {
                maxRow[r] = max(maxRow[r], grid[r][c])
                maxCol[c] = max(maxCol[c], grid[r][c])
            }
        }
        for r in 0 ..< n {
            for c in 0 ..< n {
                let mn = min(maxRow[r], maxCol[c])
                ans += mn - grid[r][c]
            }
        }
        return ans
    }
}
