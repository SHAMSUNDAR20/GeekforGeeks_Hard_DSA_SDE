

class Solution:
    def displayContacts(self, n, contact, s):
        results = []
        for i in range(1, len(s) + 1):
            prefix = s[:i]
            matches = sorted(set(c for c in contact if c.startswith(prefix)))
            results.append(matches if matches else ["0"])
        return results
