#ifndef _TREE_H_
#define _TREE_H_

extern int columnZero(char matrix[5][5]);
extern int columnOne(char matrix[5][5]);
extern int columnTwo(char matrix[5][5]);
extern int columnThree(char matrix[5][5]);
extern int columnFour(char matrix[5][5]);

#include <iostream>

using namespace std;

class Tree
{
public:
	Tree() = default;
	~Tree()
	{
		deleteTree(*this);
	}

	friend int count(const Tree& tree)
	{
		return tree.cnt;
	}

	friend void insertNode(char matrica[5][5], Tree& tree);

	friend ostream& operator<<(ostream& os, const Tree& tree);

	friend void deleteTree(Tree& tree);

	void setPlayer(char p)
	{
		root->player = p;
	}

	char getPlayer()
	{
		return root->player;
	}

	char getWinner()
	{
		return root->winner;
	}

	void setWinner(char c)
	{
		root->winner = c;
	}

	friend void finish(Tree& tree);

	int count() const
	{
		return this->cnt;
	}

private:
	struct Node
	{
		int turn;
		bool leaf = false;
		char winner = '/';
		char player = '/';
		char matrix[5][5];
		Node* parent;
		Node** child;

		Node(Node* p = nullptr) : parent(p)
		{
			child = new Node * [5];
			for (int i = 0; i < 5; i++)
				child[i] = nullptr;
		}

		~Node()
		{
			delete[] child;
		}
	public:
		char getWinnerr()
		{
			return winner;
		}

		void setWinnerr(char c)
		{
			winner = c;
		}

		bool gameOverr();
		void minimax();
	};

	int degree = 5;
	int cnt = 0;
	Node* root = nullptr;
};

#endif
