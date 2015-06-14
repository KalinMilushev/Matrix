#include <iostream>
#include <fstream>
#include "Complex.h"
#include "Matrix.h"
using namespace std;

void menu()
{
	cout << "1.Det\n";
	cout << "2.Inverse\n";
	cout << "3.Transpose\n";
	cout << "4.Operation\n";
	cout << "5.Exit\n";
	
}
void menu2()
{
	cout << "1.Add number\n";
	cout << "2.Multyply by number\n";
	cout << "3. + another matrix\n";
	cout << "4. - another matrix\n";
	cout << "5. * another matrix\n";
}
int main()
{
	
	int dim1, dim2;
	cout << "dimensions: \n";
	cin >> dim1 >> dim2;
	Matrix matrix(dim1, dim2);
	matrix.accept();
	int choice;
	menu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << matrix.Det() << endl;
		menu();
		break;
	case 2:
		matrix.Inverse().display();
		menu();
		matrix.Inverse().CopyToFile();
		break;
	case 3:
		matrix.Transpose().display();
		menu();
		matrix.Transpose().CopyToFile();
		break;
	case 4:
		menu2();
		int choice2;
		cin >> choice2;
		if (choice2 == 1)
		{
			cout << "number: \n";
			double n;
			cin >> n;
			(matrix + n).display();
			(matrix + n).CopyToFile();

		}
		if (choice2 == 2)
		{
			cout << "number: \n";
			double n;
			cin >> n;
			(matrix*n).display();
			(matrix*n).CopyToFile();
		}
		if (choice2 == 3)
		{
			Matrix temp(dim1,dim2);
			temp.accept();
			(matrix + temp).display();
			(matrix + temp).CopyToFile();
		}
		if (choice2 == 4)
		{
			Matrix temp(dim1, dim2);
			temp.accept();
			(matrix - temp).display();
			(matrix - temp).CopyToFile();
		}
		if (choice2 == 5)
		{
			int p,q;
			cout << "dims of new matrix:\n";
			cin >> p >> q;
			if (dim2 == p)
			{
				Matrix temp(p, q);
				temp.accept();
				(matrix*temp).display();
				(matrix*temp).CopyToFile();
			}
			else cout << "error" << endl;
		}
		break;
	case 5:
		break;
	default:
		break;
	}
	
}
