class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        intervals.sort(key = lambda x: x[0])
        
        merged = []
        
        for index, interval in enumerate(intervals):
            
            # we add a new interval if the start date is after the last end date OR empty
            if not merged or interval[0] > merged[-1][1]:
                merged.append(interval)
            # or modify last inervals in merged
            else:
                merged[-1][1] = max(interval[1], merged[-1][1])
        return merged
            