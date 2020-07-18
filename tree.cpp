#include "tree.h"
#include "stack.h"
#include "queue.h"

void deleteTree(Tree& tree)
{
	Stack<Tree::Node*> nodes;
	if (tree.root)
	{
		push(nodes, tree.root);
	}
	while (nodes.notEmpty())
	{
		Tree::Node* temp = pop(nodes);
		for (int i = tree.degree - 1; i >= 0; i--)
			if (temp->child[i])
			{
				push(nodes, temp->child[i]);
				temp->child[i] = nullptr;
			}
		delete temp;
	}
}

ostream& operator<<(ostream& os, const Tree& tree)
{
	Queue<Tree::Node*> queue;

	if (tree.root)
	{
		insert(queue, tree.root);
	}

	while (queue.notEmpty())
	{
		Tree::Node* temp = remove(queue);

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				cout << temp->matrix[i][j] << ' ';
			}
			cout << '\n';
		}
		for (int i = 0; i <= 4; i++)
		{
			if (temp->child[i])
			{
				insert(queue, temp->child[i]);
			}
		}
		cout << '\n';
		cout << "The winner is: " << temp->winner << endl;
		cout << '\n';
	}
	return os;
}

void insertNode(char matrica[5][5], Tree& tree)
{
	++tree.cnt;
	bool flag = false;
	Stack<Tree::Node*> nodes, helper;
	Tree::Node* n = new Tree::Node();
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			n->matrix[i][j] = matrica[i][j];
		}
	}
	if (!tree.root)
	{
		tree.root = n;
	}
	else
	{
		push(nodes, tree.root);
		while (nodes.notEmpty())
		{
			Tree::Node* temp = pop(nodes);
			for (int i = 0; i < tree.degree; i++)
				if (!temp->child[i])
				{
					temp->child[i] = n;
					temp->child[i]->parent = temp;
					flag = true;
					break;
				}
			if (flag)
			{
				break;
			}
			for (int i = 0; i < tree.degree; i++)
			{
				if (temp->child[i])
				{
					push(helper, temp->child[i]);
				}
			}
			if (!nodes.notEmpty())
			{
				while (helper.notEmpty())
				{
					push(nodes, pop(helper));
				}
			}
		}
	}
}

void finish(Tree& tree)
{
	if (tree.root->gameOverr())
	{
		return;
	}
	Queue<Tree::Node*> queue;
	insert(queue, tree.root);
	while (queue.notEmpty())
	{
		Tree::Node* temp = remove(queue);
		char help[5][5];

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				help[i][j] = temp->matrix[i][j];
			}
		}
		if (columnZero(temp->matrix) != -1)
		{
			help[columnZero(temp->matrix)][0] = temp->player;
			Tree::Node* n = new Tree::Node();
			tree.cnt++;
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j <= 4; j++)
				{
					n->matrix[i][j] = help[i][j];
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				if (!temp->child[i])
				{
					temp->child[i] = n;
					n->parent = temp->child[i];
					break;
				}
			}
		}

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				help[i][j] = temp->matrix[i][j];
			}
		}
		if (columnOne(temp->matrix) != -1)
		{
			help[columnOne(temp->matrix)][1] = temp->player;
			Tree::Node* n = new Tree::Node();
			tree.cnt++;
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j <= 4; j++)
				{
					n->matrix[i][j] = help[i][j];
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				if (!temp->child[i])
				{
					temp->child[i] = n;
					n->parent = temp->child[i];
					break;
				}
			}
		}

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				help[i][j] = temp->matrix[i][j];
			}
		}
		if (columnTwo(temp->matrix) != -1)
		{
			help[columnTwo(temp->matrix)][2] = temp->player;
			Tree::Node* n = new Tree::Node();
			tree.cnt++;
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j <= 4; j++)
				{
					n->matrix[i][j] = help[i][j];
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				if (!temp->child[i])
				{
					temp->child[i] = n;
					n->parent = temp->child[i];
					break;
				}
			}
		}

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				help[i][j] = temp->matrix[i][j];
			}
		}
		if (columnThree(temp->matrix) != -1)
		{
			help[columnThree(temp->matrix)][3] = temp->player;
			Tree::Node* n = new Tree::Node();
			tree.cnt++;
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j <= 4; j++)
				{
					n->matrix[i][j] = help[i][j];
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				if (!temp->child[i])
				{
					temp->child[i] = n;
					n->parent = temp->child[i];
					break;
				}
			}
		}

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				help[i][j] = temp->matrix[i][j];
			}
		}
		if (columnFour(temp->matrix) != -1)
		{
			help[columnFour(temp->matrix)][4] = temp->player;
			Tree::Node* n = new Tree::Node();
			tree.cnt++;
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j <= 4; j++)
				{
					n->matrix[i][j] = help[i][j];
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				if (!temp->child[i])
				{
					temp->child[i] = n;
					n->parent = temp->child[i];
					break;
				}
			}
		}

		if (temp->player == 'X')
		{
			for (int i = 0; i <= 4; i++)
			{
				if (temp->child[i]) temp->child[i]->player = 'O';
			}
		}
		else if (temp->player == 'O')
		{
			for (int i = 0; i <= 4; i++)
			{
				if (temp->child[i]) temp->child[i]->player = 'X';
			}
		}

		for (int i = 0; i <= 4; i++)
		{
			if (temp->child[i])
			{
				if (temp->child[i]->gameOverr())
				{
					temp->child[i]->leaf = true;
				}
			}
		}
		for (int i = 0; i <= 4; i++)
		{
			if (temp->child[i])
			{
				if (!(temp->child[i]->gameOverr()))
				{
					bool flag = true;
					for (int j = 0; j <= 4; j++)
					{
						for (int k = 0; k <= 4; k++)
						{
							if (temp->child[i]->matrix[j][k] == '/')
							{
								flag = false; break;
							}
						}
						if (!flag) break;
					}
					if (flag)
					{
						temp->child[i]->leaf = true;
						temp->child[i]->winner = '/';
					}
				}
			}
		}
		for (int i = 0; i <= 4; i++)
		{
			if (temp->child[i])
			{
				if (!(temp->child[i]->leaf))
				{
					insert(queue, temp->child[i]);
				}
			}
		}
	}
}

bool Tree::Node::gameOverr()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (matrix[i][j] == 'X' && matrix[i + 1][j + 1] == 'X' && matrix[i + 2][j + 2] == 'X')
			{
				setWinnerr('X');
				return true;
			}
			if (matrix[i][j] == 'O' && matrix[i + 1][j + 1] == 'O' && matrix[i + 2][j + 2] == 'O')
			{
				setWinnerr('O');
				return true;
			}
		}
	}

	for (int i = 0; i <= 2; i++)
	{
		for (int j = 4; j >= 2; j--)
		{
			if (matrix[i][j] == 'X' && matrix[i + 1][j - 1] == 'X' && matrix[i + 2][j - 2] == 'X')
			{
				setWinnerr('X');
				return true;
			}
			if (matrix[i][j] == 'O' && matrix[i + 1][j - 1] == 'O' && matrix[i + 2][j - 2] == 'O')
			{
				setWinnerr('O');
				return true;
			}
		}
	}

	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (matrix[i][j] == 'X' && matrix[i][j + 1] == 'X' && matrix[i][j + 2] == 'X' && j >= 0 && j <= 2)
			{
				setWinnerr('X');
				return true;
			}
			if (matrix[i][j] == 'O' && matrix[i][j + 1] == 'O' && matrix[i][j + 2] == 'O' && j >= 0 && j <= 2)
			{
				setWinnerr('O');
				return true;
			}
		}
	}

	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (matrix[i][j] == 'X' && matrix[i + 1][j] == 'X' && matrix[i + 2][j] == 'X' && i >= 0 & i <= 2)
			{
				setWinnerr('X');
				return true;
			}
			if (matrix[i][j] == 'O' && matrix[i + 1][j] == 'O' && matrix[i + 2][j] == 'O' && i >= 0 & i <= 2)
			{
				setWinnerr('O');
				return true;
			}
		}
	}
	return false;
}

void Tree::Node::minimax()
{
	if (player == 'X')
	{
		for (int i = 0; i <= 4; i++)
		{
			if (child[i] && child[i]->leaf)
			{
				if (child[i]->winner == 'X')
				{
					turn = 1;
				}
				else if (child[i]->winner == '/')
				{
					turn = 0;
				}
				else turn = -1;
			}
		}
	}
	else if (player == 'O')
	{
		for (int i = 0; i <= 4; i++)
		{
			if (child[i] && child[i]->leaf)
			{
				if (child[i]->winner == 'O')
				{
					turn = -1;
				}
				else if (child[i]->winner == '/')
				{
					turn = 0;
				}
				else turn = 1;
			}
		}
	}
	else return;
}