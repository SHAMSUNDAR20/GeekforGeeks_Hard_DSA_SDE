class Node {
    int key;
    int value;
    Node prev;
    Node next;
}

class LRUCache {
    private final int capacity;
    private HashMap<Integer, Node> map = new HashMap<>();
    private Node head = null;
    private Node end = null;

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            remove(node);
            setHead(node);
            return node.value;
        }
        return -1;
    }

    public void set(int key, int value) {
        if (map.containsKey(key)) {
            Node old = map.get(key);
            old.value = value;
            remove(old);
            setHead(old);
        } else {
            Node newNode = new Node();
            newNode.key = key;
            newNode.value = value;

            if (map.size() >= capacity) {
                map.remove(end.key);
                remove(end);
                setHead(newNode);
            } else {
                setHead(newNode);
            }    

            map.put(key, newNode);
        }
    }

    private void remove(Node node) {
        if (node.prev != null) {
            node.prev.next = node.next;
        } else {
            head = node.next;
        }

        if (node.next != null) {
            node.next.prev = node.prev;
        } else {
            end = node.prev;
        }
    }

    private void setHead(Node node) {
        node.next = head;
        node.prev = null;

        if (head != null) {
            head.prev = node;
        }

        head = node;

        if (end == null) {
            end = head;
        }
    }
}
