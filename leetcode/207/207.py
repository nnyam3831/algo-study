class Solution:
    def canFinish(self, numCourses, prerequisites):
        graph = [[] for _ in range(numCourses)]
        visited = [0 for _ in range(numCourses)]
        for x, y in prerequisites:
            graph[y].append(x)

        def _dfs(i):
            # 지금 한 텀 안돌았으면 -1, 다 돌고 끝났으면 1 왜냐하면 사이클은 한 번 도는동안 찾을 수 있음
            if visited[i] == -1:
                return False

            if visited[i] == 1:
                return True

            visited[i] = -1
            for j in graph[i]:
                if not _dfs(j):
                    return False

            visited[i] = 1
            return True

        for i in range(numCourses):
            if not _dfs(i):
                return False

        return True


sol = Solution()
print(sol.canFinish(2, [[1, 0]]))
print(sol.canFinish(2, [[1, 0], [0, 1]]))
print(sol.canFinish(3, [[0, 1], [0, 2], [1, 2]]))
