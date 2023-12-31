
class Solution:
    def string_sum(self, str1, str2):
        str1, str2 = str(int(str1)), str(int(str2))
        if len(str1) < len(str2):
            str1, str2 = str2, str1

        str1 = str1[::-1]
        str2 = str2[::-1]
        carry = 0
        ans = ''

        for i in range(len(str2)):
            temp_sum = ((ord(str1[i]) - ord('0')) + (ord(str2[i]) - ord('0')) + carry)
            ans += chr((temp_sum % 10) + ord('0'))
            carry = temp_sum // 10

        for i in range(len(str2), len(str1)):
            temp_sum = ((ord(str1[i]) - ord('0')) + carry)
            ans += chr((temp_sum % 10) + ord('0'))
            carry = temp_sum // 10

        if carry:
            ans += chr(carry + ord('0'))

        return ans[::-1]

    def checkSumStrUtil(self, str, beg, len1, len2):
        s1 = str[beg : beg + len1]
        s2 = str[beg + len1 : beg + len1 + len2]
        s3 = self.string_sum(s1, s2)

        if len(s3) > len(str) - len1 - len2 - beg:
            return False

        if s3 == str[beg + len1 + len2 : beg + len1 + len2 + len(s3)]:
            if beg + len1 + len2 + len(s3) == len(str):
                return True

            return self.checkSumStrUtil(str, beg + len1, len2, len(s3))

        return False

    def isSumStr(self, str):
        n = len(str)

        for i in range(1, n):
            for j in range(1, n - i + 1):
                if self.checkSumStrUtil(str, 0, i, j):
                    return True

        return False

    def isSumString(self, S):
        return int(self.isSumStr(S))

# Driver Code Ends





