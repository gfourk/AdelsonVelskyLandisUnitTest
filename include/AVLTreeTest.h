#ifndef AVLTREETEST_H_
#define AVLTREETEST_H_

#include "UnitTest++.h"

#include "AVLTree.h"


SUITE(AVLTreeTest)
{

	TEST(AVLTreeTestNoRoot)
	{
		AVLTree<int> avlTree;

		CHECK_EQUAL(avlTree.getRoot(), reinterpret_cast<AVLNode<int>*>(0) );

	}

	TEST(AVLTreeTestRoot)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 17 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 17 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );

	}

	TEST(AVLTreeTestRootAndRight)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 37 );
		avlTree.insert( 39 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 37 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 39 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootAndLeft)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 31 );
		avlTree.insert( 29 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 31 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 29 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootLeftLeft)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 31 );
		avlTree.insert( 29 );
		avlTree.insert( 27 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 29 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 27 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 31 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootLeftLeft2)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 31 );
		avlTree.insert( 27 );
		avlTree.insert( 29 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 29 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 27 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 31 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootRightLeft)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 23 );
		avlTree.insert( 27 );
		avlTree.insert( 21 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 23 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 21 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 27 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootRightRight)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 23 );
		avlTree.insert( 27 );
		avlTree.insert( 39 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 27 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 23 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 39 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootRightRight2)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 23 );
		avlTree.insert( 39 );
		avlTree.insert( 27 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 27 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 23 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 39 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );

		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}

	TEST(AVLTreeTestRootRightLeftAndChilds)
	{
		AVLTree<int> avlTree;
		avlTree.insert( 19 );
		avlTree.insert( 21 );
		avlTree.insert( 22 );
		avlTree.insert( 23 );
		avlTree.insert( 25 );
		avlTree.insert( 27 );
		avlTree.insert( 29 );

		CHECK_EQUAL(avlTree.getRoot()->getValue(), 23 );
		CHECK_EQUAL(avlTree.getRoot()->getHeight(), 3 );


		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getValue(), 21 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft()->getValue(), 19 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getLeft()->getParent(), avlTree.getRoot()->getLeft() );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight()->getValue(), 22 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getRight()->getParent(), avlTree.getRoot()->getLeft() );

		CHECK_EQUAL(avlTree.getRoot()->getLeft()->getParent(), avlTree.getRoot() );


		CHECK_EQUAL(avlTree.getRoot()->getRight()->getValue(), 27 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getHeight(), 2 );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft()->getValue(), 25 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getLeft()->getParent(), avlTree.getRoot()->getRight() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight()->getValue(), 29 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight()->getHeight(), 1 );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight()->getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight()->getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlTree.getRoot()->getRight()->getRight()->getParent(), avlTree.getRoot()->getRight() );

		CHECK_EQUAL(avlTree.getRoot()->getRight()->getParent(), avlTree.getRoot() );


		CHECK_EQUAL(avlTree.getRoot()->getParent(), reinterpret_cast<AVLNode<int>*>(0) );
	}


}

#endif // AVLTREETEST_H_
