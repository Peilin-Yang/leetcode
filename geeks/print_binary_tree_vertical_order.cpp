#include <iostream>
using namespace std;
 
// A node of binary tree
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new Binary Tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* 
// A utility function to find min and max distances with respect
// to root.
void findMinMax(Node *node, int *min, int *max, int hd)
{
    // Base case
    if (node == NULL) return;
 
    // Update min and max
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;
 
    // Recur for left and right subtrees
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}
 
// A utility function to print all nodes on a given line_no.
// hd is horizontal distance of current node with respect to root.
void printVerticalLine(Node *node, int line_no, int hd)
{
    // Base case
    if (node == NULL) return;
 
    // If this node is on the given line number
    if (hd == line_no)
        cout << node->data << " ";
 
    // Recur for left and right subtrees
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}
 
// The main function that prints a given binary tree in
// vertical order
void verticalOrder(Node *root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
 
    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout << endl;
    }
}
*/

void findMinMax(Node *root, int &min, int &max, int d) {
  if (root == NULL) return;
  if (d < min) min = d;
  if (d > max) max = d;
  findMinMax(root->left, min, max, d-1);
  findMinMax(root->right, min, max, d+1);
}

void printVerticalLine(Node *root, int d, int cur) {
  if (!root) return;
  if (d == cur) cout << root->data << " ";
  printVerticalLine(root->left, d, cur-1);
  printVerticalLine(root->right, d, cur+1);
}

void verticalOrder(Node *root) {
  int min = 0, max = 0;
  findMinMax(root, min, max, 0);
  cout << "min:" << min << " max:" << max << endl;

  for (int i = min; i <= max; i++) {
    printVerticalLine(root, i, 0);
    cout << endl;
  }  
}
 
// Driver program to test above functions
int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
 
    cout << "Vertical order traversal is \n";
    verticalOrder(root);
 
    return 0;
}
