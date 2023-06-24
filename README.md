Đây là một bài tập nhỏ về hướng đối tượng. Đối tượng chính là ma trận (maxtrix) với các thuộc tính nhập/xuất cộng trừ, nhân.
Có hai class trong bài tập này,  được xây dựng như sau:
    class matrix: 
        - Định nghĩa về một ma trận thường có kích thước n (hàng) x m (cột).
        - Hàm thành viên:
            + Constructor : matrix(int n = 0, int m = 0) hàm cho phép gởi khạo ma trận nxm với giá trị đầu là 0.
            + Contrustor : mtraix(vecotr<vector<double>> vb) cho phép khởi tạo ma trận với mảng hai chiều cho trước.
            + Operator +/-: Cho phép cộng/trừ hai ma trận cùng kích thước,  kết quả trả về là một ma trận.
            + Operator * (int n): cho phép nhân vô hướng với một số.
            + Operator * (matrix o): chép nhân có hướng với một ma trận khác, theo quy tắc như sau: [axb]x[bxc]=[axc]
            + row_() : trả về số dòng
            + col_() : trả về số cột
            + row_(int i) : trả về vector<double> của dòng thứ i trong ma trận
            + col_()(int j) : trả về vector<double> là vector chuyển vị của cột thứ j trong ma trận 
            + dot(vector<double> a, vector<double> b) : trả về tích vô hướng của hai vector.
            + Operator >> : NHập matrix
            + Operator << : xuất matrix
            + is_squared_matrix() : trả về true/false nếu ma trận là ma trận vuông / hoặc không.
    class squared_matrix < thừa kế từ class matrix >:
        - Định nghĩa một ma trận vuông có kích thước nxn.
        - Các hàm thành viên:
            + Các constructor tương tự class matrix.
            + determinant() : trả về định thức của ma trận.
            + operator !() : ma trận nghịch đão.

-----------------------------
Sử dụng lớp kế thừa, nạp chồng hàm...
