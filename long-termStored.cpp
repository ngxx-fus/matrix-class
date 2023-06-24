// class matrix{
//     public:
//     //var
//     int line, col;
//     vector< vector<int> > mt;
//     //method
//     matrix(int l = 0, int c = 0){
//         line = l, col = l;
//         mt.resize(l, vector<int>(l, 0));
//     }
//     void f1_bai4();
//     void resize(){};
//     void set_matrix();
//     void print_matrix();
//     vector<vector<int>> get_matrix();
//     matrix operator* (const matrix b);
//     matrix operator* (int const num);
//     matrix operator= (const matrix b);
//     matrix operator+ (const matrix b);
//     matrix operator- (const matrix b);
// };

// //Nhập vào ma trận
// void matrix::set_matrix(){
//     cout << "Enter line and col of matrix: \n";
//     cin >> line >> col;
//     cout << "Enter matrix " << line << "*" << col <<":\n";
//     mt.resize(line, vector<int>(col));
//     for(int i = 0; i < line; i++){
//         for( int j = 0; j < col; j++){
//             cin>> mt[i][j];
//         }
//     }
// }

// //In ra ma trận
// void matrix::print_matrix(){
//     cout << "Matrix " << line << "*" << col <<":\n";
//     for(int i = 0; i < line; i++){
//         for( int j = 0; j < col; j++){
//             cout << setw(3) << mt[i][j];
//         }
//         cout << endl;
//     }
//     cout << endl;
// };

// //Trả về vector 2 chiều
// vector<vector<int>> matrix::get_matrix(){
//     return mt;
// };

// //Toán tử * : nhân có hướng
// matrix matrix::operator* (const matrix b){
//     if( this->col != b.line){
//         cout << "Cannot multiple!\n";
//         return matrix(0,0);
//     }
//     matrix c(this->line, b.col);
//     for(int i = 0; i < c.line; i++){
//         for(int j = 0; j < c.col; j++){
//             for(int k = 0; k < this->col; k++){
//                 c.mt[i][j] += this->mt[i][k] + b.mt[k][i];
//             }
//         }
//     }
//     return c;
// };

// //Toán tử * : Nhân vô hướng với 1 số
// matrix matrix::operator* (int const num){
//     matrix c(line, col);
//     for(int i = 0; i < c.line; i++){
//         for(int j = 0; j < c.col; j++){
//             for(int k = 0; k < this->col; k++){
//                 c.mt[i][j] = this->mt[i][k]*num;
//             }
//         }
//     }
//     return c;
// };

// //Toán tử = : Gán giá trị của ma trận B cho ma trận này
// matrix matrix:: operator= (const matrix b){
//     line = b.line; 
//     col = b.col;
//     mt = b.mt;
//     return *this;
// };

// //Toán tử cộng, thực hiện phép cộng với ma trận
// matrix matrix:: operator+ (const matrix b){
//     if( col != b.col || line != b.line){
//         cout << "Cannot add!\n";
//         return matrix(0,0);
//     }
//     matrix c(line, b.col);
//     for(int i = 0; i < c.line; i++){
//         for(int j = 0; j < c.col; j++){
//             c.mt[i][j] = mt[i][j] + b.mt[i][j];
//         }
//     }
//     return c;
// }

// //Toán tử cộng, thực hiện phép trừ với ma trận
// matrix matrix:: operator- (const matrix b){
//     if( col != b.col || line != b.line){
//         cout << "Cannot add!\n";
//         return matrix(0,0);
//     }
//     matrix c(line, b.col);
//     for(int i = 0; i < c.line; i++){
//         for(int j = 0; j < c.col; j++){
//             c.mt[i][j] = mt[i][j] - b.mt[i][j];
//         }
//     }
//     return c;
// }

// void matrix::f1_bai4(){
//     //mt[i][j] < 1000;
//     //sàn nguyên tố Eratosthenes
//     vector<bool> isprime(1001, true);
//     isprime[1] = isprime[0] = false;
//     for(int num = 2; num <= 1000; num++){
//         if(!isprime[num]) continue;
//         for(int k = num*num; k <= 1000; k+=num){
//             isprime[k] = false;
//         }
//     }
//     //duyệt hết ma trận
//     cout << "All prime numbers in matrix:\n";
//     for(int i = 0; i < line; i++){
//         for(int j = 0; j < col; j++){
//             if(isprime[ mt[i][j] ]) cout << setw(3) << mt[i][j];
//         }
//     }
//     cout << endl;
// };