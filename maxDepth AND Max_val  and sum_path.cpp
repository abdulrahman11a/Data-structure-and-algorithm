#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <numeric> // std::accumulate
#include <cassert>
#include <string>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
};
struct trre_Node
{

    int Data;

    trre_Node *Left{}, *right{};
    trre_Node(int val) : Data(val) {}
};
class binary_tree
{
public:
    int MAX = 0;
    trre_Node *Root{};
    binary_tree(int Value_Root) : Root(new trre_Node(Value_Root)) {}

    void Add_new_node(vector<int> values, vector<char> direction)
    {
        int n = values.size();
        // assert(values.size() == direction.size());

        trre_Node *cur = this->Root;
        for (int i = 0; i < n; i++)
        {

            if (toupper(direction[i]) == 'L')
            {
                if (!cur->Left)
                    cur->Left = new trre_Node(values[i]);
                cur = cur->Left;
            }

            else
            {

                if (!cur->right)
                    cur->right = new trre_Node(values[i]);
                cur = cur->right;
            }
        }
    }
    void _print_inorder(trre_Node *current)
    {
        if (!current)
            return;
        _print_inorder(current->Left);
        cout << current->Data << " ";
        _print_inorder(current->right);
    }
      bool _hasPathSum(trre_Node* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        if (root->Left == nullptr && root->right == nullptr) {
            return targetSum == root->Data;
        }
        
        return _hasPathSum(root->Left, targetSum - root->Data) ||
               _hasPathSum(root->right, targetSum - root->Data);
    }
        bool hasPathSum(int targetSum)
    {
                   return _hasPathSum(Root,targetSum);
    }
        void print_inorder()
        {
            _print_inorder(Root);
            cout << "\n";
        }

        int _Max_val(trre_Node * current)
        {
            int Max = INT_MIN;
            if (!current)
                return INT_MIN;

            int LM = _Max_val(current->Left);
            int RM = _Max_val(current->right);

            Max = max(max(LM, RM), max(current->Data, Max));
            return Max;
        }

        int Max_val()
        {
            return _Max_val(Root);
            cout << "\n";
        }

        int _maxDepth(trre_Node * current)
        {
            if (!current)
            {
                return 0;
            }

            int leftDepth = _maxDepth(current->Left);
            int rightDepth = _maxDepth(current->right);

            // Update MAX with the maximum depth found so far
            MAX = max(MAX, leftDepth + rightDepth);

            // Return the depth of the current node
            return max(leftDepth, rightDepth) + 1;
        }

        int maxDepth()
        {
            _maxDepth(Root);
            return MAX;
        }
    };

int main()
{
    binary_tree tree(1);
    tree.Add_new_node({2, 4, 7, 5, 6}, {'L', 'L', 'L', 'L', 'R'});
    // cout << tree.hasPathSum(18);

   cout << tree.Max_val();
    // tree.Add_new_node({2, 4, 8}, {'L', 'L', 'R'});
    // cout << tree.Max_val();
    // tree.Add_new_node({2, 5, 9}, {'L', 'R', 'R'});
    // cout << tree.Max_val();
    // tree.Add_new_node({3, 6, 10}, {'R', 'R', 'L'});
    // cout << tree.Max_val();

    return 0;
}