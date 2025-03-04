from typing import List


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        cnt = [{chr(i): 0 for i in range(ord('a'), ord('z') + 1)} for _ in range(len(words))]
        mns = {chr(i): (10 ** 9) for i in range(ord('a'), ord('z') + 1)}

        for idx, word in enumerate(words):
            for c in word:
                cnt[idx][c] += 1
            for i in range(ord('a'), ord('z') + 1):
                mns[chr(i)] = min(mns[chr(i)], cnt[idx][chr(i)])

        ans = []
        for k, v in mns.items():
            ans.extend([k] * v)

        return ans


# leetcode submit region end(Prohibit modification and deletion)
if __name__ == '__main__':
    sol = Solution()
    sol.commonChars(["cool", "lock", "cook"])
