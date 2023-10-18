/*!
    \brief Implementation of the real matrix class
    \author Aliteya
    \version 2.5
    \date September 2023
    \details Contains a default constructor, with specified dimensions and reading a matrix from a file;
     operators ++ and -- for a given matrix; cout thread overload; transposition methods, type definitions
     and selecting a submatrix of a given size.
*/
#include "real_matrix.h"
/*!
  \brief default class constructor 0 rows, 0 columns
*/
real_matrix::real_matrix() {
    this->rows = 0;
    this->cols = 0;
    this->content = nullptr;
}
/*!
  \brief Class constructor with parameters
  \param _rows, _cols Rows, columns.
*/
real_matrix::real_matrix(int _rows, int _cols) {
    this->rows = _rows;
    this->cols = _cols;
    content = new double* [rows];
    for (int i = 0; i < rows; i++) {
        content[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            content[i][j] = 0;
        }
    }
}
/*!
  \brief Class constructor with parameters
  \param filename the file from which the matrix is read
*/
real_matrix::real_matrix(const char* file_name) {
    std::ifstream inp(file_name);
    if (!inp.is_open()) {
        std::cout << "Troubles with opening file";
        return;
    }
    int _rows, _cols;
    inp >> _rows >> _cols;
    if (inp.fail()) {
        std::cout << "Error: non-numeric input in file";
        exit(0);
    }
    this->rows = _rows;
    this->cols = _cols;
    content = new double* [rows];
    for (int i = 0; i < rows; i++) {
        content[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            if (inp.fail()) {
                std::cout << "Error: non-numeric input in file";
                exit(0);
            }
            inp >> content[i][j];
        }
    }
    inp.close();
}
/*!
  \brief Copy constructor
*/
real_matrix::real_matrix(const real_matrix& other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->content = new double* [rows];
    for (int i = 0; i < rows; i++) {
        content[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            content[i][j] = other.content[i][j];
        }
    }
}
/*!
  \brief Class destructor
*/
real_matrix::~real_matrix() {;
    for (int i = 0; i < rows; i++)
        delete[] content[i];
    delete[] content;
}
/*!
  \brief Overloading the stream output operator
  \param os An instance of the ostream class
  \param rm An instance of the class real_matrix
*/
std::ostream& operator<<(std::ostream& os, const real_matrix& rm) {
    for (int i = 0; i < rm.rows; i++) {
        for (int j = 0; j < rm.cols; j++) {
            os << rm.content[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
/*!
    \brief Helper method for checking if a matrix is square
    \return True if yes, False if no
*/
bool real_matrix::quad_check() {
    if (rows == cols) return true;
    return false;
}

/*!
\brief Helper method for checking if a matrix is diagonal
    \return True if yes, False if no
*/
bool real_matrix::diagonal_check() {
    if (!quad_check()) return false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i != j && content[i][j] != 0)
                return false;
        }
    }
    return true;
}
/*!
\brief Helper method for checking if a matrix is zero
    \return True if yes, False if no
*/
bool real_matrix::zero_check() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (content[i][j] != 0)
                return false;
        }
    }
    return true;
}
/*!
\brief Helper method for checking if a matrix is identity
    \return True if yes, False if no
*/
bool real_matrix::identity_check() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (content[i][j] != 1)
                return false;
        }
    }
    return true;
}
/*!
\brief Helper method for checking if a matrix is symmetrical
    \return True if yes, False if no
*/
bool real_matrix::symmetrical_check() {
    if (!quad_check()) return false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i != j && content[i][j] != content[j][i])
                return false;
        }
    }
    return true;
}
/*!
\brief Helper method for checking if a matrix is upper triangle
    \return True if yes, False if no
*/
bool real_matrix::uptriang_check() {
    if (!quad_check()) return false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && content[i][j] != 0)
            
                return false;
        }
    }
    return true;
}

/*!
\brief Helper method for checking if a matrix is lower triangle
    \return True if yes, False if no
*/
bool real_matrix::lowtriang_check() {
    if (!quad_check()) return false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < j && content[i][j] != 0)
                return false;
        }
    }
    return true;
}

/*!
    \brief preincrement operator. Changes content returns option after change
    \return *this is the modified object itself
*/
real_matrix& real_matrix::operator++() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            content[i][j]++;
        }
    }
    return *this;
}
/*!
    \brief post-increment operator. Changes the content returns the option before the change
    \return copy_matr copy of the object before modification
*/
real_matrix real_matrix::operator++(int) {
    real_matrix copy_matr = *this;
    operator++();
    return copy_matr;
}

/*!
    \brief predecrement operator. Changes content returns option after change
    \return *this is the modified object itself
*/
real_matrix& real_matrix::operator--() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            content[i][j]--;
        }
    }
    return *this;
}

/*!
    \brief postdecrement operator. Changes the content returns the option before the change
    \return copy_matr copy of the object before modification
*/
real_matrix real_matrix::operator--(int) {
    real_matrix copy_matr = *this;
    operator--();
    return copy_matr;
}

/*!
    \brief row getter
*/
int real_matrix::get_rows() const {
    return this->rows;
}
/*!
    \brief column getter
*/
int real_matrix::get_cols() const {
    return this->cols;
}
/*!
    \brief element getter
*/
double real_matrix::get_element(int _i, int _j) const {
    return this->content[_i][_j];
}
/*!
    \brief the main method for determining the type of matrix. Calls helper methods and prints the type to the console
*/
void real_matrix::determine_type() {
    if (quad_check()) std::cout << " Quad ";
    if (diagonal_check()) std::cout << " Diagonal ";
    if (zero_check()) std::cout << " Zero ";
    if (identity_check()) std::cout << " Identity ";
    if (symmetrical_check()) std::cout << " Symmetrical ";
    if (uptriang_check()) std::cout << " Upper triangular ";
    if (lowtriang_check()) std::cout << " Lower triangular ";
}

/*!
    \brief matrix transposition method <3
    \warning !!!THE MATRIX ITSELF IS CHANGING!!!
*/
void real_matrix::transponse() {
    int _new_rows = cols;
    int _new_cols = rows;
    double** _new_content = new double* [_new_rows];
    for (int i = 0; i < _new_rows; i++) {
        _new_content[i] = new double[_new_cols];
        for (int j = 0; j < _new_cols; j++) {
            _new_content[i][j] = this->content[j][i];
        }
    }
    for (int i = 0; i < rows; i++) delete[] content[i];
    delete[] content;
    content = _new_content;
    rows = _new_rows;
    cols = _new_cols;
}

/*!
    \brief method for changing the shape of the matrix. If the new matrix is smaller,
    then the original matrix is cut off from the upper left corner to accommodate the new values; if more, then the new rows and columns are filled with zeros. :^)
    \param _new_rows, _new_cols new matrix form
    \warning !!!THE MATRIX ITSELF IS CHANGING!!!
*/
void real_matrix::change_form(int _new_rows, int _new_cols) {
    double** _new_content = new double* [_new_rows];
    for (int i = 0; i < _new_rows; i++) {
        _new_content[i] = new double[_new_cols];
        for (int j = 0; j < _new_cols; j++) {
            if (i < rows && j < cols) {
                _new_content[i][j] = this->content[i][j];
            }
            else {
                _new_content[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++) delete[] content[i];
    delete[] content;
    content = _new_content;
    rows = _new_rows;
    cols = _new_cols;
}

/*!
    \brief method for extracting a submatrix. If the new matrix is smaller,
    then the original matrix is cut off from the upper left corner to accommodate the new values, if >= then I return the original matrix.
    \param _new_rows, _new_cols new matrix form
    \return changed_matr submatrix cut from a copy of the original
    \warning !!!THE COPY OF THE MATRIX IS CHANGING!!!
*/
real_matrix real_matrix::sub_matrix(int _new_rows, int _new_cols) {
    if (_new_cols > cols || _new_rows > rows) {
        return *this;
    }
    real_matrix changed_matr(_new_rows, _new_cols);
    for (int i = 0; i < _new_rows; i++) {
        for (int j = 0; j < _new_cols; j++) {
            changed_matr.content[i][j] = this->content[i][j];
        }
    }

    return changed_matr;
}
