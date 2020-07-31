class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        min_angle = 6*minutes
        hour = hour % 12
        base_h = (30*hour)
        adj = minutes*0.5
        hour_angle = base_h + adj
        ans = (hour_angle - min_angle)
        ans = max(ans,-ans)
        return min(ans,360-ans)