1.Làm thế nào để bật (set) một bit cụ thể trong một biến?
Dùng toán tử OR (|): x |= (1 << n);
2.Làm thế nào để bật (set) một bit cụ thể trong một biến?
Dùng toán tử OR (|): x |= (1 << n);
3.Làm thế nào để đảo (toggle) một bit cụ thể trong một biến?
Dùng toán tử XOR (^): x ^= (1 << n);
4.Làm thế nào để kiểm tra một bit cụ thể đã được bật hay chưa?
Dùng toán tử AND (&): if (x & (1 << n))...
5.Làm thế nào để hoán đổi hai số mà không cần biến thứ ba?
Dùng XOR swap: a ^= b; b ^= a; a ^= b;
6.Làm thế nào để kiểm tra một số có phải là lũy thừa của 2 hay không?
Số n là lũy thừa của 2 nếu n & (n - 1) == 0;
7.Làm thế nào để đếm số bit 1 trong biểu diễn nhị phân của một số?
Dùng vòng lặp hoặc __builtin_popcount(n);
8.Làm thế nào để kiểm tra một số là chẵn hay lẻ?
Kiểm tra bit 0: if (n & 1) => lẻ; 
Hoặc n %2 == 0
9.Làm thế nào để tìm bù 2 (2’s complement) của một số nhị phân?
Bù 2 = đảo bit (~n) + 1;
10.Làm thế nào để kiểm tra hai số có bằng nhau hay không mà không dùng toán tử so sánh?
Dùng XOR: if ((a ^ b) == 0) => bằng nhau;
11.Làm thế nào để kiểm tra hai số có bằng nhau hay không mà không dùng toán tử so sánh?
Dùng XOR: if ((a ^ b) == 0) => bằng nhau;
12. Làm thế nào để tìm bit có trọng số lớn nhất (Most Significant Bit - MSB)
Tìm MSB bằng log2(n) hoặc vòng lặp dịch bit;

13.Làm thế nào để tìm bit có trọng số nhỏ nhất (Least Significant Bit - LSB)?
Tìm LSB bằng công thức n & (-n);
14.Làm thế nào để tắt bit 1 ở ngoài cùng bên phải?
Tắt bit phải nhất: x = x & (x - 1);
15.Làm thế nào để cô lập bit 1 ở ngoài cùng bên phải?
Cô lập bit phải nhất: x & (-x);
16.Làm thế nào để kiểm tra một số có phải là bội số của 8 hay không?
Kiểm tra nếu n % 8 == 0 hoặc (n & 0x7) == 0;
Ý nghĩa của typedef trong các trường hợp sử dụng là gì?
Dùng để định nghĩa một kiểu dữ liệu mới.

Có vấn đề gì khi so sánh hai giá trị số thực (if(a == b))?
Do bộ nhớ là giới hạn, nên giá trị số thực a và b sẽ được lưu với giá trị xấp xỉ (nghĩa là sai số giữa số chúng ta định nghĩa và giá trị được lưu là rất nhỏ). Chính vì thế khi so sánh giữa 2 giá trị số thực thì có thể kết quả cho ra sẽ không được chính xác. Nên so sánh hiệu của chúng với một giá trị rất nhỏ (epsilon) để đánh giá sai số giữa a và b, nếu sai số rất nhỏ thì khả năng là a và b bằng nhau nhưng do máy tính lưu giá trị số thực làm a và b khi được lưu bị thay đổi.

Macro là gì? Các ứng dụng điển hình là gì?
Macro là đoạn mã được thay thế trước khi biên dịch. Dùng để định nghĩa hằng số, tạo hàm macro

Mảng con trỏ hàm là gì? Viết ví dụ.
Là mảng chứa con trỏ, trỏ đến các hàm
#include <stdio.h>

// Định nghĩa các hàm (Tất cả đều có cùng kiểu: trả về double, nhận vào 2 double)
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int main() {
    double (*operations[4])(double, double);

    operations[0] = add;
    operations[1] = subtract;
    operations[2] = multiply;
    operations[3] = divide;
    
    double num1 = 10;
    double num2 = 5;
    int choice;

    printf("Chọn phép tính (0=cộng, 1=trừ, 2=nhân, 3=chia): ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < 4) {
        double result = operations[choice](num1, num2);
        
        printf("Kết quả: %lf\n", result);
    } else {
        printf("Lựa chọn không hợp lệ!\n");
    }
    return 0;
}

Sự khác biệt giữa const và #define là gì?
const: là biến thật, có kiểu dữ liệu, được cấp phát bộ nhớ.
#define: chỉ là thay thế văn bản, không kiểm tra kiểu.

Hàm __inline__ là gì?
Là gợi ý cho trình biên dịch chèn mã hàm trực tiếp tại nơi gọi, giảm chi phí gọi hàm nhưng có thể làm tăng kích thước mã.

Toán tử & và &&
Toán tử & &cho các điều kiện trong if, while và do-while
Toàn tử & cho thao tác bit

17.Có những phân đoạn vùng nhớ nào?
1. Stack (RAM): Biến local
2. Heap (RAM): Dữ liệu cấp phát động (malloc, alloc, calloc)
3. Initialize data (.data) (RAM): Biến static + global được khởi tạo giá trị khác 0
4. Uinitialize data (.bss) (RAM): Biến static + global không được khởi tạo hoặc khởi tạo bằng 0.
5. Text (.rodata) (ROM): Biến const toàn cục, code intructions

18.Core C Language Topics
Để quản lý dữ liệu hiệu quả, tách biệt dữ liệu tĩnh, động, mã lệnh, và biến tạm thời.
19.Biến toàn cục không khởi tạo nằm ở đâu?
.bss
20.Hai biến global có cùng giá trị khởi tạo 0 và 10 — tại sao chúng không nằm trong cùng một vùng nhớ?
0 lưu ở .bss
10 lưu ở .data
21.Khi chương trình gọi một hàm lồng nhau nhiều lần (đệ quy), vùng nhớ nào bị ảnh hưởng nhiều nhất?
Stack (do tạo nhiều stack frame có thể tràn stack)
22.Tại sao biến const thường được đặt trong vùng .rodata thay vì .data?
Dữ liệu chỉ đọc, không cần ghi — giúp bảo vệ và tiết kiệm RAM.
23.Nếu bạn muốn dữ liệu tồn tại suốt vòng đời chương trình, bạn nên đặt nó ở vùng nhớ nào?
.data hoặc .bss (static và global)
24.Tại sao vùng .bss không chiếm nhiều dung lượng trong file .bin, nhưng lại chiếm RAM khi chạy?
.bss chỉ lưu thông tin kích thước, không chứa dữ liệu thực.
Khi RAM chạy thì thì lúc đấy sẽ tạo ra số các phần tử tương ứng với kích thước được lưu, chính vì thế mà nó chiếm RAM.
25.Điều gì xảy ra với Stack khi hàm kết thúc, nhưng biến static trong hàm đó vẫn được giữ giá trị?
Khi hàm kết thúc thì stack frame của hàm đấy được giải phóng.
Tuy nhiên, các biến static được lưu trong .data không bị giải phóng khi stack pop.
26.Lỗi Memory Leak xảy ra khi nào? Tại sao? Cách debug.
Xảy ra khi vùng nhớ được cấp phát bằng malloc/new nhưng không được free/delete. Dùng Valgrind hoặc AddressSanitizer (ASan)
27.Lỗi Stack Overflow xảy ra khi nào? Tại sao? Cách debug.
Xảy ra khi chương trình sử dụng quá nhiều bộ nhớ stack, thường do đệ quy vô hạn hoặc khai báo mảng lớn trong hàm. Debug bằng gdb (backtrace).
28.Lỗi Segmentation Fault xảy ra khi nào? Tại sao? Cách debug.
Khi truy cập vùng nhớ không hợp lệ :
1.NULL: khi khai báo con trỏ null và cố gắng ghi và đọc dữ liệu tại đấy
2.Truy cập vào Dangling pointer: pointer đã được giải phóng sau khi được free() nhưng lại quên trả con trỏ về NULL.
3.Out of range: khai bảo array có 5 phần tử nhưng truy cập vào phần tử thứ 10 thì sẽ bị.
Dùng gdb để xem backtrace.
29.Lỗi Stack Smashing là gì? Cách compiler phát hiện bằng cơ chế Canary.
Khi tràn vùng stack ghi đè biến return. Compiler bật bảo vệ -fstack-protector.
Cơ chế canary như sau:
30.Lỗi Heap Corruption là gì? Cách phát hiện bằng AddressSanitizer.
Khi ghi đè vùng nhớ cấp phát động. ASan hiển thị block lỗi.
31.Lỗi Dangling Pointer là gì? Tại sao nguy hiểm? Cách khắc phục.
Con trỏ trỏ đến vùng nhớ đã bị giải phóng. Đặt con trỏ về NULL sau khi free.
32.Khi nào nên dùng AddressSanitizer thay vì Valgrind để debug lỗi bộ nhớ?
Khi cần hiệu năng cao hơn, tích hợp vào build (Valgrind chậm hơn).
33.Lỗi Wild Pointer là gì?
Con trỏ không được gán địa chỉ hợp lệ. Cần khởi tạo = NULL.
34.Các lớp lưu trữ (storage classes) là gì?
Storage class specifier quyết định cách mà biến tồn tại, phạm vi sử dụng và thời gian sống trong chương trình C. Trong C có 4 storage class specifier chính: auto/static/extern/register
35.Từ khóa auto dùng để làm gì? Khi nào thì dùng?
auto là một chỉ định lớp lưu trữ (storage-class specifier). Nó dùng để khai báo một biến có thời gian tồn tại tự động (automatic storage duration). Biến "tự động" là biến được tạo ra khi chương trình đi vào một khối lệnh (ví dụ: vào một hàm) và bị hủy khi thoát ra khỏi khối lệnh đó. Đây chính là các biến cục bộ (local variables) được lưu trên Stack.
Tất cả các biến được khai báo bên trong một hàm (biến cục bộ) đều mặc định là auto.
36.Từ khóa static dùng để làm gì? Khi nào thì dùng?
Khi đặt static trước một biến cục bộ, nó sẽ thay đổi vòng đời (lifetime) của biến đó.
- Vòng đời: Thay vì được tạo ra khi vào hàm và bị hủy khi ra khỏi hàm (lưu trên Stack), biến static cục bộ sẽ tồn tại trong suốt vòng đời của chương trình. Nó được lưu trong vùng nhớ Data Segment/BSS.
- Khởi tạo: Nó chỉ được khởi tạo một lần duy nhất – chính là lần đầu tiên chương trình chạy đến dòng khai báo đó. Trong các lần gọi hàm tiếp theo, dòng khởi tạo sẽ được bỏ qua. Nếu không khởi tạo giá trị, nó sẽ có giá trị mặc định là 0.
- Phạm vi (Scope): Phạm vi truy cập của nó vẫn là cục bộ. Chỉ có thể truy cập nó từ bên trong hàm mà nó được khai báo.
Nếu static cho một biến toàn cục, thì:
- Vòng đời: tồn tại trong suốt vòng đời chương trình, được lưu ở bss hoặc .data
- Khởi tạo: chỉ được khởi tạo một ần duy nhất
- Phạm vi: toàn cục, có thể được truy cập từ bất kỳ đâu trong chương trình
37.Từ khóa extern dùng để làm gì? Khi nào thì dùng?
extern là cho phép các tệp mã nguồn khác nhau trong cùng một dự án chia sẻ và truy cập chung một biến toàn cục.
Khi cần dùng một biến hoặc một hàm được định nghĩa ở tệp khác
38.Từ khóa register dùng để làm gì? Khi nào thì dùng?
register đưa ra một gợi ý (hint) cho trình biên dịch rằng một biến cụ thể sẽ được sử dụng rất thường xuyên. Dựa trên gợi ý này, trình biên dịch có thể quyết định lưu trữ biến đó trong một thanh ghi (CPU register) thay vì trong bộ nhớ chính (RAM).
register chỉ có thể được áp dụng cho các biến cục bộ (local variables) trong một hàm và các tham số của hàm. Nó
không thể được áp dụng cho các biến toàn cục (global variables).
39.Từ khóa volatile dùng để làm gì? Khi nào thì dùng?
volatile là một "chỉ thị kiểu" (type qualifier) dùng để báo cho trình biên dịch (compiler) một thông điệp quan trọng: "Giá trị của biến này có thể bị thay đổi bởi các yếu tố nằm ngoài tầm kiểm soát của đoạn mã đang thực thi. Vì vậy, đừng thực hiện bất kỳ tối ưu hóa nào liên quan đến biến này."
-> Ngăn compiler tối ưu hóa, thường dùng với thanh ghi phần cứng;
40.Khác nhau giữa struct và array?
Array chứa các phần tử cùng kiểu; struct chứa các biến khác kiểu.
41.Kích thước struct được tính như thế nào?
Tổng kích thước các thành viên + padding (theo alignment).
42.Căn chỉnh bộ nhớ trong struct hoạt động như thế nào?
Đầu tiên, địa chỉ của struct phải chia hết cho số byte của thành viên có kích thước lớn nhất (ví dụ, int là 4 byte thì địa chỉ phải chia hết cho 4), sau đó xếp lần lượt từng thành viên của struct theo thứ tự. Giả sử int là thành viên có kích thước lớn nhất và địa chỉ bắt đầu từ 0x1000, trong khi sắp xếp các thành viên, nếu đến thành viên nào khi xếp bị vượt quá 4 byte thì thành viên đấy sẽ được chuyển qua địa chỉ chia hết tiếp theo, nghĩa là xếp qua địa chỉ 0x1004, các byte còn trống thì sẽ được gọi là padding.
43.Padding là gì trong struct? Làm sao tránh padding?
a. Là byte trống được chèn để dữ liệu căn hàng theo bộ nhớ (alignment).
b. Dùng #pragma pack(1) hoặc __attribute__((packed))
44.Có thể gán trực tiếp giữa 2 struct cùng kiểu không?
Có thể (copy toàn bộ nội dung byte theo byte).
45.Struct có thể so sánh bằng toán tử == không?
Không trong C (chỉ có thể so sánh từng trường hoặc dùng memcmp()).
46.Struct có thể dùng làm tham số hàm không?
Có, nhưng thường truyền bằng con trỏ để tiết kiệm bộ nhớ.
47.#pragma pack(1) có ý nghĩa gì?
pack  cho phép điều chỉnh giá trị alignment ở cấp độ data-declaretion(khai báo dữ liệu). 
#pragma pack(1) để thông báo cho compiler biết là mức đóng gói là 1 byte.
48.Khi truyền struct vào hàm, có thể bị padding sai khi giao tiếp giữa vi điều khiển khác nhau không?
Có. Cần __attribute__((packed)) hoặc cấu hình #pragma pack.
49.Union là gì?
Kiểu dữ liệu đặc biệt cho phép nhiều thành viên chia sẻ cùng một vùng nhớ.
50.Kích thước của union là bao nhiêu?
Bằng kích thước của thành viên lớn nhất.
51.Union dùng khi nào?
Khi cần tiết kiệm bộ nhớ, ví dụ dữ liệu có thể ở nhiều dạng khác nhau nhưng chỉ dùng một tại một thời điểm.
52.Nếu ghi vào một thành viên union rồi đọc thành viên khác thì sao?
Không xác định (undefined behavior).
53.Có thể khởi tạo nhiều thành viên của union cùng lúc không?
Không, chỉ một thành viên tại một thời điểm.
54.Union có thể chứa struct không?
Có, và ngược lại (struct có thể chứa union).
55.Union thường dùng trong embedded để làm gì?
Dùng để map bit/byte của thanh ghi hoặc giao tiếp protocol.
56.Enum là gì?
Kiểu dữ liệu được đặt tên cho các hằng số nguyên.
57.Mặc định giá trị đầu tiên của enum là gì?
0
58.Enum có thể gán giá trị cụ thể cho phần tử không?
Có
59.Giá trị của phần tử tiếp theo nếu không chỉ định?
Tự động tăng 1 từ giá trị trước
60.Tại sao nên dùng enum thay vì #define?
Giúp dễ debug vì khi dùng #define thì khi biên dịch máy chỉ thay thế tên đấy thành giá trị, còn nếu dùng enum thì khi biên dịch thì vẫn để nguyên tên đấy, nên sẽ dễ debug.
Enum có phạm vi rõ ràng, được trình biên dịch kiểm tra.
61.Enum có thể âm không?
Có, vì enum lưu dưới dạng int signed.
