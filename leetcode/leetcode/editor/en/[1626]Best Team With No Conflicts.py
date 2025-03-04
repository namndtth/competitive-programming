from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        inc = sorted(zip(scores, ages), key=lambda x: x[1])


        print(inc)


# leetcode submit region end(Prohibit modification and deletion)

if __name__ == '__main__':
    sol = Solution()
    sol.bestTeamScore([4, 5, 6, 5], [2, 1, 2, 1])
