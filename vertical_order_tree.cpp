#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{
	int key;
	Node *left, *right;
};

struct Node * newNode(int key){
	struct Node *root = new Node();
	root->key = key;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &mymap){
	if(root == NULL)
		return;
	//Inorder
	mymap[hd].push_back(root->key);
	getVerticalOrder(root->left, hd - 1, mymap);
	getVerticalOrder(root->right, hd + 1, mymap);
}

void printVerticalOrder(Node *root){
	map<int, vector<int>> mymap;
	int hd = 0;
	getVerticalOrder(root,hd,mymap);
	
	map<int, vector<int>> :: iterator it;
	for(it = mymap.begin(); it != mymap.end(); it++){
		for(int i = 0; i < it->second.size(); ++i){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

int main() 
{
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
    printVerticalOrder(root);
    return 0;
}