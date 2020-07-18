#include "tree.h"
#include <time.h>
#include <stdlib.h>

int main()
{
	int choice;
	Tree tree = Tree();
	char help[5][5];
	int kolona, vrsta;
	bool flag = false;
	srand(time(NULL));
	double sum = 0;

	cout << "**************************\n";
	cout << "1. Form an initial game tree\n";
	cout << "2. Create the game tree\n";
	cout << "3. Print the game tree\n";
	cout << "4. Delete the game tree\n";
	cout << "5. End of program\n";
	cout << "6. Number od nodes\n";

	while (true)
	{
		cout << "Your choice? \n";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << "Form an initial game matrix: \n";

				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						cin >> help[i][j];
					}
					cin.get();
				}

				insertNode(help, tree);

				for (int i = 0; i < 20; i++)
				{
					double rx = rand() / (RAND_MAX + 1.);
					sum += rx;
				}

				sum /= 20.;

				if (sum < 0.5)
				{
					tree.setPlayer('X');
				}
				else
				{
					tree.setPlayer('O');
				}
					
				break;
			case 2:
				finish(tree);

				break;
			case 3:
				if (!count(tree))
				{
					cout << "Tree is empty!";
				}
				else
				{
					cout << "Tree: \n" << tree;
				}

				break;
			case 4:
				deleteTree(tree);

				break;
			case 5:
				exit(0);
			case 6:
				cout << "Node count: " << tree.count();
		}
		cout << endl << endl;
	}
}