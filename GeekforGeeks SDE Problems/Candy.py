

class Solution:
    def minCandy(self, N, ratings):
        if N == 1:
            return 1
        candies = [1] * N
        for i in range(1, N):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        for i in range(N-2, -1, -1):
            if ratings[i] > ratings[i+1] and candies[i] <= candies[i+1]:
                candies[i] = candies[i+1] + 1
        return sum(candies)
        
        
        
        
        
        