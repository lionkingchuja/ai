#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
void printLevelorder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            cout << node->data << " ";
        }
        cout << endl;
    }
}

void printPostorder(Node* node){
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printInorder(Node* node){
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node* node){
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

bool dep_search(Node* root, int lvl, int val, int height) {
    if (root == NULL) {
        return false;
    }

    if (height > lvl) {
        return false;
    }

    if (height == lvl && root->data == val) {
        return true;
    }

    return (dep_search(root->left, lvl, val, height + 1) || dep_search(root->right, lvl, val, height + 1));
}

bool bfs_search(Node* root, int val) {
    if(root == NULL) {
        return false;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) {
                q.push(node->left);
            }
            if(node->right != NULL) {
                q.push(node->right);
            }

            if(node->data == val) {
                return true;
            }
        }
    }
    return false;
}
Node* buildTree() {
    int data;
    cout << "Enter the data for the root node: ";
    cin >> data;

    Node* root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter the data for the left child of " << current->data << " (or -1 if no left child): ";
        cin >> leftData;

        if (leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter the data for the right child of " << current->data << " (or -1 if no right child): ";
        cin >> rightData;

        if (rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }
    return root;
}
// void insert_btree(int data){
//         Node* temp=new Node(data);
//         Node* temp2=root;
//         if(root==NULL){
//             root=temp;
//         }
//         else{
//             while(true){
//                 cout<<"left or right "<<endl;
//                 int choice;cin>>choice;
//                 if(choice==0){
//                     if(temp2->left==NULL){ temp2->left=temp; break;}
//                     temp2=temp2->left;
//                 }
//                 else if(choice==1){
//                     if(temp2->right==NULL){ temp2->right=temp; break;}
//                     temp2=temp2->right;
//                 }
//             }
//         }
//     }

bool Path(Node *root, vector<int>& v, int x)
{
    if (!root) return false;
     
    v.push_back(root->data);    
     
    if (root->data == x)    
        return true;
    
    if (Path(root->left, v, x) ||Path(root->right, v, x))
        return true;
     
    v.pop_back();
    return false;            
}

int main() {
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    Node* root=NULL;
    root = buildTree();


    cout << "\nLevel order traversal of binary tree is \n";
    printLevelorder(root);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    int choice;
    cout << "\n\nUser Manual : \n1. DFS Search \n2. BFS Search";
    cout << "\n\nEnter your choice : ";
    cin >> choice;

    if (choice == 1) {
        int val, lvl;

        cout << "\n\nEnter the value you want to search : ";
        cin >> val;
        cout << "Enter the level to which you want to search : ";
        cin >> lvl;

        if (dep_search(root, lvl, val, 1)) {
            cout << "\nElement found";
        } else {
            cout << "\nElement Not found";
        }
        vector<int>v;
        Path(root,v,val);
        cout<<endl;
        for(auto i:v) cout<<i<<" ";
        cout<<endl;

    } else if (choice == 2) {
        int val;

        cout << "\n\nEnter the value you want to search : ";
        cin >> val;

        if (bfs_search(root, val)) {
            cout << "\nElement Found\n";
        } else {
            cout << "\nElement Not Found\n";
        }
    } else {
        cout << "\nInvalid choice!!!\n";
    }

    return 0;
}
