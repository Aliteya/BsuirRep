
#include "real_matrix.h"

    real_matrix::real_matrix() {
        this->rows = 0;
        this->cols = 0;
        this->content = nullptr;
    }

    real_matrix::real_matrix(int _rows, int _cols) {
        this->rows = _rows;
        this->cols = _cols;
        content = new double*[rows];
        for(int i = 0; i < rows; i++){
            content[i] = new double[cols];
            for(int j = 0; j < cols; j++){
                content[i][j] = 0;
            }
        }
    }

    real_matrix::real_matrix(const char* file_name) {
        std::ifstream inp(file_name);
        if (!inp.is_open()){
            std::cout << "Troubles with opening file";
        return;
        }
        inp >> rows >> cols;
        if (inp.fail()) {
            std::cout << "Error: non-numeric input in file";
            exit(0);
        }
        std::cout << "Rows: " << rows << " | Columns: " << cols << "\n";
        content = new double*[rows];
        for(int i = 0; i < rows; i++){
            content[i] = new double[cols];
            for(int j = 0; j < cols; j++){
                if (inp.fail()) {
                    std::cout << "Error: non-numeric input in file";
                    exit(0);
                }
                inp >> content[i][j];
            }
        }
        inp.close();
    }

    real_matrix::real_matrix(const real_matrix& other) {
        this->rows = other.rows;
        this->cols =  other.cols;
        this->content = new double*[rows];
        for(int i = 0; i < rows; i++){
            content[i] = new double[cols];
            for(int j = 0; j < cols; j++){
                content[i][j] = other.content[i][j];
            }
        }
    }

    real_matrix::~real_matrix() {
        std::cout <<"destructor";
        for(int i = 0; i < rows; i++)
            delete[] content[i];
        delete[] content;
    }

    std::ostream& operator<<(std::ostream& os, const real_matrix& rm) {
        for(int i = 0; i < rm.rows; i++){
            for(int j = 0; j < rm.cols; j++){
                os << rm.content[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    bool real_matrix::quad_check(){
        if (rows == cols) return true;
        return false;
    }
        
        
    bool real_matrix::diagonal_check(){
        if(!quad_check()) return false;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (i != j && content[i][j] != 0)
                    return false;     
            }
        }
        return true; 
    }
        
    bool real_matrix::zero_check(){
        for(int i = 0; i < rows; i++){
           for(int j = 0; j < cols; j++){
                if (content[i][j] != 0)
                    return false;     
            }
        }
        return true;
    }

    bool real_matrix::identity_check(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (content[i][j] != 1)
                    return false;     
            }
        }
        return true;
    }
        
    bool real_matrix::symmetrical_check(){
        if(!quad_check()) return false;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (i != j && content[i][j] != content[j][i])
                    return false;     
            }
        }
        return true;
    }

    bool real_matrix::uptriang_check(){
        if(!quad_check()) return false;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (i >= j && content[i][j] != 0)
                    return false;     
            }
        }
        return true;
    }

    
    bool real_matrix::lowtriang_check(){
        if(!quad_check()) return false;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (i <= j && content[i][j] != 0)
                    return false;     
            }
        }
        return true;
    }

    real_matrix& real_matrix::operator++(){
        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols; j++){
                content[i][j]++;
            }
        }
        return *this;
    } 

    real_matrix real_matrix::operator++(int){
        real_matrix copy_matr = *this;
        operator++();
        return copy_matr;
    }

        //предекремент
    real_matrix& real_matrix::operator--(){
        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols; j++){
                content[i][j]--;
            }
        }
        return *this;
    }

    real_matrix real_matrix::operator--(int){
        real_matrix copy_matr = *this;
        operator--();
        return copy_matr;
    }

    int real_matrix::get_rows() const{
        return this->rows;
    }
    int real_matrix::get_cols() const{
        return this->cols;
    }
        
    double real_matrix::get_element(int _i, int _j) const{
        return this->content[_i][_j];
    }

    void real_matrix::determine_type(){
        if (quad_check()) std :: cout << " Quad ";
        if (diagonal_check()) std :: cout << " Diagonal ";
        if (zero_check()) std :: cout << " Zero ";
        if (identity_check()) std :: cout << " Identity ";
        if (symmetrical_check()) std :: cout << " Symmetrical ";
        if (uptriang_check()) std :: cout << " Upper triangular ";
        if (lowtriang_check()) std :: cout << " Lower triangular ";
    }

    void real_matrix::transponse(){
        int _new_rows = cols;
        int _new_cols = rows;
        double** _new_content = new double*[_new_rows];
        for(int i = 0; i < _new_rows; i++){
            _new_content[i] = new double[_new_cols];
            for(int j = 0; j < _new_cols; j++){
                _new_content[i][j]= this->content[j][i];
            }
        }
        for (int i = 0; i < rows; i++) delete[] content[i];
        delete[] content;
        content = _new_content;
        rows = _new_rows;
        cols = _new_cols;
    }

    void real_matrix::change_form(int _new_rows, int _new_cols){
        double** _new_content = new double*[_new_rows];
        for(int i = 0; i < _new_rows; i++){
            _new_content[i] = new double[_new_cols];
        for(int j = 0; j < _new_cols; j++){
            if (i < rows && j < cols){
                _new_content[i][j] = this->content[i][j]; 
            }
            else{
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

    real_matrix real_matrix::sub_matrix(int _new_rows, int _new_cols){
        if (_new_cols > cols || _new_rows > rows){
            return *this;
        }
        real_matrix changed_matr(_new_rows, _new_cols);
        for(int i = 0; i < _new_rows; i++){
            for(int j = 0; j < _new_cols; j++){
                changed_matr.content[i][j] = this->content[i][j]; 
            }
        }
            
        return changed_matr;
    }