#include<bits/stdc++.h>
using namespace std;
// //*task: https://stackoverflow.com/questions/2981836/how-can-i-use-cout-myclass

class matrix{
    typedef vector<double> vb;
    /*###*/ private:
    #define rep(i, a, b) for(int i = a; i<=b; i++)
    int /*row_*/ n = 0, /*column*/ m = 0;
    vector< vb > data;
    void invalid_size_noti(){cout << "Invalid size!"; exit(1);}
    /*###*/ public:
    matrix(int row_ = 0, int col_ = 0){
        n = row_, m = col_;
        if (n == 0 || m == 0) return;
        data.reserve(n*m*sizeof(int));
        data.resize(n, vb(m,0.0));
    }
    matrix(vector< vb > INPUTdata){
        n = INPUTdata.size(), m = (n<1)?0:INPUTdata.at(0).size();
        data.reserve(n*m*sizeof(int));
        data = INPUTdata;
    }
    //return a number of columns
    int &col_(){return m;}
    //return a number of rows
    int &row_(){return n;}
    //return data[i][j]
    double &data_(int i, int j){return data.at(i).at(j);}
    //return vector< vector< double > > [nxm] matrix
    vector< vb > &data_(){return data;}
    matrix operator-(){
        matrix tmp;
        tmp.row_() = this->n;
        tmp.col_() = this->m;
        tmp.data_() = this->data;
        for(auto &p:tmp.data_()){
            for(auto &c:p){
                c*=-1;
            }
        }
        return tmp;
    }
    matrix operator-(matrix o){
        matrix tmp(data);
        //checkin 
        if( o.row_() != n || o.col_() != m){
            cout << "Two matrixs have difference size!\n";
            exit(1);
        }
        //minus
        for(int  i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                tmp.data_().at(i).at(j) -= o.data_().at(i).at(j); 
            }
        }
        return tmp;
    }
    matrix operator+(){
        matrix tmp(data);
        return tmp;
    }
    matrix operator+(matrix o){
        matrix tmp(data);
        //checkin 
        if( o.row_() != n || o.col_() != m){
            cout << "Two matrixs have difference size!\n";
            exit(1);
        }
        //minus
        for(int  i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                tmp.data_().at(i).at(j) += o.data_().at(i).at(j); 
            }
        }
        return tmp;
    }
    matrix operator*(int n){
        matrix tmp(data);
        //minus
        for(int  i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                tmp.data_().at(i).at(j) *=n; 
            }
        }
        return tmp;
    }
    //return vector of row ith
    vector< double > row_(int i){
        vector< double > res;
        if( i < 0 || i >= n ) invalid_size_noti();
        rep(j, 0, m-1) res.push_back(data[i][j]);
        return res;
    }
    // return vector of column jth
    vector< double > col_(int j){
        vector< double > res;
        if( j < 0 || j >= m ) invalid_size_noti();
        rep(i, 0, n-1) res.push_back(data[i][j]);
        return res;
    }
    int dot( vb row, vb col){
        int res = 0;
        if(row.size() != col.size()) invalid_size_noti();
        rep(i, 0, row.size()-1) res += row[i]*col[i];
        return res;
    }
    matrix operator*(matrix o){
        if(m != o.row_()) invalid_size_noti();
        matrix res(n, o.col_());
        rep(i, 0, n-1){
            rep(j, 0, o.col_()-1){
                res.data_().at(i).at(j) = dot(this->row_(i), o.col_(j));
            }
        }
        return res;
    }
    matrix operator=(matrix o){
        n = o.row_(); m = col_();
        data = o.data_();
        return *this;
    }

};
ostream &operator<<(ostream &os, matrix &a){
    os << "Matrix [" << a.row_() <<"x"<<a.col_()<<"] :\n";
    for(auto row_:a.data_()){
        for(auto cell:row_){
            os << cell << " ";
        }
        os << '\n';
    }
    return os;
}
istream &operator>>(istream &is, matrix &a){
    cout << "Enter size of matrix [mxn]: \n";
    cout << "m (row) : "; is >> a.row_();
    cout << "m  (column) : "; is >> a.col_();
    if (a.row_() == 0 || a.col_() == 0) {
        cout << "Invalid size!\n";
        return is;
    }
    a.data_().reserve(a.row_()*a.col_()*sizeof(double));
    a.data_().resize(a.row_(), vector<double>(a.col_(),0.0));
    cout << "Enter matrix :\n";
    for(int i = 0; i < a.row_(); i++){
        for(int j = 0; j < a.col_(); j++){
            is >> a.data_().at(i).at(j);
        }
    }
    return is;
}
