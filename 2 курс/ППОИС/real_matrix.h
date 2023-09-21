#ifndef REAL_MATRIX_H
#define REAL_MATRIX_H

#include <iostream>
#include <fstream>

class real_matrix {
public:
    int rows;
    int cols;
    double **content;

    real_matrix();
    real_matrix(int _rows, int _cols);
    real_matrix(const char* file_name);
    real_matrix(const real_matrix& other);
    ~real_matrix();
    real_matrix& operator++();
    real_matrix operator++(int);
    real_matrix& operator--();
    real_matrix operator--(int);
    int get_rows() const;
    int get_cols() const;   
    double get_element(int _i, int _j) const;
    friend std::ostream& operator<<(std::ostream& os, const real_matrix& rm);
    bool quad_check();
    bool diagonal_check();
    bool zero_check();
    bool identity_check();
    bool symmetrical_check();
    bool uptriang_check();
    bool lowtriang_check();
    void determine_type();
    void transponse();
    void change_form(int _new_rows, int _new_cols);
    real_matrix sub_matrix(int _new_rows, int _new_cols);

};

#endif
