
class TrapRainWaterII {

    public static void main(String[] args) {
        // Sample height map (3x6 grid)
        int[][] heightMap = {
            {1, 4, 3, 1, 3, 2},
            {3, 2, 1, 3, 2, 4},
            {2, 3, 3, 2, 3, 1}
        };

        // Call function and print trapped water
        int trappedWater = trapRainWater(heightMap);
        System.out.println("Total trapped water: " + trappedWater);
    }

    public static int trapRainWater(int[][] heightMap) {
        // Edge case: empty grid
        if (heightMap == null || heightMap.length == 0 || heightMap[0].length == 0) {
            return 0;
        }

        int m = heightMap.length;      // number of rows
        int n = heightMap[0].length;   // number of columns
        int[][] vols = new int[m][n];  // matrix storing final water levels

        // Step 1: Initialize vols with the original height map
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vols[i][j] = heightMap[i][j];
            }
        }

        boolean upt = true; // tracks if updates occur in a pass
        boolean init = true;

        // Step 2: Iteratively propagate water levels
        while (upt) {
            upt = false;

            // Pass 1: Top-left → bottom-right
            for (int i = 1; i < m - 1; i++) {
                for (int j = 1; j < n - 1; j++) {
                    int val = Math.max(heightMap[i][j],
                            Math.min(vols[i - 1][j], vols[i][j - 1]));
                    if (init || vols[i][j] > val) {
                        vols[i][j] = val;
                        upt = true;
                    }
                }
            }

            init = false;

            // Pass 2: Bottom-right → top-left
            for (int i = m - 2; i >= 1; i--) {
                for (int j = n - 2; j >= 1; j--) {
                    int val = Math.max(heightMap[i][j],
                            Math.min(vols[i + 1][j], vols[i][j + 1]));
                    if (vols[i][j] > val) {
                        vols[i][j] = val;
                        upt = true;
                    }
                }
            }
        }

        // Step 3: Calculate total trapped water
        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                res += Math.max(vols[i][j] - heightMap[i][j], 0);
            }
        }

        return res;
    }
}
