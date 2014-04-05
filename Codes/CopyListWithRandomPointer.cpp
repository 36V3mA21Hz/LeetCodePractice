class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
        	return NULL;
        unordered_map<int, RandomListNode*> temp;
        RandomListNode *node = head->next, *node2 = NULL, *head2 = new RandomListNode(head->label);
        node2 = head2;
        temp.insert({node2->label, node2});
        while (node) {
            node2->next = new RandomListNode(node->label);
            node2 = node2->next;
        	temp.insert({node2->label, node2});
        	node = node->next;
        }
        node = head;
        node2 = head2;
        while (node) {
        	if (node->random) {
        		auto got = temp.find(node->random->label);
        		node2->random = got->second;
        	} else {
        		node2->random = NULL;
        	}
        	node = node->next;
        	node2 = node2->next;
        }
        return head2;
    }
};
