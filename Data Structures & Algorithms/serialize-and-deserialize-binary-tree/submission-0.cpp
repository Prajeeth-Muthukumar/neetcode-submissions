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
        if(!root) return "N,";
        string res = "";
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            TreeNode* node = nodes.front();
            nodes.pop();
            if(!node) res += "N,";
            else{
                res += to_string(node->val)+",";
                nodes.push(node->left);
                nodes.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (data.empty() || data == "N,") return nullptr;

        int i = 0;
        
        // Find first node
        int commaPos = data.find(',', i);
        string val = data.substr(i, commaPos - i);
        i = commaPos + 1;

        if (val == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        // Standard BFS without the inner size loop
        while (!q.empty() && i < data.size()) {
            TreeNode* node = q.front();
            q.pop();

            // 1. Process Left Child
            commaPos = data.find(',', i);
            if (commaPos != string::npos) {
                val = data.substr(i, commaPos - i);
                i = commaPos + 1;
                if (val != "N") {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            // 2. Process Right Child
            commaPos = data.find(',', i);
            if (commaPos != string::npos) {
                val = data.substr(i, commaPos - i);
                i = commaPos + 1;
                if (val != "N") {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));