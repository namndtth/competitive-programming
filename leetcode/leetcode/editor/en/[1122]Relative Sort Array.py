from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        not_exist = []

        cnt = {}
        for x in arr1:
            if x in arr2:
                cnt[x] = cnt.get(x, 0) + 1
            else:
                not_exist.append(x)

        ans = []
        for x in arr2:
            ans.extend([x] * cnt[x])
        ans.extend(sorted(not_exist))

        return ans


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.relativeSortArray(arr1=[1, 2], arr2=[2])
