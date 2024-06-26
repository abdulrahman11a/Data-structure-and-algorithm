#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <numeric> // std::accumulate
#include <cassert>
#include <string>

using namespace std;

struct trre_Node
{

    int Data;

    trre_Node *Left{}, *right{};
    trre_Node(int val) : Data(val) {}
};
class binary_tree
{
    public:

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
    	void _print_inorder(trre_Node* current) {
		if (!current)
			return;
		_print_inorder(current->Left);
		cout << current->Data << " ";
		_print_inorder(current->right);
	}


	void print_inorder() {
		_print_inorder(Root);
		cout << "\n";
	}
};

int main()
{
    binary_tree tree(1);
    tree.Add_new_node({2, 4, 7}, {'L', 'L', 'L'});
    tree.Add_new_node({2, 4, 8}, {'L', 'L', 'R'});
    tree.Add_new_node({2, 5, 9}, {'L', 'R', 'R'});
    tree.Add_new_node({3, 6, 10}, {'R', 'R', 'L'});

    tree.print_inorder(); // Output: 7 4 8 2 5 9 1 3 10 6

    return 0;
}