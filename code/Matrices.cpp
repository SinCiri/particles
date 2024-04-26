#include "Matrices.h"

using namespace std;


//we are working within the matrices name space, and when we are using them we use the namespace we declared. in main.
namespace Matrices {


	Matrix::Matrix(int _rows, int _cols) {
		rows = _rows;
		cols = _cols;
		a = vector<vector<double>>(rows, vector<double>(cols));
	}


	Matrix operator+(const Matrix& a, const Matrix& b) {
		Matrix c(a.getRows(), a.getCols());
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
			throw runtime_error("dimensions must agree");
		}
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				c(i, j) = a(i, j) + b(i, j);
			}
		}
		return c;
	}

	bool operator==(const Matrix& a, const Matrix& b) {
		if (a.getCols() != b.getCols() || a.getRows() != b.getRows()) {
            return false;
        }
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                if (a(i,j) != b(i,j)) {
					if (abs(a(i,j) - b(i,j)) < 0.00001) {
                    	return false;
                	}
					return false;
				}
            }
        }
        return true;
	}


	bool operator!=(const Matrix& a, const Matrix& b) {
		return !(a == b);
	}


	ostream& operator<<(ostream& os, const Matrix& a) {
		for (int i = 0; i < a.getRows(); i++) {
			for (int j = 0; j < a.getCols(); j++) {
				os << setw(10) << a(i, j) << " ";
			}
			os << endl;
		}
		return os;
	}

	Matrix operator*(const Matrix& a, const Matrix& b) {
		

		if (a.getRows() != b.getCols() && a.getCols() != b.getRows()) {
			throw runtime_error("dimensions must agree");
		}

		Matrix c(a.getRows(), b.getCols());
		for (int i = 0; i < a.getRows(); i++) {
			for (int k = 0; k < b.getCols(); k++) {
				c(i, k) = 0;
				for (int j = 0; j < a.getCols(); j++) {
					c(i, k) += a(i, j) * b(j, k);
				}
			}
		}
		return c;
	}
}