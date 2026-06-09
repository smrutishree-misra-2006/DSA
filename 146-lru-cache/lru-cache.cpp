class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, Node*> mpp;
    int cap;
    Node* head;
    Node* tail;

    // Add node right after head (Most Recently Used)
    void add(Node* newNode) {
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    // Remove node from the list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];

        // Move to front (MRU)
        deleteNode(node);
        add(node);

        return node->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];

            node->val = value;

            deleteNode(node);
            add(node);

            return;
        }

        // Cache full
        if (mpp.size() == cap) {
            Node* lru = tail->prev;

            mpp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }

        // Insert new node
        Node* newNode = new Node(key, value);
        add(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */