from typing import List

# leetcode submit region begin(Prohibit modification and deletion)
import sys

sys.set_int_max_str_digits(5010)


def isGreaterOrEqual(a: str, b: str):
    return int(a) >= int(b)


class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        target_plus_1 = target + 1

        dp = ['0'] * target_plus_1

        for i in range(target_plus_1):
            for num, c in enumerate(cost, 1):
                if i < c:
                    continue

                num_str = str(num)
                if i > c:
                    num_str = dp[i - c] + str(num) if dp[i - c] != '0' else '0'

                if isGreaterOrEqual(num_str, dp[i]):
                    dp[i] = num_str

        return dp[target]


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.largestNumber(cost=[1, 1, 1, 1, 1, 1, 1, 1, 1], target=5000)
