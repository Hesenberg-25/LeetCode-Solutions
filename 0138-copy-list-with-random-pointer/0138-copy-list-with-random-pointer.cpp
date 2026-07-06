class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            Node* copyNode = new Node(temp->val);
            temp->next = copyNode;
            copyNode->next = nextNode;
            temp = nextNode;
        }

        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node* dummy = new Node(0);
        Node* res = dummy;
        temp = head;
        
        while (temp != nullptr) {
            Node* nextNode = temp->next->next;
            res->next = temp->next;
            temp->next = nextNode;
            res = res->next;
            temp = nextNode;
        }

        return dummy->next;
    }
};