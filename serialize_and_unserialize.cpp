// Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

// For example, given the following Node class

// class Node:
//     def __init__(self, val, left=None, right=None):
//         self.val = val
//         self.left = left
//         self.right = right
// The following test should pass:

// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

// LEETCODE SERIALIZATION:
//              1
//             / \
//            2   3
//               / \
//              4   5
// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// THIS IS a BFS traversal given the placement of the nulls
// DFS would be same in this case too

// NOTES:
// - A binary tree has at most two children
// - required recursion
// - to serialize, we convert the tree into a string:
// - the above case: 
// - tree: Node('root', Node('left', Node('left.left')), Node('right'))
// - serialized: 
// - in the case above, the value is the type of node in relation to its parent, left is the left node, right is the right node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream tree_serialized;
        serialize_helper(root, tree_serialized); 
        return tree_serialized.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }

    void serialize_helper(TreeNode* root, stringstream& tree_ser) {
        if (root != nullptr) {
            tree_ser << " ";
            tree_ser << root->val;
            serialize_helper(root->left, tree_ser);
            serialize_helper(root->right, tree_ser);
        }
        else {
            tree_ser << " ";
            tree_ser << "NULL";
        }
    }
    TreeNode* deserialize_helper(stringstream& tree_ser) {
        string nodeval;
        tree_ser >> nodeval;
        if (nodeval == "NULL") {
            return nullptr;
        }
        TreeNode* n = new TreeNode(stoi(nodeval));
        n->left = deserialize_helper(tree_ser);
        n->right = deserialize_helper(tree_ser);
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));