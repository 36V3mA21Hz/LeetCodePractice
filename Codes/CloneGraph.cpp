/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> nodeMap;
        return dfsClone(node, nodeMap);
    }
    UndirectedGraphNode *dfsClone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &nodeMap) {
        if (!node) return NULL;
        if (nodeMap.find(node->label) != nodeMap.end())
            return nodeMap.find(node->label)->second;
        UndirectedGraphNode *copyNode;
        copyNode = new UndirectedGraphNode(node->label);
        nodeMap.emplace(copyNode->label, copyNode);
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (node->neighbors[i] == node)
                copyNode->neighbors.push_back(copyNode);
            else 
                copyNode->neighbors.push_back(dfsClone(node->neighbors[i], nodeMap));
        }
        return copyNode;
    }
};