class Solution:
    def maximalSquare(self, matrix: [[str]]) -> int:
        if len(matrix) == 0:
            return 0
        mat = [[int(col) for col in row] for row in matrix]
        n, m = len(mat), len(mat[0])
        ret = 0
        for row in mat:
            for col in row:
                ret = max(ret, col)

        for i in range(n - 2, -1, -1):
            for j in range(m - 2, -1, -1):
                if mat[i][j] == 1:
                    mat[i][j] = min(mat[i + 1][j], mat[i][j + 1], mat[i + 1][j + 1]) + 1
                    ret = max(ret, mat[i][j])
        return ret * ret


sol = Solution()
print(sol.maximalSquare([["0", "1"], ["1", "0"]]))
print(sol.maximalSquare(["0"]))
print(
    sol.maximalSquare(
        [
            ["1", "0", "1", "0", "0"],
            ["1", "0", "1", "1", "1"],
            ["1", "1", "1", "1", "1"],
            ["1", "0", "0", "1", "0"],
        ]
    )
)
