#include "Test.h"
#include <iostream>
#include <map>
using namespace std;

bool exists(vector<int> avl_tree, int number)
{
	int index = 0;
	while(index>=0 && index < avl_tree.size())
	{
		if (number > avl_tree[index])
		{
			index = index*2 + 2;
		}else if (number < avl_tree[index])
		{
			index = index*2 + 1;
		}else{
			return true;
		}
	}
	return false;
}

BinaryNode* appendNode(BinaryNode* node, vector<int> max_heap, int current_node)
{
	int index_left = current_node*2 + 1;
	int index_right = current_node*2 + 2;

	if (index_left < max_heap.size())
	{
		node->left_child = new BinaryNode(max_heap[index_left]);
		appendNode(node->left_child,max_heap,index_left);
	}
	if (index_right < max_heap.size())
	{
		node->right_child = new BinaryNode(max_heap[index_right]);
		appendNode(node->right_child,max_heap,index_right);
	}
}

BinaryNode* convertToLinkedTree(vector<int> max_heap)
{
  BinaryNode *node = new BinaryNode(max_heap[0]);
  appendNode(node,max_heap,0);
  return node;
}

int main ()
{
  test();
  return 0;
}






