#include<bits/stdc++.h>
#include "matrix.h"
using namespace std;
class squared_matrix : public matrix{
    private:
    #define rep(i, a, b) for(int i = a; i<=b; i++)
    typedef vector<double> vb;
    void invalid_size_noti(){cout << "Invalid size!"; exit(1);}

    public:
    squared_matrix(int n = 0){
        row_() = col_() = n;
        if (row_() == 0 || col_() == 0) return;
        data_().reserve(n*n*sizeof(int));
        data_().resize(n, vb(n,0.0));
    }
    squared_matrix( vector<vb> INPUTdata ){
        row_() = INPUTdata.size(), col_() = (row_()<1)?0:INPUTdata.at(0).size();
        if( row_() != col_() ) invalid_size_noti();
        data_().reserve(row_()*col_()*sizeof(int));
        data_() = INPUTdata;
    }
    double determinant(){
        if( col_() != row_() ) invalid_size_noti();
        if(row_() == 1 && col_() == 1 ) return data_(0,0);
        if(row_() == 2 && col_() == 2){
            return data_(0,0)*data_(1,1) - data_(1,0)*data_(0,1);
        }
        double res = 0;
        for(int j = 0, i = 0; j < col_(); j++){
            vector< vb > sub_data;
            rep(l, 0, row_()-1){
                if(l == i) continue;
                vb tmp_vb;
                rep(c, 0, col_()-1){
                    if(c == j) continue;
                    tmp_vb.push_back( data_(l, c) ); 
                }
                sub_data.push_back(tmp_vb);
            }
            double tmp = data_()[i][j]*pow(-1, i+j)*squared_matrix(sub_data).determinant();
            res += tmp;
        }
        return res;
    }
    //only for squared matrix
    squared_matrix operator!(){
        double det = determinant();
        if(det == 0 || !is_squared_matrix()){
            cout << "This matrix doesn't have inverse matrix!\n";
            return squared_matrix(0);
        }
        squared_matrix res(row_());
        auto M_ = [=](int i, int j){
            vector< vb > sub_data;
            rep(l, 0, row_()-1){
                if(l == i) continue;
                vb sub_row;
                rep(c, 0, col_()-1){
                    if( c == j) continue;
                    sub_row.push_back(data_(l,c));
                }
                sub_data.push_back(sub_row);
            }
            return (double)pow(-1, i+j)*squared_matrix(sub_data).determinant();
        };
        rep(i, 0, row_()-1){
            rep(j, 0, col_()-1){
                res.data_(j, i) = M_(i,j)/(det*1.0);
            }
        }
        return res;
    }
};
istream &operator>>(istream &is, squared_matrix &a){
    cout << "Enter size of matrix [nxn]: \n";
    cout << "n: "; 
    is >> a.row_(); a.col_() = a.row_();
    if (a.row_() == 0) {
        cout << "Invalid size!\n";
        return is;
    }
    a.data_().reserve(a.row_()*a.col_()*sizeof(double));
    a.data_().resize(a.row_(), vector<double>(a.col_(),0.0));
    cout << "Enter matrix [" << a.row_() <<"x"<<a.col_()<<"] :\n";
    for(int i = 0; i < a.row_(); i++){
        for(int j = 0; j < a.col_(); j++){
            is >> a.data_().at(i).at(j);
        }
    }
    return is;
}
