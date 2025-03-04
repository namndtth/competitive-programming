# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        n = len(x)
        i = 0
        j = n - 1
        while i < j:
            if x[i] != x[j]:
                return False
            i += 1
            j -= 1
        return True


# leetcode submit region end(Prohibit modification and deletion)
sol = Solution()
sol.isPalindrome(121)
