#ifndef AVLNODETEST_H_
#define AVLNODETEST_H_

#include "UnitTest++.h"

#include "AVLNode.h"

SUITE(AVLNodeTest)
{

	TEST(AVLNodeTestTrivial)
	{
		AVLNode<int> avlNode(17,1,0,0,0);

		CHECK_EQUAL(avlNode.getValue(), 17 );
		CHECK_EQUAL(avlNode.getHeight(), 1 );
		CHECK_EQUAL(avlNode.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		avlNode.reHeight();
		CHECK_EQUAL(avlNode.getHeight(), 1 );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 0 );

		CHECK_EQUAL(avlNode.findNext(), reinterpret_cast<AVLNode<int>*>(0) ); // only for clear() method
		CHECK_EQUAL(avlNode.findPrevious(), reinterpret_cast<AVLNode<int>*>(0) ); // only for clear() method
	}

	TEST(AVLNodeTestRootAndRight)
	{
		AVLNode<int> avlNode(39,1,0,0,0);
		AVLNode<int> avlNode2(37,2,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setRight(&avlNode);

		CHECK_EQUAL(avlNode2.getRight(), &avlNode );
		CHECK_EQUAL(avlNode2.getRight()->getParent(), &avlNode2 );

		avlNode2.reHeight();
		CHECK_EQUAL(avlNode2.getHeight(), 2 );

		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), -1 );

		CHECK_EQUAL(avlNode2.findNext(), &avlNode ); // only for clear() method
		CHECK_EQUAL(avlNode2.findPrevious(), reinterpret_cast<AVLNode<int>*>(0) ); // only for clear() method
	}

	TEST(AVLNodeTestRootAndLeft)
	{
		AVLNode<int> avlNode(29,1,0,0,0);
		AVLNode<int> avlNode2(31,2,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setLeft(&avlNode);

		CHECK_EQUAL(avlNode2.getLeft(), &avlNode );
		CHECK_EQUAL(avlNode2.getLeft()->getParent(), &avlNode2 );

		avlNode2.reHeight();
		CHECK_EQUAL(avlNode2.getHeight(), 2 );

		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 1 );

		CHECK_EQUAL(avlNode2.findNext(), reinterpret_cast<AVLNode<int>*>(0) ); // only for clear() method
		CHECK_EQUAL(avlNode2.findPrevious(), &avlNode ); // only for clear() method
	}

	TEST(AVLNodeTestRootRightLeft)
	{
		AVLNode<int> avlNode(27,1,0,0,0);
		AVLNode<int> avlNode2(23,2,0,0,0);
		AVLNode<int> avlNode3(21,1,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setRight(&avlNode);
		avlNode3.setParent(&avlNode2);
		avlNode2.setLeft(&avlNode3);

		CHECK_EQUAL(avlNode2.getRight(), &avlNode );
		CHECK_EQUAL(avlNode2.getRight()->getParent(), &avlNode2 );
		CHECK_EQUAL(avlNode2.getLeft(), &avlNode3 );
		CHECK_EQUAL(avlNode2.getLeft()->getParent(), &avlNode2 );

		avlNode2.reHeight();
		CHECK_EQUAL(avlNode2.getHeight(), 2 );

		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 0 );

		CHECK_EQUAL(avlNode2.findNext(), &avlNode ); // only for clear() method
		CHECK_EQUAL(avlNode2.findPrevious(), &avlNode3 ); // only for clear() method
	}

	TEST(AVLNodeTestRootRightLeftAndChilds)
	{
		AVLNode<int> avlNode(23,3,0,0,0);
		AVLNode<int> avlNode2(21,2,0,0,0);
		AVLNode<int> avlNode3(27,2,0,0,0);
		AVLNode<int> avlNode4(25,1,0,0,0);
		AVLNode<int> avlNode5(29,1,0,0,0);
		AVLNode<int> avlNode6(22,1,0,0,0);
		AVLNode<int> avlNode7(19,1,0,0,0);

		avlNode.setLeft(&avlNode2);
		avlNode2.setParent(&avlNode);
		avlNode.setRight(&avlNode3);
		avlNode3.setParent(&avlNode);

		avlNode2.setLeft(&avlNode7);
		avlNode7.setParent(&avlNode2);
		avlNode2.setRight(&avlNode6);
		avlNode6.setParent(&avlNode2);

		avlNode3.setLeft(&avlNode4);
		avlNode4.setParent(&avlNode3);
		avlNode3.setRight(&avlNode5);
		avlNode5.setParent(&avlNode3);


		avlNode.reHeight();
		CHECK_EQUAL(avlNode.getHeight(), 3 );
		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 0 );

		CHECK_EQUAL(avlNode.findNext(), &avlNode4 ); // only for clear() method
		CHECK_EQUAL(avlNode.findPrevious(), &avlNode6 ); // only for clear() method
	}

	TEST(AVLNodeTestRootAndRightLeftRotate)
	{
		AVLNode<int> avlNode(39,1,0,0,0);
		AVLNode<int> avlNode2(37,2,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setRight(&avlNode);

		avlNode.leftRotate();
		avlNode2.reHeight(); // reHeight manually
		avlNode.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 1 );
		CHECK_EQUAL(avlNode2.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode2.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode2.getParent(), &avlNode );

		CHECK_EQUAL(avlNode.getHeight(), 2 );
		CHECK_EQUAL(avlNode.getLeft(), &avlNode2 );
		CHECK_EQUAL(avlNode.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 1 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 0 );
	}

	TEST(AVLNodeTestRootAndLeftRightRotate)
	{
		AVLNode<int> avlNode(29,1,0,0,0);
		AVLNode<int> avlNode2(31,2,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setLeft(&avlNode);

		avlNode.rightRotate();
		avlNode2.reHeight(); // reHeight manually
		avlNode.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 1 );
		CHECK_EQUAL(avlNode2.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode2.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode2.getParent(), &avlNode );

		CHECK_EQUAL(avlNode.getHeight(), 2 );
		CHECK_EQUAL(avlNode.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getRight(), &avlNode2 );
		CHECK_EQUAL(avlNode.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), -1 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 0 );
	}

	TEST(AVLNodeTestRootRightLeftLeftRotate)
	{
		AVLNode<int> avlNode(27,1,0,0,0);
		AVLNode<int> avlNode2(23,2,0,0,0);
		AVLNode<int> avlNode3(21,1,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setRight(&avlNode);
		avlNode3.setParent(&avlNode2);
		avlNode2.setLeft(&avlNode3);

		avlNode.leftRotate();
		avlNode2.reHeight(); // reHeight manually
		avlNode.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 2 );
		CHECK_EQUAL(avlNode2.getLeft(), &avlNode3 );
		CHECK_EQUAL(avlNode2.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode2.getParent(), &avlNode );

		CHECK_EQUAL(avlNode.getHeight(), 3 );
		CHECK_EQUAL(avlNode.getLeft(), &avlNode2 );
		CHECK_EQUAL(avlNode.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode3.getHeight(), 1 );
		CHECK_EQUAL(avlNode3.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 2 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 1 );
		CHECK_EQUAL(avlNode3.reHeightAndGetBalance(), 0 );
	}

	TEST(AVLNodeTestRootRightRightLeftRotate)
	{
		AVLNode<int> avlNode(21,3,0,0,0);
		AVLNode<int> avlNode2(23,2,0,0,0);
		AVLNode<int> avlNode3(27,1,0,0,0);
		avlNode.setRight(&avlNode2);
		avlNode2.setParent(&avlNode);
		avlNode2.setRight(&avlNode3);
		avlNode3.setParent(&avlNode2);

		avlNode2.leftRotate();
		avlNode.reHeight(); // reHeight manually
		avlNode2.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 2 );
		CHECK_EQUAL(avlNode2.getLeft(), &avlNode );
		CHECK_EQUAL(avlNode2.getRight(), &avlNode3 );
		CHECK_EQUAL(avlNode2.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.getHeight(), 1 );
		CHECK_EQUAL(avlNode.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode3.getHeight(), 1 );
		CHECK_EQUAL(avlNode3.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode3.reHeightAndGetBalance(), 0 );
	}

	TEST(AVLNodeTestRootRightLeftRightRotate)
	{
		AVLNode<int> avlNode(27,1,0,0,0);
		AVLNode<int> avlNode2(23,2,0,0,0);
		AVLNode<int> avlNode3(21,1,0,0,0);
		avlNode.setParent(&avlNode2);
		avlNode2.setRight(&avlNode);
		avlNode3.setParent(&avlNode2);
		avlNode2.setLeft(&avlNode3);

		avlNode3.rightRotate();
		avlNode2.reHeight(); // reHeight manually
		avlNode3.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 2 );
		CHECK_EQUAL(avlNode2.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode2.getRight(), &avlNode );
		CHECK_EQUAL(avlNode2.getParent(), &avlNode3 );

		CHECK_EQUAL(avlNode.getHeight(), 1 );
		CHECK_EQUAL(avlNode.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode3.getHeight(), 3 );
		CHECK_EQUAL(avlNode3.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getRight(), &avlNode2 );
		CHECK_EQUAL(avlNode3.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), -1 );
		CHECK_EQUAL(avlNode3.reHeightAndGetBalance(), -2 );
	}

	TEST(AVLNodeTestRootLeftLeftRightRotate)
	{
		AVLNode<int> avlNode(27,3,0,0,0);
		AVLNode<int> avlNode2(23,2,0,0,0);
		AVLNode<int> avlNode3(21,1,0,0,0);
		avlNode.setLeft(&avlNode2);
		avlNode2.setParent(&avlNode);
		avlNode2.setLeft(&avlNode3);
		avlNode3.setParent(&avlNode2);

		avlNode2.rightRotate();
		avlNode.reHeight(); // reHeight manually
		avlNode2.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 2 );
		CHECK_EQUAL(avlNode2.getLeft(), &avlNode3 );
		CHECK_EQUAL(avlNode2.getRight(), &avlNode );
		CHECK_EQUAL(avlNode2.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.getHeight(), 1 );
		CHECK_EQUAL(avlNode.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode3.getHeight(), 1 );
		CHECK_EQUAL(avlNode3.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode3.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode3.reHeightAndGetBalance(), 0 );
	}

	TEST(AVLNodeTestRootRightLeftAndChildsLeftRotate)
	{
		AVLNode<int> avlNode(23,3,0,0,0);
		AVLNode<int> avlNode2(21,2,0,0,0);
		AVLNode<int> avlNode3(27,2,0,0,0);
		AVLNode<int> avlNode4(25,1,0,0,0);
		AVLNode<int> avlNode5(29,1,0,0,0);
		AVLNode<int> avlNode6(22,1,0,0,0);
		AVLNode<int> avlNode7(19,1,0,0,0);

		avlNode.setLeft(&avlNode2);
		avlNode2.setParent(&avlNode);
		avlNode.setRight(&avlNode3);
		avlNode3.setParent(&avlNode);

		avlNode2.setLeft(&avlNode7);
		avlNode7.setParent(&avlNode2);
		avlNode2.setRight(&avlNode6);
		avlNode6.setParent(&avlNode2);

		avlNode3.setLeft(&avlNode4);
		avlNode4.setParent(&avlNode3);
		avlNode3.setRight(&avlNode5);
		avlNode5.setParent(&avlNode3);

		avlNode3.leftRotate();
		avlNode.reHeight(); // reHeight manually
		avlNode3.reHeight(); // order matters

		CHECK_EQUAL(avlNode3.getHeight(), 4 );
		CHECK_EQUAL(avlNode3.getLeft(), &avlNode );
		CHECK_EQUAL(avlNode3.getRight(), &avlNode5 );
		CHECK_EQUAL(avlNode3.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.getHeight(), 3 );
		CHECK_EQUAL(avlNode.getLeft(), &avlNode2 );
		CHECK_EQUAL(avlNode.getRight(), &avlNode4 );
		CHECK_EQUAL(avlNode.getParent(), &avlNode3 );

		CHECK_EQUAL(avlNode4.getHeight(), 1 );
		CHECK_EQUAL(avlNode4.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode4.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode4.getParent(), &avlNode );

		CHECK_EQUAL(avlNode5.getHeight(), 1 );
		CHECK_EQUAL(avlNode5.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode5.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode5.getParent(), &avlNode3 );

		CHECK_EQUAL(avlNode2.getHeight(), 2 );
		CHECK_EQUAL(avlNode2.getLeft(), &avlNode7 );
		CHECK_EQUAL(avlNode2.getRight(), &avlNode6 );
		CHECK_EQUAL(avlNode2.getParent(), &avlNode );

		CHECK_EQUAL(avlNode6.getHeight(), 1 );
		CHECK_EQUAL(avlNode6.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode6.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode6.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode7.getHeight(), 1 );
		CHECK_EQUAL(avlNode7.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode7.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode7.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), 1 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode3.reHeightAndGetBalance(), 2 );
		CHECK_EQUAL(avlNode4.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode5.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode6.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode7.reHeightAndGetBalance(), 0 );
	}

	TEST(AVLNodeTestRootRightLeftAndChildsRightRotate)
	{
		AVLNode<int> avlNode(23,3,0,0,0);
		AVLNode<int> avlNode2(21,2,0,0,0);
		AVLNode<int> avlNode3(27,2,0,0,0);
		AVLNode<int> avlNode4(25,1,0,0,0);
		AVLNode<int> avlNode5(29,1,0,0,0);
		AVLNode<int> avlNode6(22,1,0,0,0);
		AVLNode<int> avlNode7(19,1,0,0,0);

		avlNode.setLeft(&avlNode2);
		avlNode2.setParent(&avlNode);
		avlNode.setRight(&avlNode3);
		avlNode3.setParent(&avlNode);

		avlNode2.setLeft(&avlNode7);
		avlNode7.setParent(&avlNode2);
		avlNode2.setRight(&avlNode6);
		avlNode6.setParent(&avlNode2);

		avlNode3.setLeft(&avlNode4);
		avlNode4.setParent(&avlNode3);
		avlNode3.setRight(&avlNode5);
		avlNode5.setParent(&avlNode3);

		avlNode2.rightRotate();
		avlNode.reHeight(); // reHeight manually
		avlNode2.reHeight(); // order matters

		CHECK_EQUAL(avlNode2.getHeight(), 4 );
		CHECK_EQUAL(avlNode2.getLeft(), &avlNode7 );
		CHECK_EQUAL(avlNode2.getRight(), &avlNode );
		CHECK_EQUAL(avlNode2.getParent(), reinterpret_cast<AVLNode<int>*>(0) );

		CHECK_EQUAL(avlNode.getHeight(), 3 );
		CHECK_EQUAL(avlNode.getLeft(), &avlNode6 );
		CHECK_EQUAL(avlNode.getRight(), &avlNode3 );
		CHECK_EQUAL(avlNode.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode4.getHeight(), 1 );
		CHECK_EQUAL(avlNode4.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode4.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode4.getParent(), &avlNode3 );

		CHECK_EQUAL(avlNode5.getHeight(), 1 );
		CHECK_EQUAL(avlNode5.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode5.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode5.getParent(), &avlNode3 );

		CHECK_EQUAL(avlNode3.getHeight(), 2 );
		CHECK_EQUAL(avlNode3.getLeft(), &avlNode4 );
		CHECK_EQUAL(avlNode3.getRight(), &avlNode5 );
		CHECK_EQUAL(avlNode3.getParent(), &avlNode );

		CHECK_EQUAL(avlNode6.getHeight(), 1 );
		CHECK_EQUAL(avlNode6.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode6.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode6.getParent(), &avlNode );

		CHECK_EQUAL(avlNode7.getHeight(), 1 );
		CHECK_EQUAL(avlNode7.getLeft(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode7.getRight(), reinterpret_cast<AVLNode<int>*>(0) );
		CHECK_EQUAL(avlNode7.getParent(), &avlNode2 );

		CHECK_EQUAL(avlNode.reHeightAndGetBalance(), -1 );
		CHECK_EQUAL(avlNode2.reHeightAndGetBalance(), -2 );
		CHECK_EQUAL(avlNode3.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode4.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode5.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode6.reHeightAndGetBalance(), 0 );
		CHECK_EQUAL(avlNode7.reHeightAndGetBalance(), 0 );
	}

}

#endif // AVLNODETEST_H_
