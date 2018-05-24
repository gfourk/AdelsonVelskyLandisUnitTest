#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "AVLNode.h"

/*
T interface
T(const T& x) -> copy constructor
~T() -> destructor
T& operator=(const T& x) -> operator=
bool operator<(const T& x) -> operator<
bool operator>(const T& x) -> operator>
*/
template<class T>
class AVLTree
{

	AVLNode<T>* root;

	void reconstructAfterInsert( AVLNode<T>* current, AVLNode<T>* father );
	void reconstructAfterErase( AVLNode<T>* current );


public:

	~AVLTree();
	AVLTree();

	bool insert( const T& val );
	bool erase( const T& val );
	AVLNode<T>* find( const T& val ) const;
	void clear();

	template<typename S> friend class AVLTreeTestHelper;

	AVLNode<T>* getRoot()
	{
		return root;
	}

};

template<class T>
AVLTree<T>::~AVLTree()
{
	clear();
}

template<class T>
AVLTree<T>::AVLTree() : root(0)
{

}

/*
T interface
T(const T& x) -> copy constructor
bool operator<(const T& x) -> operator<
bool operator>(const T& x) -> operator>
*/
template<class T>
bool AVLTree<T>::insert( const T& val )
{
	if ( root == 0 )
	{
		root = new AVLNode<T>( val, 1, 0, 0, 0 );
		return true;
	}
	AVLNode<T>* father = 0;
	AVLNode<T>* newNode = root;
	while( newNode != 0 )
	{
		if (newNode->value > val)
		{
			father = newNode;
			newNode = newNode->left;
		}
		else if (newNode->value < val)
		{
			father = newNode;
			newNode = newNode->right;
		}
		else
			return false;
	}

	newNode = new AVLNode<T>( val, 1, 0, 0, father );
	if (father->value > val)
		father->left =  newNode;
	else
		father->right =  newNode;
	reconstructAfterInsert(newNode,father);
	newNode = 0;
	father = 0;
	return true;
}

template<class T>
void AVLTree<T>::reconstructAfterInsert( AVLNode<T>* current, AVLNode<T>* father )
{
	int balance;

	AVLNode<T>* grant = father->parent; // grant maybe null
	father->reHeight(); // father is never null if root in not null

	while( grant != 0 )
	{
		balance = grant->reHeightAndGetBalance();
		if ( balance == -2 )
		{

			if ( current->parent->left == current ) // current is left child of it's father, make father right child of current
			{
				current->rightRotate();
				current = father;
				current->reHeight();

				father = current->parent; // new father will reHeight after leftRotate
			}

			father->leftRotate();
			grant->reHeight();
			father->reHeight();

			current = father;
			father = father->parent;

			if ( father == 0 )
				root = current;
			break;
		}
		else if ( balance == 2 )
		{

			if (current->parent->right == current) // current is right child of it's father, make father left child of current
			{
				current->leftRotate();
				current = father;
				current->reHeight();

				father = current->parent; // new father will reHeight after rightRotate
			}

			father->rightRotate();
			grant->reHeight();
			father->reHeight();

			current = father;
			father = father->parent;

			if ( father == 0 )
				root = current;
			break;
		}
		else // move up to the tree to check inconsistencies
		{
			current = father;
			father = grant;
			grant = grant->parent;
		}
	}//end of while
	father = 0;
	current = 0;
}

/*
T interface
T(const T& x) -> copy constructor
T& operator=(const T& x) -> operator=
*/
template<class T>
bool AVLTree<T>::erase( const T& val )
{
	AVLNode<T>* nodeNext = 0;
	AVLNode<T>* current = find( val );

	if ( current == 0 )
		return false;

	if ( current->right != 0 )
	{
		nodeNext = current->right;
		while( nodeNext->left != 0 )
			nodeNext = nodeNext->left;

		if ( current->right != nodeNext )
		{
			nodeNext->parent->left =  nodeNext->right;
			if ( nodeNext->right != 0 )
			{
				nodeNext->right->parent =  nodeNext->parent;
			}
		}
		else
		{
			nodeNext->parent->right =  nodeNext->right;
			if ( nodeNext->right != 0 )
			{
				nodeNext->right->parent =  nodeNext->parent;
			}
		}
		current->value = nodeNext->value;
		reconstructAfterErase(nodeNext); // erase only leafs
		delete nodeNext;
		nodeNext = 0;
	}
	else if ( current->left != 0 )
	{
		nodeNext = current->left;
		while( nodeNext->right != 0 )
			nodeNext = nodeNext->right;

		if ( current->left != nodeNext )
		{
			nodeNext->parent->right =  nodeNext->left;
			if ( nodeNext->left != 0 )
			{
				nodeNext->left->parent =  nodeNext->parent;
			}
		}
		else
		{
			nodeNext->parent->left =  nodeNext->left;
			if ( nodeNext->left != 0 )
			{
				nodeNext->left->parent =  nodeNext->parent;
			}
		}
		current->value = nodeNext->value;
		reconstructAfterErase(nodeNext); // erase only leafs
		delete nodeNext;
		nodeNext = 0;
	}
	else if ( current->parent == 0 )
	{
		delete root;
		root = 0;
	}
	else
	{
		if ( current->parent->right == current )
			current->parent->right =  0;
		else if ( current->parent->left == current )
			current->parent->left =  0;
		reconstructAfterErase(current);
		delete(current);
	}
	current = 0;
	return true;
}

template<class T>
void AVLTree<T>::reconstructAfterErase( AVLNode<T>* current )
{
	int balance;
	int height;
	AVLNode<T>* father = current->parent;
	while( father != 0 )
	{
		height = father->height;
		balance = father->reHeightAndGetBalance();

		if ( balance == 2 )
		{
			current = father->left;
			balance = current->reHeightAndGetBalance();

			if ( balance == -1 )
			{
				current = current->right;
				current->leftRotate();
				current->left->reHeight();
			}

			current->rightRotate();
			father->reHeight();
			current->reHeight();

			if ( current->height < height )
				father = current->parent;
			else
			{
				if ( current->parent != 0 )
					current = root;
				break;
			}
		}
		else if ( balance == -2 )
		{
			current = father->right;
			balance = current->reHeightAndGetBalance();

			if ( balance == 1 )
			{
				current = current->left;
				current->rightRotate();
				current->right->reHeight();
			}

			current->leftRotate();
			father->reHeight();
			current->reHeight();

			if ( current->height < height )
				father = current->parent;
			else
			{
				if ( current->parent != 0 )
					current = root;
				break;
			}
		}
		else
		{
			current = father;
			father = father->parent;
		}
	}//end of while
	root = current;
	current = 0;
}

/*
T interface
T(const T& x) -> copy constructor
bool operator<(const T& x) -> operator<
bool operator>(const T& x) -> operator>
*/
template<class T>
AVLNode<T>* AVLTree<T>::find( const T& val ) const
{
	AVLNode<T>* current = root;
	while( current != 0 )
	{
		if ( current->value > val )
			current = current->left;
		else if ( current->value < val )
			current = current->right;
		else
			return current;
	}
	return 0;
}

template<class T>
void AVLTree<T>::clear()
{

	if ( root == 0 )
		return;

	AVLNode<T>* current = root->findNext();
	while ( current != 0 )
	{
		if ( current->parent->left == current )
		{
			current->parent->left = current->right;
			if ( current->right != 0 )
				current->right->parent = current->parent;
		}
		else if ( current->parent->right == current )
		{
			current->parent->right = current->right;
			if ( current->right != 0 )
				current->right->parent = current->parent;
		}
		delete(current);
		current = root->findNext();
	}

	current = root->findPrevious();
	while ( current != 0 )
	{
		if ( current->parent->left == current )
		{
			current->parent->left = current->left;
			if ( current->left != 0 )
				current->left->parent = current->parent;
		}
		else if ( current->parent->right == current )
		{
			current->parent->right = current->left;
			if ( current->left != 0 )
				current->left->parent = current->parent;
		}
		delete(current);
		current = root->findPrevious();
	}

	delete(root);

	root = 0;
}

#endif // AVLTREE_H_
