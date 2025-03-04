# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        length = 0
        char_set = {}
        for i, x in enumerate(s):
            if x in char_set:
                length = i - char_set[x]
                char_set = {k: v for k, v in char_set.items() if v >= char_set[x]}
                char_set[x] = i
            else:
                char_set[x] = i
                length += 1

            ans = max(ans, length)

        return ans


# leetcode submit region end(Prohibit modification and deletion)
sol = Solution()
print(sol.lengthOfLongestSubstring("dvdf"))
