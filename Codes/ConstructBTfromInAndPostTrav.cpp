class Solution {
public:
	typedef vector<int>::iterator vit;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty())
        	return NULL;
        return buildTreeAux(inorder.begin(), inorder.end() - 1, postorder.begin(), postorder.end() - 1);
    }
    TreeNode *buildTreeAux(vit istart, vit iend, vit pstart, vit pend) {
        if (pstart > pend)
            return NULL;
    	TreeNode *node;
    	vit mid = find(istart, iend, *(pend));
    	node = new TreeNode(*(mid));
    	node->left = buildTreeAux(istart, mid - 1, pstart, pstart + (mid-1 - istart));
    	node->right = buildTreeAux(mid + 1, iend, pend - (iend - mid), pend-1);
    	return node;
    }
};
