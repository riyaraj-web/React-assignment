class Solution(object):
    def avoidFlood(self, rains):
        """
        :type rains: List[int]
        :rtype: List[int]
        """
        n = len(rains)
        full = {}
        dry_days = []
        ans = [-1] * n

        for i, lake in enumerate(rains):
            if lake == 0:
                dry_days.append(i)
                ans[i] = 1
            else:
                if lake in full:
                    j = bisect_right(dry_days, full[lake])
                    if j == len(dry_days):
                        return []
                    dry_day = dry_days.pop(j)
                    ans[dry_day] = lake
                full[lake] = i
                ans[i] = -1

        return ans
