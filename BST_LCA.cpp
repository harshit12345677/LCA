#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public:
  		Node* insertBST(Node* root, int data) {
		// Complete function to insert a node in the BST rooted at 'root'


		if(root==NULL)
        {
            Node *temp=new Node(data);

            root=temp;
            return root;
        }

        if(data>root->data)
        {
            root->right=insertBST(root->right,data);

        }
        else root->left=insertBST(root->left,data);
        return root;
		}

		Node *returnLCA(Node *root, int v1,int v2) {
		// Complete function to return pointer of LCA of v1 and v2
		if(root==NULL)
            return NULL;
		if(root->data<v1&&root->data<v2)
        {
            return returnLCA(root->right,v1,v2);
        }
        else return returnLCA(root->left,v1,v2);
        return root;
    }

};

int main() {
	// Loop to iterate over test cases
    BST myTree;
    Node* root = NULL;
	// Code to read input and insert node in BST
	int v1, v2;
	// Read v1 and v2
	int t;
	cin>>t;
	int n;
	for(int i=0;i<t;i++)
    {
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            root=myTree.insertBST(root,arr[j]);

        }
        cout<<root->left->data;
    }
    cin>>v1>>v2;
	Node *ans = myTree.returnLCA(root, v1, v2);
	cout << ans->data;
}
