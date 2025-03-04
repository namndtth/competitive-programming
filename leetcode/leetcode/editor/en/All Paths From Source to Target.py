from typing import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def __init__(self):
        self.graph = [[]]
        self.n = 0
        self.ans = []
        self.path = []

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.graph = graph
        self.n = len(graph)
        self.dfs(0)
        return self.ans

    def dfs(self, u: int):
        self.path.append(u)

        if u == self.n - 1:
            self.ans.append(list(self.path))
            return

        for v in self.graph[u]:
            self.dfs(v)
            self.path.pop(-1)


# leetcode submit region end(Prohibit modification and deletion)
sol = Solution()
print(sol.allPathsSourceTarget([[4, 3, 1], [3, 2, 4], [3], [4], []]))
