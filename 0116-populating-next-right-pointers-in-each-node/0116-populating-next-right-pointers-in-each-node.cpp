class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == nullptr) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        
        Node* prev = nullptr;

        while(q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            if(curr == nullptr) {
                if(q.size() == 0) {
                    break;
                } else {
                    q.push(nullptr);
                }
            } else {
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }

                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
                if(prev != nullptr) {
                    prev->next = curr;
                }
            }
            prev = curr;
        }
        
       
        return root;
    }
};