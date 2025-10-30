# Leetcode problem 417. Pacific Atlantic Water Flow

class Solution(object):
    def pacificAtlantic(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        rows,cols=len(heights),len(heights[0])    
        pac,atl =set(),set()

        def search(r,c,visit,prev):
            if((r,c) in visit or r<0 or c<0 or r==rows or c==cols or heights[r][c]<prev):
                return 
            visit.add((r,c))
            search(r+1,c,visit,heights[r][c])
            search(r-1,c,visit,heights[r][c])
            search(r,c+1,visit,heights[r][c])
            search(r,c-1,visit,heights[r][c])

        for c in range(cols):
            search(0,c,pac,heights[0][c])
            search(rows-1,c,atl,heights[rows-1][c])

        for r in range(rows):
            search(r,0,pac,heights[r][0])
            search(r,cols-1,atl,heights[r][cols-1])

        res=[]

        for r in range(rows):
            for c in range(cols):
                if (r,c)in pac and (r,c) in atl:
                    res.append([r,c])

        return res