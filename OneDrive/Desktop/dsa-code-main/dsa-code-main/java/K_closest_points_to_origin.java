import java.util.*;

class K_closest_points_to_origin {
    public static int[][] kClosest(int[][] points, int k) {

        PriorityQueue<int[]> queue = new PriorityQueue<>(
                (a, b) -> (b[0]*b[0] + b[1]*b[1]) - (a[0]*a[0] + a[1]*a[1])
        );

        for (int[] point : points) {
            queue.add(point);
            if (queue.size() > k) {
                queue.poll();
            }
        }

        int[][] result = new int[k][2];
        for (int i = 0; i < k; i++) {
            result[i] = queue.poll();
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int k = sc.nextInt();
        int[][] input = new int[num][2];
        for (int i = 0; i < input.length; i++) {
            input[i][0] = sc.nextInt();
            input[i][1] = sc.nextInt();
        }

        int[][] output = kClosest(input, k);
        System.out.println(Arrays.deepToString(output));
    }
}
