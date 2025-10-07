#include<iostream>
using namespace std;
#include<algorithm>
struct Tree
{
	Tree* left, * right;
	int height;
	int value;

	Tree(int val = 0) : left(nullptr), right(nullptr), height(0), value(val) {}
};
int height(Tree* GIVE_ME_HEIGHT)
{
	return GIVE_ME_HEIGHT ? GIVE_ME_HEIGHT->height : 0;
}

int getBalance(Tree* GIVE_ME_BALANCE)
{
	return (GIVE_ME_BALANCE ? height(GIVE_ME_BALANCE->left) : 0) - (GIVE_ME_BALANCE ? height(GIVE_ME_BALANCE->right) : 0);
}

Tree* leftRotate(Tree* to_rotate)
{
	Tree* try_rotate = to_rotate->right;
	to_rotate->right = try_rotate->left;
	try_rotate->left = to_rotate;


	to_rotate->height = 1 + max(height(to_rotate->left), height(to_rotate->right));


	try_rotate->height = 1 + max(height(try_rotate->left), height(try_rotate->right));
	return try_rotate;
}

Tree* rightRotate(Tree* to_rotate)
{
	Tree* try_rotate = to_rotate->left;
	to_rotate->left = try_rotate->right;
	try_rotate->right = to_rotate;


	to_rotate->height = 1 + max(height(to_rotate->left),height(to_rotate->right));


	try_rotate->height = 1 + max(height(try_rotate->left), height(try_rotate->right));
	return try_rotate;
}
Tree* insert(Tree* tree, int val)
	{
	if (tree == nullptr) {
		return new Tree(val);
	}

		if (tree->value > val)
		{
			if (tree->left == nullptr) { tree->left = new Tree(val) ; }
			else
			{
				tree->left = insert(tree->left, val);
			}
		}
		if (tree->value < val)
		{
			if (tree->right == nullptr) { tree->right = new Tree(val); }
			else
			{
				tree->right= insert(tree->right, val);
			}
		}
		else
			return tree;
		tree->height = 1 + max(height(tree->left) , height(tree->right));
		int balance = getBalance(tree);

		if (balance > 1 && tree->left->value > val) { tree = rightRotate(tree); }

		if (balance < -1 && tree->right->value < val) { tree = leftRotate(tree); }

		if (balance > 1 && tree->left->value < val) { tree->left = leftRotate(tree->left); tree = rightRotate(tree); }

		if (balance < -1 && tree->right->value > val) { tree->right = rightRotate(tree->right); tree = leftRotate(tree); }
		return tree;
	}
void printTree(Tree* root, int space = 0, int height = 10) {
	if (root == nullptr)
		return;

	space += height;

	printTree(root->right, space);

	cout << endl;
	for (int i = height; i < space; i++)
		cout << " ";
	cout << root->value << "\n";

	printTree(root->left, space);
}
//int main()
//{
//		Tree* root = nullptr;
//
//		root = insert(root, 5);
//		root = insert(root, 9);
//		root = insert(root, 4);
//		root = insert(root, 18);
//		root = insert(root, 50);
//		root = insert(root, 13);
//
//		cout << "AVL Tree structure:\n";
//		printTree(root);
//
//	return 0;
//}
