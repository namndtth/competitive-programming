# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = {}
        for c in s:
            cnt[c] = cnt.get(c, 0) + 1

        most = max(cnt, key=lambda x: cnt[x] % 2 != 0)

        ans = cnt[most]
        for k, v in cnt.items():
            if k == most:
                continue

            ans += v if v % 2 == 0 else v - 1

        return ans


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.longestPalindrome("abccccdd")
