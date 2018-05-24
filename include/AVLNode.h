#ifndef AVLNODE_H_
#define AVLNODE_H_

/*
T interface
T(const T& x) -> copy constructor
~T() -> destructor
*/
template<class T>
class AVLNode
{

	T value;
	int height;
	AVLNode<T>* left;
	AVLNode<T>* right;
	AVLNode<T>* parent;

public:

	~AVLNode();
	AVLNode( const T& val, const int& h, AVLNode* l, AVLNode* r, AVLNode* p );

	void leftRotate();
	void rightRotate();

	void reHeight();
	int reHeightAndGetBalance();

	AVLNode<T>* findNext() const;
	AVLNode<T>* findPrevious() const;

	template<typename S> friend class AVLTree;

	T getValue()
	{
		return this->value;
	}

	int getHeight()
	{
		return this->height;
	}

	AVLNode<T>* getLeft() const
	{
		return this->left;
	}

	void setLeft(AVLNode<T>* l)
	{
		this->left = l;
	}

	AVLNode<T>* getRight() const
	{
		return this->right;
	}

	void setRight(AVLNode<T>* r)
	{
		this->right = r;
	}

	AVLNode<T>* getParent() const
	{
		return this->parent;
	}

	void setParent(AVLNode<T>* p)
	{
		this->parent = p;
	}

};

/*
T interface
~T() -> destructor
*/
template<class T>
AVLNode<T>::~AVLNode()
{
	height = 0;
	parent = 0;
	left = 0;
	right = 0;
}

/*
T interface
T(const T& x) -> copy constructor
*/
template<class T>
AVLNode<T>::AVLNode( const T& val, const int& h, AVLNode* l, AVLNode* r, AVLNode* p )
	: value(val), height(h), left(l), right(r), parent(p)
{

}

template<class T>
void AVLNode<T>::leftRotate()
{
	AVLNode* father = this->parent;
	AVLNode* grant = father->parent;

	this->parent = grant;
	if ( grant != 0 )
	{
		if ( father->parent->left == father )
			grant->left = this;
		else
			grant->right = this;
	}

	father->parent = this;
	father->right = this->left;

	if ( this->left != 0 )
		this->left->parent = father;
	this->left = father;
}

template<class T>
void AVLNode<T>::rightRotate()
{
	AVLNode* father = this->parent;
	AVLNode* grant = father->parent;

	this->parent = grant;
	if ( grant != 0 )
	{
		if ( father->parent->left == father )
			grant->left = this;
		else
			grant->right = this;
	}

	father->parent = this;
	father->left = this->right;

	if ( this->right != 0 )
		this->right->parent = father;
	this->right = father;
}

template<class T>
AVLNode<T>* AVLNode<T>::findNext() const
{
	if ( this->right != 0 )
	{
		AVLNode<T>* nodeNext = this->right;
		while( nodeNext->left != 0 )
			nodeNext = nodeNext->left;
		return nodeNext;
	}
	return 0;
}

template<class T>
AVLNode<T>* AVLNode<T>::findPrevious() const
{
	if ( this->left != 0 )
	{
		AVLNode<T>* nodeNext = this->left;
		while( nodeNext->right != 0 )
			nodeNext = nodeNext->right;
		return nodeNext;
	}
	return 0;
}

template<class T>
void AVLNode<T>::reHeight()
{
	if ( left != 0 )
	{
		if ( right != 0 )
		{
			height = ( left->height > right->height ?
					   left->height : right->height ) + 1;
		}
		else
		{
			height = left->height + 1;
		}
	}
	else if ( right != 0 )
	{
		height = right->height + 1;
	}
	else
	{
		height = 1;
	}
}

template<class T>
int AVLNode<T>::reHeightAndGetBalance()
{
	if ( left != 0 )
	{
		if ( right != 0 )
		{
			height = ( left->height > right->height ?
					   left->height : right->height ) + 1;
			return left->height - right->height;
		}
		else
		{
			height = left->height + 1;
			return left->height;
		}
	}
	else if ( right != 0 )
	{
		height = right->height + 1;
		return -right->height;
	}
	else
	{
		height = 1;
		return 0;
	}
}

#endif // AVLNODE_H_
