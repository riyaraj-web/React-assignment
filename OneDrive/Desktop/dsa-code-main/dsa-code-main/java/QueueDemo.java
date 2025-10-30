import java.util.PriorityQueue;

public class QueueDemo {
    public static void main(String[] args) {
        PriorityQueue<String> queue = new PriorityQueue<>();

        queue.add("India");
        queue.add("Germany");
        queue.add("USA");

        System.out.println("Queue:"+queue);

        queue.remove();

        System.out.println(queue);

        String head = queue.peek();
        System.out.println("Head:"+head);

        head = queue.poll();
        System.out.println("Removed head:"+head);

        System.out.println(queue);
    }
}
