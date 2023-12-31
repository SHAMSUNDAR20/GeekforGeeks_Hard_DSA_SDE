class Solution:
    def maxSubsetXOR(self, arr, N):
        # add code here
        index = 0

        for i in range(31, -1, -1):
            max_ind = index
            max_ele = -2147483648
            for j in range(index, N):
                if (arr[j] & (1 << i)) != 0 and arr[j] > max_ele:
                    max_ele = arr[j]
                    max_ind = j

            if max_ele == -2147483648:
                continue

            arr[max_ind] = arr[index]
            arr[index] = max_ele

            max_ind = index

            for j in range(N):
                if j != max_ind and (arr[j] & (1 << i)) != 0:
                    arr[j] = arr[j] ^ arr[max_ind]

            index += 1

        res = 0
        for i in range(N):
            res ^= arr[i]

        return res
        
