

// code_start

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
    Node* head;  // virtual head
    int size;
    
public:
        
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    
    int get(int index) {
        int res = -1;
        // index valid or not? 
        if (index < 0 || index > size)
            return res;

        // find the specific node. 
        Node* cur = head;
        while (cur && index>1) {
            index--;
            cur = cur->next;
        }

        // check the node is valid.
        // it is dangerous to access the null pointer
        if (cur!=nullptr) 
            res = cur->val;
        
        return res;
    }
    
    void addAtHead(int val) {
        // val is always valid
        // find the position to insert
        // check the initial state of MyLinkedlist
        //   1. head is nullptr
        //   2. already have some nodes. 

        Node* res = new Node(val);
        // if (head==nullptr) { 
        //     // head = new Node(0);
        //     head->next = res;
        // } else {
        //     res->next = head->next;
        //     head->next = res;
        // }
        res->next = head;
        head = res;
        size++;
    }
    
    void addAtTail(int val) {
        // check the MyLinkedList state
        Node* res = new Node(val);
        size++;

        if (head == nullptr) {
            head = res;
            return ;
        }
            
        Node* cur = head;
        while (cur && cur->next)
            cur =  cur->next;

        // end because of cur,
        // only for the head node is nullptr
        // cur == head
        // cur ->next = res;
            
        // end because of cur->next find the last one.
        cur->next = res;
    }

    // before index.th node. 
    void addAtIndex(int index, int val) {
        // checked if the index is correct
        if (index>size || index<0)
            return ;
        if (index==0 || index==1) {
            addAtHead(val);
            return;
        }
        if (index==size) {
            addAtHead(val);
            return ;
        }
        
        Node* cur = head;
        while (index > 1) {
            index--;
            cur = cur->next;
        }
        Node* new_node = new Node(val);
        new_node->next = cur->next;
        cur->next = new_node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (size == 0)
            return ;
        if (index>size || index<0)
            return ;
        
        if (index == 0) {
            Node *tmp = head;
            head = head->next;
            size--;
            delete tmp;
            return ;
        }

        Node* cur = head;
        // TODO: check cur/cur->next or not?
        while (cur && index > 1) {
            cur = cur->next;
            index--;
        }

        if (index==1 && cur->next) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// code_end

