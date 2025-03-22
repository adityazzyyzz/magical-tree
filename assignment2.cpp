#include <iostream>
using namespace std;



// for structure for a tree node

struct Node {
    int data;
    Node* left;                   // Pointer to the left child
    Node* right;                   // Pointer to the right child

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


// create a binary tree

Node* createTree() {
    cout << "Enter node value (-1 for no node): ";
    int value;
    cin >> value;


// Base case: If the input is -1, return nullptr (no node)

    if (value == -1) {
        return nullptr;      
    }


  // Create a new node with the input value
    Node* newNode = new Node(value);


  //create the left and right children

    cout << "Left child of " << value << ": ";
    newNode->left = createTree();

    cout << "Right child of " << value << ": ";
    newNode->right = createTree();

    return newNode;  // Return the created node
}



// for  calculate "absolute value"


int absoluteValue(int x) {
    return (x < 0) ? -x : x; // Return the positive value
}



//  post-order traversal

void postOrderTraversal(Node* root) {
    if (root == nullptr) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}




// check if two trees are magical
bool areMagical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;





    // Check if both are leaf nodes
    bool isLeaf1 = (root1->left == nullptr && root1->right == nullptr);
    bool isLeaf2 = (root2->left == nullptr && root2->right == nullptr);

    if (isLeaf1 && isLeaf2) return true;                                // Both are leaf nodes, skip calculation

    if (isLeaf1 || isLeaf2) return false;                               // One is leaf, the other is not





    // Calculate sum and "absolute difference" for root1

    int sum1 = 0, diff1 = 0;
    if (root1->left) {
        sum1 += root1->left->data;
        diff1 += root1->left->data;
    }
    if (root1->right) {
        sum1 += root1->right->data;
        diff1 -= root1->right->data;
    }
    diff1 = absoluteValue(root1->data - absoluteValue(diff1));



    // Calculate sum and "absolute difference" for root2
    int sum2 = 0, diff2 = 0;
    if (root2->left) {
        sum2 += root2->left->data;
        diff2 += root2->left->data;
    }
    if (root2->right) {
        sum2 += root2->right->data;
        diff2 -= root2->right->data;
    }
    diff2 = absoluteValue(root2->data - absoluteValue(diff2));




    // Debugging output
    cout << "Root1: " << root1->data << " | Sum of element of tree1: " << sum1 << " | Diff of element of tree1: " << diff1 << endl;
    cout << "Root2: " << root2->data << " | Sum of element of tree2: " << sum2 << " | Diff of element of tree2: " << diff2 << endl;
   
   
   // If sums or differences don't match, the trees are not magical
    if (sum1 != sum2 || diff1 != diff2) return false;




    // check if the left and right subtrees are magical
    return areMagical(root1->left, root2->left) && areMagical(root1->right, root2->right);
}

int main() {
    
    // the user to create the first binary tree

    cout << "Create Tree 1:" << endl;
    Node* root1 = createTree();


    //the user to create the second binary tree

    cout << "Create Tree 2:" << endl;
    Node* root2 = createTree();


    cout << "\nPost-order traversal of Tree 1: ";
    postOrderTraversal(root1);


    cout << "\nPost-order traversal of Tree 2: ";
    postOrderTraversal(root2);

    cout << endl;






    if (areMagical(root1, root2)) {
        cout << "The trees are magical." << endl;
    } else {
        cout << "The trees are not magical." << endl;
    }
    return 0;
}