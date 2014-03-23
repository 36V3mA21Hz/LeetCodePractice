class Solution {
public:
	typedef vector<int>::iterator vit;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.empty())
        	return NULL;
        return buildTreeAux(inorder.begin(), inorder.end()-1, preorder.begin(), preorder.end()-1);
    }
    TreeNode *buildTreeAux(vit istart, vit iend, vit pstart, vit pend) {
    	if (pstart > pend)
    		return NULL;
    	vit mid = find(istart, iend, *(pstart));
    	TreeNode *node;
    	node = new TreeNode(*mid);
    	node->left = buildTreeAux(istart, mid - 1, pstart + 1, pstart + (mid - istart));
    	node->right = buildTreeAux(mid + 1, iend, pend - (iend - mid-1), pend);
    	return node;
    }
};
