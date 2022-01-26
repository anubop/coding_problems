import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        numRooms = 1
        endtimes = []
        intervals.sort() #O(n*logn)
        
        heapq.heappush(endtimes, intervals[0][1])
        
        for interval in intervals[1:]:
            start, end = interval
            if(start >= endtimes[0]):
                heapq.heappop(endtimes)
                heapq.heappush(endtimes, end)
            else:
                numRooms +=1
                heapq.heappush(endtimes, interval[1])
        return numRooms
      
        