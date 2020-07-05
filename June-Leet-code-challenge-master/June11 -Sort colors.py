class Solution(object):
    def sortColors(self, arr):
        
        def swap(idx1, idx2, arr):
            arr[idx1], arr[idx2] = arr[idx2], arr[idx1]
        
        currentIdx = 0
        while currentIdx < len(arr):
            smallestIdx = currentIdx
            for i in range(currentIdx + 1, len(arr)):
                if arr[smallestIdx] > arr[i]:
                    smallestIdx = i
            swap(currentIdx, smallestIdx, arr)
            currentIdx += 1
        return arr
