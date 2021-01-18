class Solution:
    def findKthLargest(self, nums: [int], k: int) -> int:
        temp = []

        def _binary_search(array, number):
            l, h = 0, len(array) - 1
            while l <= h:
                m = (l + h) // 2
                if array[m] < number:
                    l = m + 1
                else:
                    h = m - 1
            return l

        for num in nums:
            if len(temp) < k:
                idx = _binary_search(temp, num)
                # if idx >= len(temp):
                #     temp.append(num)
                # else:
                #     temp.insert()
                temp.insert(idx, num)
            else:
                if temp[0] >= num:
                    continue
                temp = temp[1:]
                idx = _binary_search(temp, num)
                temp.insert(idx, num)

        return temp[0]


sol = Solution()
print(sol.findKthLargest([3, 2, 1, 5, 6, 4], 2))
print(sol.findKthLargest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))
