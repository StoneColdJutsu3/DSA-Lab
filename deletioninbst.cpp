#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    // Helper function to find the minimum value node in a subtree
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Recursive function to delete a node
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        // Traverse to the correct node
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node to be deleted found

            // Case 1: No child or one child (left or right)
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node has two children
            Node* temp = findMin(root->right); // Find the in-order successor
            root->data = temp->data;          // Copy the successor's data to the current node
            root->right = deleteNode(root->right, temp->data); // Delete the successor
        }
        return root;
    }

    // Helper function for in-order traversal
    void inOrder(Node* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a node into the BST
    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* insertRec(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }
        return root;
    }

    // Delete a node by value
    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    // Display the BST using in-order traversal
    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal of the BST: ";
    tree.display();

    cout << "Deleting 20...\n";
    tree.deleteValue(20);
    cout << "In-order traversal after deleting 20: ";
    tree.display();

    cout << "Deleting 30...\n";
    tree.deleteValue(30);
    cout << "In-order traversal after deleting 30: ";
    tree.display();

    cout << "Deleting 50...\n";
    tree.deleteValue(50);
    cout << "In-order traversal after deleting 50: ";
    tree.display();

    return 0;
}
