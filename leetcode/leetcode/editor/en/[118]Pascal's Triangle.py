from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            print(1)
            return [[1]]

        ans = [[1], [1, 1]]
        for i in range(2, numRows):
            row = [1]
            for j in range(0, len(ans[i - 1]) - 1):
                row.append(ans[i - 1][j] + ans[i - 1][j + 1])
            row.append(1)
            ans.append(row)
        print(ans)
        return ans


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.generate(1)
