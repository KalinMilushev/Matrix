#include "Matrix.h"
#include <fstream>

Matrix::Matrix()
{
	p = NULL;
	m = 0;
	n = 0;
}
Matrix::Matrix(const int row_count, const int column_count)
{
	p = NULL;
	if (row_count > 0 && column_count > 0)
	{
		m = row_count;
		n = column_count;

		p = new double*[m];
		for (int r = 0; r < m; r++)
		{
			p[r] = new double[n];
			for (int c = 0; c < n; c++)
			{
				p[r][c] = 0;
			}
		}
	}
}
Matrix::Matrix(const Matrix & a)
{
	m = a.m;
	n = a.n;
	p = new double*[a.m];
	for (int r = 0; r < a.m; r++)
	{
		p[r] = new double[a.n];
		for (int c = 0; c < a.n; c++)
		{
			p[r][c] = a.p[r][c];
		}
	}
}
Matrix::~Matrix()
{
	for (int r = 0; r < m; r++)
	{
		delete p[r];
	}
	delete p;
	p = NULL;
}
double& Matrix::operator()(const int r, const int c)
{
	if (p != NULL && r > 0 && r <= m && c > 0 && c <= n)
	{
		return p[r - 1][c - 1];
	}
	else
	{
		cout << "error";
	}
}
double Matrix::get(const int r, const int c) const
{
	if (p != NULL && r > 0 && r <= m && c > 0 && c <= n)
	{
		return p[r - 1][c - 1];
	}
}
Matrix& Matrix::operator= (const Matrix& a) 
{
	m = a.m;
	n = a.n;
	p = new double*[a.m];
	for (int r = 0; r < a.m; r++)
	{
		p[r] = new double[a.n];
		for (int c = 0; c < a.n; c++)
		{
			p[r][c] = a.p[r][c];
		}
	}
	return *this;
}
Matrix& Matrix::Add(const double v)
{
	for (int r = 0; r < m; r++)
	{
		for (int c = 0; c < n; c++)
		{
			p[r][c] += v;
		}
	}
	return *this;
}
Matrix& Matrix::Subtract(const double v)
{
	return Add(-v);
}
Matrix& Matrix::Multiply(const double v)
{
	for (int r = 0; r < m; r++)
	{
		for (int c = 0; c < n; c++)
		{
			p[r][c] *= v;
		}
	}
	return *this;
}
Matrix& Matrix::Divide(const double v)
{
	return Multiply(1 / v);
}
Matrix Matrix::operator+(const Matrix& b)
{
	if (this->m == b.m && this->n == b.n)
	{
		Matrix res(this->m, this->n);

		for (int r = 0; r < this->m; r++)
		{
			for (int c = 0; c < this->n; c++)
			{
				res.p[r][c] = this->p[r][c] + b.p[r][c];
			}
		}
		return res;
	}
	return Matrix();
}
Matrix Matrix::operator+(const double b)
{
	Matrix res;
	res.m = this->m;
	res.n = this->n;
	res.p = new double*[this->m];
	for (int r = 0; r < this->m; r++)
	{
		res.p[r] = new double[this->n];
		for (int c = 0; c < this->n; c++)
		{
			res.p[r][c] = this->p[r][c];
		}
	}
	res.Add(b);
	return res;
}
Matrix Matrix::operator-(const Matrix& b)
{
	if (this->m == b.m && this->n == b.n)
	{
		Matrix res(this->m, this->n);

		for (int r = 0; r < this->m; r++)
		{
			for (int c = 0; c < this->n; c++)
			{
				res.p[r][c] = this->p[r][c] - b.p[r][c];
			}
		}
		return res;
	}
	return Matrix();
}
Matrix Matrix::operator-(const double b)
{
	Matrix res;
	res.m = this->m;
	res.n = this->n;
	res.p = new double*[this->m];
	for (int r = 0; r < this->m; r++)
	{
		res.p[r] = new double[this->n];
		for (int c = 0; c < this->n; c++)
		{
			res.p[r][c] = this->p[r][c];
		}
	}
	res.Subtract(b);
	return res;
}
Matrix Matrix::operator*(const Matrix& b)
{
	if (this->n == b.m)
	{
		Matrix res(this->m, b.n);

		for (int r = 0; r < this->m; r++)
		{
			for (int c_res = 0; c_res < b.n; c_res++)
			{
				for (int c = 0; c < this->n; c++)
				{
					res.p[r][c_res] += this->p[r][c] * b.p[c][c_res];
				}
			}
		}
		return res;
	}
	return Matrix();
}
Matrix Matrix::operator*(const double b)
{
	Matrix res;
	res.m = this->m;
	res.n = this->n;
	res.p = new double*[this->m];
	for (int r = 0; r < this->m; r++)
	{
		res.p[r] = new double[this->n];
		for (int c = 0; c < this->n; c++)
		{
			res.p[r][c] = this->p[r][c];
		}
	}
	res.Multiply(b);
	return res;
}
Matrix Matrix::operator/(const Matrix& b)
{
	Matrix res;
	res.m = this->m;
	res.n = this->n;
	res.p = new double*[this->m];
	for (int r = 0; r < this->m; r++)
	{
		res.p[r] = new double[this->n];
		for (int c = 0; c < this->n; c++)
		{
			res.p[r][c] = this->p[r][c];
		}
	}
	Matrix res2;
	res2.m = b.m;
	res2.n = b.n;
	res2.p = new double*[b.m];
	for (int r = 0; r < b.m; r++)
	{
		res2.p[r] = new double[b.n];
		for (int c = 0; c < b.n; c++)
		{
			res2.p[r][c] = b.p[r][c];
		}
	}
	if (this->m == this->n && this->m == b.n && b.m == b.n)
	{
		Matrix res1(this->m, this->n);

		res1 = res*res2.Inverse();

		return res1;
	}
	return Matrix();
}
Matrix Matrix::operator/(const double b)
{
	Matrix res;
	res.m = this->m;
	res.n = this->n;
	res.p = new double*[this->m];
	for (int r = 0; r < this->m; r++)
	{
		res.p[r] = new double[this->n];
		for (int c = 0; c < this->n; c++)
		{
			res.p[r][c] = this->p[r][c];
		}
	}
	res.Divide(b);
	return res;
}
Matrix Matrix::Minor(const int row, const int col) const
{
	Matrix res;
	if (row > 0 && row <= m && col > 0 && col <= n)
	{
		res = Matrix(m - 1, n - 1);
		for (int r = 1; r <= (m - (row >= m)); r++)
		{
			for (int c = 1; c <= (n - (col >= n)); c++)
			{
				res(r - (r > row), c - (c > col)) = p[r - 1][c - 1];
			}
		}
	}
	return res;
}
int Matrix::Size(const int i) const
{
	if (i == 1)
	{
		return m;
	}
	else if (i == 2)
	{
		return n;
	}
	return 0;
}
int Matrix::GetRows() const
{
	return m;
}
int Matrix::GetCols() const
{
	return n;
}
Matrix Matrix::Diag(const int n)
{
	Matrix res = Matrix(n, n);
	for (int i = 1; i <= n; i++)
	{
		res(i, i) = 1;
	}
	return res;
}
Matrix Matrix::Diag(const Matrix& v)
{
	Matrix res;
	if (v.GetCols() == 1)
	{
		int rows = v.GetRows();
		res = Matrix(rows, rows);
		for (int r = 1; r <= rows; r++)
		{
			res(r, r) = v.get(r, 1);
		}
	}
	else if (v.GetRows() == 1)
	{
		int cols = v.GetCols();
		res = Matrix(cols, cols);
		for (int c = 1; c <= cols; c++)
		{
			res(c, c) = v.get(1, c);
		}
	}
	return res;
}
double Matrix::Det() const
{
	double d = 0;
	int rows = this->m;
	int cols = this->n;

	if (rows == cols)
	{
		if (rows == 1)
		{
			d = this->get(1, 1);
		}
		else if (rows == 2)
		{
			d = this->get(1, 1) * this->get(2, 2) - this->get(2, 1) * this->get(1, 2);
		}
		else
		{
			for (int c = 1; c <= cols; c++)
			{
				Matrix M = this->Minor(1, c);
				d += (c % 2 + c % 2 - 1) * this->get(1, c) * M.Det();
			}
		}
	}
	return d;
}
void Matrix::Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
Matrix Matrix::CoFactor()
{
	Matrix cofactor(m, n);
	if (m != n)
		return cofactor;

	if (m < 2)
		return cofactor;
	else if (m == 2)
	{
		cofactor.p[0][0] = p[1][1];
		cofactor.p[0][1] = -p[1][0];
		cofactor.p[1][0] = -p[0][1];
		cofactor.p[1][1] = p[0][0];
		return cofactor;
	}
	else if (m >= 3)
	{
		int DIM = m;
		Matrix ***temp = new Matrix**[DIM];
		for (int i = 0; i < DIM; i++)
			temp[i] = new Matrix*[DIM];
		for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++)
			temp[i][j] = new Matrix(DIM - 1, DIM - 1);

		for (int k1 = 0; k1 < DIM; k1++)
		{
			for (int k2 = 0; k2 < DIM; k2++)
			{
				int i1 = 0;
				for (int i = 0; i < DIM; i++)
				{
					int j1 = 0;
					for (int j = 0; j < DIM; j++)
					{
						if (k1 == i || k2 == j)
							continue;
						temp[k1][k2]->p[i1][j1++] = this->p[i][j];
					}
					if (k1 != i)
						i1++;
				}
			}
		}

		bool flagPositive = true;
		for (int k1 = 0; k1 < DIM; k1++)
		{
			flagPositive = ((k1 % 2) == 0);

			for (int k2 = 0; k2 < DIM; k2++)
			{
				if (flagPositive == true)
				{
					cofactor.p[k1][k2] = temp[k1][k2]->Det();
					flagPositive = false;
				}
				else
				{
					cofactor.p[k1][k2] = -temp[k1][k2]->Det();
					flagPositive = true;
				}
			}

		}

		for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++)
			delete temp[i][j];

		for (int i = 0; i < DIM; i++)
			delete[] temp[i];

		delete[] temp;
	}
	return cofactor;
}
Matrix Matrix::Adjoint()
{
	Matrix cofactor(m, n);
	Matrix adj(m, n);
	if (m != n)
		return adj;

	cofactor = this->CoFactor();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			adj.p[j][i] = cofactor.p[i][j];
		}
	}
	return adj;
}
Matrix Matrix::Transpose()
{
	Matrix trans(n, m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			trans.p[j][i] = p[i][j];
		}
	}
	return trans;
}
Matrix Matrix::Inverse()
{
	Matrix cofactor(m, n);
	Matrix inv(m, n);
	if (m != n)
		return inv;
	double det = Det();
	cofactor = this->CoFactor();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			inv.p[j][i] = cofactor.p[i][j] / det;
		}
	}
	return inv;
}
void Matrix::accept()
{
	cout << "Enter matrix elements:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> p[i][j];
		}
	}
}
void Matrix::display()
{
	cout << "The matrix is:" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << p[i][j] << " ";
		}
	}
	cout << endl;
}
void Matrix::CopyToFile()
{
	ofstream myfile;
	myfile.open("Example.txt");
	cout << "The matrix is:" << endl;
	for (int i = 0; i < this->m; i++)
	{
		myfile << endl;
		for (int j = 0; j < this->n; j++)
		{
			myfile << this->p[i][j] << endl;
		}
	}
	myfile << endl;
	myfile.close();
}
