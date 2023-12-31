class Solution:
    def isPossible(self, A, N, M, curr_min):
        studentsRequired = 1
        curr_sum = 0

        for i in range(N):
            if A[i] > curr_min:
                return False

            if curr_sum + A[i] > curr_min:
                studentsRequired += 1
                curr_sum = A[i]

                if studentsRequired > M:
                    return False
            else:
                curr_sum += A[i]

        return True

    def findPages(self, A, N, M):
        sum = 0

        if N < M:
            return -1

        for i in range(N):
            sum += A[i]

        start, end = 0, sum
        result = float('inf')

        while start <= end:
            mid = (start + end) // 2
            if self.isPossible(A, N, M, mid):
                result = min(result, mid)
                end = mid - 1
            else:
                start = mid + 1

        return result
        
        

