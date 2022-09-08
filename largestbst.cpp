/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include <climits>
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

int BSTHeight(BinaryTreeNode<int> *root){
    if(root == NULL )
        return 0;
    
    return max(BSTHeight(root -> left ),BSTHeight(root -> right))+1;
}

    NodeValue largestBSTSubtreeHelper(BinaryTreeNode<int>* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        
        NodeValue left = largestBSTSubtreeHelper(root->left);
        NodeValue right = largestBSTSubtreeHelper(root->right);

        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(min(root->data, left.minNode),max(root->data, right.maxNode),BSTHeight(root));
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
int largestBSTSubtree(BinaryTreeNode<int>* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
    