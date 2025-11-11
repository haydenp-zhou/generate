#include "fun_nxPwe7pc7tF2rpiw.hpp"

// Original algorithm: Morrisinorder
int fun_nxPwe7pc7tF2rpiw() {
    try {
        using namespace std;
        struct Btree {
            int data;
            struct Btree *left;   // Pointer to left subtree
            struct Btree *right;  // Pointer to right subtree
        };
        void insert(Btree **root, int d) {
            Btree *nn = new Btree();  // Creating new node
            nn->data = d;
            nn->left = NULL;
            nn->right = NULL;
            if (*root == NULL) {
                *root = nn;
                return;
            } else {
                queue<Btree *> q;
                q.push(*root);
                while (!q.empty()) {
                    Btree *node = q.front();
                    q.pop();
                    if (node->left)
                        q.push(node->left);
                    else {
                        node->left = nn;
                        return;
                    }
                    if (node->right)
                        q.push(node->right);
                    else {
                        node->right = nn;
                        return;
                    }
                }
            }
        }
        void morrisInorder(Btree *root) {
            Btree *curr = root;
            Btree *temp;
            while (curr) {
                if (curr->left == NULL) {
                    cout << curr->data << " ";
                    curr = curr->right;
                } else {
                    temp = curr->left;
                    while (temp->right && temp->right != curr) temp = temp->right;
                    if (temp->right == NULL) {
                        temp->right = curr;
                        curr = curr->left;
                    }
                    else if (temp->right == curr) {
                        cout << curr->data << " ";
                        temp->right = NULL;
                        curr = curr->right;
                    }
                }
            }
        }
        void deleteAll(const Btree *const root) {
            if (root) {
                deleteAll(root->left);
                deleteAll(root->right);
                delete root;
            }
        }


        volatile int status = 1;
        cout << "fun_nxPwe7pc7tF2rpiw: Morrisinorder executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_nxPwe7pc7tF2rpiw: Exception - " << e.what() << endl;
        return 0;
    }
}
