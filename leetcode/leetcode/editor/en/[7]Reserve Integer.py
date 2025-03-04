class Solution(object):
    def reverse(self, x):
        result = int(str(x)[::-1]) if x >= 0 else -int(str(x)[:0:-1])
        if result >= (1 << 32 - 1) or result <= -(1 << 32 - 1):
            result = 0

        return result


s = Solution()
print(s.reverse(-1534236469))
