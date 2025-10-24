1	Viết 1 dòng code để bật bit thứ n của x.
Dùng toán tử OR (|): x |= (1 << n);
2	Viết 1 dòng code để tắt bit thứ n của x.
x &= ~(1 << n);
3	Viết 1 dòng code để đảo bit thứ n của x.
x ^= (1<<n);
4	Viết 1 dòng code để kiểm tra bit thứ n có bật không.
 if (x&(1<<n)) {return 1;} else return 0;
5	Viết 1 dòng code để hoán đổi 2 số a và b không dùng biến tạm.
a^=b; b^=a; a^=b;
6	Viết 1 dòng code để kiểm tra n có phải lũy thừa của 2 không.
if (x&(x-1) == 0) && (x >0) return 1; else return 0;
7	Viết 1 dòng code để kiểm tra n là chẵn hay lẻ.
x%2 == 0 hoặc  ( (x&1) == 0)
8	Viết 1 dòng code để lấy bù 2 (two’s complement) của n.
(~x)+1
9	Viết 1 dòng code để kiểm tra hai số a, b có bằng nhau không mà không dùng ==.
if (a^b) return 0; else return 1;
10	Viết 1 dòng code để tìm vị trí MSB (bit có trọng số lớn nhất).
(int)floor(log2(n))
hoặc:
(sizeof(n) * 8 - 1) - __builtin_clz(n)
11	Viết 1 dòng code để tìm vị trí LSB (bit có trọng số nhỏ nhất).
x & (-x);
12	Viết 1 dòng code để tắt bit 1 ở ngoài cùng bên phải của n.
Tắt bit phải nhất: x = x & (x - 1);
13	Viết 1 dòng code để cô lập bit 1 ở ngoài cùng bên phải của n.
Cô lập bit phải nhất: x & (-x);
14	Viết 1 dòng code để kiểm tra n có phải bội của 8 không.
Kiểm tra nếu n % 8 == 0 hoặc (n & 0x7) == 0;
	Chương trình sau có hoạt động không? Nếu không, vấn đề là gì?
int month = 5;
if (month = 1) {
    printf("January");
} else {
    printf("Not January");
}
code vẫn hoạt động nhưng sai kết quả, do ở điều kiện if, phép month = 1 là phép gán, nếu để như vậy sẽ cho ra kết quả khác không và if sẽ nhảy vào print ra January

	Viết lại hàm strcpy
void strcpy(char *des, const char *src) {
    while (*src) {
        *des++ = *src++;
    }
    *des = '\0';
}

	Chương trình sau sẽ in ra gì?
unsigned char c;
for (c = 0; c < 999; c++) {
    printf("%d ", c);
}
Range của unsigned char là 0 đến 255 do đây là kiểu dữ liệu 8 bit, khi đếm đến 255, vòng lặp tự reset về 0, điều này làm cho điều kiện của vòng lặp luôn đúng và dẫn đến vòng lặp vô hạn.
	Hàm sau làm gì? Có vấn đề gì không?
int divide(int a, int b)
{
    return b / a;
}
vì a và b đang để số nguyên, nên phép chia b/a sẽ là phần nguyên của phép chia này.

	Chương trình sau in ra gì?	
int i = 10;
while (i) {
    printf("%d", --i);
}
printf("\n");
In ra từ 9 đến 0

	Chương trình sau sẽ in ra gì?
unsigned int x;
for (x = 10; x >= 0; x--) {
    printf("%u ", x);
}
từ 10 xuống 0 và 0. Do x là unsigned int, nó không thể trở thành -1. Thay vào đó, nó quay vòng về giá trị lớn nhất mà unsigned int có thể giữ được (ví dụ: 4,294,967,295 trên hệ thống 32-bit, hoặc 65,535 trên hệ thống 16-bit).

	Có vấn đề gì với hàm sau?
unsigned char Add(unsigned char a, unsigned char b) {
    return (a + b);
}
unsigned char có range từ 0 đến 255, nếu nếu add quá 255 sẽ tự động reset về 0 và tính tiếp.

	Có vấn đề gì với hàm sau?
15	Đoạn mã sau có vấn đề gì trong đoạn mã sau không?	
void myfunction(char *q) {
    memcpy(q, "hello", 5); 
}

int main(void) {
    char *p;
    myfunction(p);
    return 0;
}
Có 2 vấn đề:
1. memcpy chỉ copy 5 kí tự, vừa đủ cho “hello”, nên q sẽ không có ‘\0’ ở cuối, dẫn đến khi truy cập vào biến q, chương trình sẽ đọc vượt quá vùng nhớ cấp phát
2. trong mani, pointer p chưa được khởi tạo, nên không trỏ đến một vùng nhớ hợp lệ, khi gắn p vào myfuction, đây là hành vi không xác định, do cố gắng ghi vào vùng nhớ không thuộc sở hữu của chương trình -> kết thúc chương trình với lỗi segmentation fault
16	Hàm hoạt động ra sao? Các biến được cấp phát ở đâu?	
int a;
char *b;
const char c[20] = "I am a string";

void func(char d, int c_param, char *f) {
    int g = 0;
    static int h = 2;
    char *i = NULL;
    i = (char *)malloc(20);
    if (i != NULL) {
        free(i);
    }
}
.bss: a, b;
.data: c, h;
Heap: i
stack: d, g, i

Khi hàm được gọi, các biến cục bộ và tham số được lưu vào stack. i là con trỏ được lưu ở stack và trỏ đến một vùng nhớ trên heap. Khi hàm gọi xong thì giải phóng khỏi stack.

17	a và b được cấp phát và lưu trữ ở đâu?
void main(void) {
    char a[4] = "foo";
    char *b = "bar";
}
a và b được lưu trên stack. còn chuỗi “bar\0” là một chuỗi hằng nên được lưu ở .data. nghĩa là biến b nằm trên stack đang trỏ đến một địa chỉ trong vùng nhớ .data

18	Đoạn mã sau có vấn đề gì không? Với RAM = 2000 byte?
void myfunction() {
    char *q;
    for (int i = 0; i < 1000; i++) {
        q = (char *)malloc(8);
        if (q != NULL) {
            memcpy(q, "hello", 6);
        }
    }
}
Chương trình đang bị MEMORY LEAK, mặc dù sẽ không sập (do có if (q != NULL)), nhưng nó sẽ thất bại trong việc sao chép "hello" sau ~250 vòng lặp đầu tiên , mỗi vòng 8 byte và sẽ làm rò rỉ toàn bộ 2000 byte RAM.
19	Đoạn mã sau có vấn đề gì không? Làm sao để in ra "hello"?
void myfunction(char *q) {
    q = (char *)malloc(8);
    if (q) {
        memcpy(q, "hello", 6);
    }
}

void main(void) {
    char *p = NULL;
    myfunction(p);
}
Code trên bị memory leak do không dùng free() sau khi đã dùng xong và kết thúc hàm. vấn đề là con trỏ p là NULL, khi gọi hàm thì biến cục bộ là con trỏ q nếu cấp phát thành công thì vẫn có thể trỏ đến địa chỉ mang giá trị “hello” trên Heap. Tuy nhiên, hết hàm thì q được giải phóng, trong khi con trỏ p vẫn trỏ đến null, nên không thể nào dùng printf cho p được.
Dùng con trỏ cấp 2 (char **)
truyền vào địa chỉ của con trỏ p (tức là &p), để hàm myfunction có thể sửa đổi nó.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nhận vào một con trỏ trỏ đến con trỏ (char**)
void myfunction(char **q_ptr) {
    // Sửa đổi con trỏ gốc bằng cách dùng *q_ptr
    *q_ptr = (char *)malloc(8); 
    if (*q_ptr) { // Kiểm tra xem con trỏ gốc có NULL không
        memcpy(*q_ptr, "hello", 6); // "hello" + '\0' = 6 bytes
    }
}

int main(void) {
    char *p = NULL;
    myfunction(&p); // Truyền địa chỉ của p

    if (p) {
        printf("%s\n", p); // Bây giờ p không còn là NULL
        free(p); // Sửa lỗi memory leak
    }
    return 0;
}
20	Các biến sau được lưu ở đâu?
int a = 5;
int d;
char b[6] = "hello";
const int c = 4;

void myfunction(void)
{
    static int g = 5;
    const int h = 6;
    char i;
}
.bss: d;
.data: a, b, c, g
heap:
stack: h, i
21	Đoạn mã sau có vấn đề gì không?
void main(void) {
    char array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    int *p = (int *)array;
    p++;
    p++;
    printf("Value at p: 0x%x\n", *p);
}
Về vấn đề alignment: Do array là kiểu char, trong khi p là con trỏ int, nên chưa có gì chắc chắn là array[0] nằm ở địa chỉ chia hết cho 4 byte.
Về vấn đề con trỏ: Do con trỏ p kiểu int, nên p++ nghĩa là sẽ tăng đến 4 byte tiếp theo chứ không phải truy cập phần tử tiếp theo của array.
Vấn đề Strict Aliasing: Bạn đang truy cập cùng một vùng nhớ (array) thông qua hai kiểu con trỏ khác nhau (char* và int*). Đây là vi phạm quy tắc "strict aliasing" của C. Trình biên dịch có quyền giả định rằng hai con trỏ thuộc hai kiểu khác nhau sẽ không bao giờ trỏ vào cùng một chỗ, và nó sẽ tối ưu hóa mã dựa trên giả định đó. Điều này có thể dẫn đến kết quả hoàn toàn sai lầm và không thể dự đoán trước.
22	Có vấn đề gì với hàm copy sau?
int copy(char *scr, char *dst, unsigned int size) {
    char *s1;
    while (size--) {
        *s1++ = *scr++;
        *dst++ = *s1;
    }
    return 0;
}
Do s1 không được khai báo nên đang trỏ tới một địa chỉ rác nằm ngoài phạm vi truy cập của chương trình -> Segmentation fault
Cho dù s1 có trỏ đến một vùng nhớ hợp lệ, Code trên sai logic, trong vòng lặp while, dst đang nhận byte tiếp theo của s1, do trước đó đã có *s1++, điều này sai logic vì ta đang muốn copy từng phần tử theo đúng thứ tự.
Vì vậy không cần s1, mà chúng ta làm như sau:
int copy(char *scr, char *dst, unsigned int size) {
    while (size--) {
        *dst++ = *scr++; 
    }
    return 0;
}

23	Đoạn mã sau có vấn đề gì không?
void func(void) {
    char *p = malloc(10);
    strcpy(p, "Embedded");
}
Code trên không free() nên sẽ bị memory leak. Tiếp theo là chưa kiểm tra xem con trỏ p có đang bị NULL không, nếu bị NULL thì khi copy sẽ cố gắng ghi dữ liệu vào địa chỉ NULL gây segmentation fault.
24	Đoạn mã sau có hợp lệ không?
void test(void) {
    char *str = "Hello";
    str[0] = 'h';
}
code này sẽ bị lỗi, do str là con trỏ kiểu char, và Hello là một string literal nên sẽ được lưu ở .rodata, nên sẽ bị lỗi Segmentation Fault (hoặc Access Violation).
25	Các biến a, b, c, d được lưu ở đâu trong bộ nhớ?
int a = 10;
const int b = 5;
static int c = 3;
int func(void) {
    int d = 2;
    return a + b + c + d;
}
.bss:
.data: a, c
.rodata: b
heap:
stack: d
26	Đoạn mã sau có vấn đề gì?
void recursion(int x) {
    int a[100];
    recursion(x + 1);
}
Đây là đệ quy vô hạn gây ra lỗi stack overflow
27	Đoạn mã sau có in ra đúng giá trị ban đầu không? Tại sao?
int main(void) {
    int a = 0x12345678;
    char *p = (char *)&a;
    p[0] = 0xAA;
    printf("a = 0x%x\n", a);
}
Lệnh p[0] = 0xAA ghi đè vào byte đầu tiên của a, vì một phần của a bị thay đổi nên toàn bộ giá trị của a sẽ bị thay đổi
28	Đoạn mã sau có vấn đề gì?
char *getString(void) {
    char str[] = "hello";
    return str;
}
int main(void) {
    char *s = getString();
    printf("%s\n", s);
}
Do getString trả về con trỏ str, tuy nhiên khi gọi hàm xong thì con trỏ str được giải phóng, điều này có nghĩa là con trỏ s đang nhận một địa chỉ rác từ con trỏ str và khi printf sẽ gây ra segmentation fault.
29	"1. Kết quả in ra là gì?
2. Nếu bỏ từ khóa static, kết quả có khác không?
3. Biến count được lưu ở vùng nhớ nào?"
void counter(void) {
    static int count = 0;
    count++;
    printf("%d ", count);
}

int main(void) {
    for (int i = 0; i < 3; i++)
        counter();
    return 0;
}
1. Kết quả in ra là 123
2. Có khác, nếu bỏ thì sẽ ra 111
3. .data
30	"1. Code này có biên dịch được không?
2. Nếu không, compiler báo lỗi gì? Tại sao?"
int main(void) {
    register int x = 5;
    printf("%d\n", x);
    printf("%p\n", &x);
    return 0;
}
1. Không
2. Do biến x sẽ được lưu trên một thanh ghi của CPU, nên sẽ không có địa chỉ trên RAM -> sẽ không dùng &x được -> Lỗi error: address of register variable 'x' requested
31	sizeof(struct ab) và sizeof(struct ba) là bao nhiêu?
	
struct
{
    int a;
    char b;
} ab;

#pragma pack(push, 1)
struct
{
    char a;
    int b;
} ba;
#pragma pack(pop)
ab là 8 byte, ba là 5 byte 
32	sizeof(mystruct) sẽ in ra gì?
typedef struct {
    char x;
    int y;
} mystruct;
sẽ in ra 8 byte
33	sizeof(struct A) là bao nhiêu trên hệ thống 32-bit? 	
struct A {
    char a;
    int b;
    short c;
};
sẽ là 12 byte.
34	Ảnh hưởng của #pragma pack(1) là gì? Kết quả sizeof(struct B) là bao nhiêu trên hệ thống 32-bit?
#pragma pack(push, 1)
struct B {
    char a;
    int b;
    short c;
};
#pragma pack(pop)
Ảnh hưởng là bây giờ sẽ không còn padding nữa
sizeof(B) = 7 byte.
35	Tính sizeof(struct Outer) trên hệ thống 32-bit.
 	
struct Inner {
    char c;
    int d;
};

struct Outer {
    int a;
    struct Inner in;
    char e[3];
};
sizeof(struct Outer) sẽ là 16 byte (do padding vẫn theo thành viên lớn nhất của struct là int d)

36	Trong đoạn mã sau, ab.b có giá trị là bao nhiêu?	
union data {
    int a;
    char b;
} ab;

ab.a = 64;
ab.a = 2500; // 0x09C4
Hệ thống Little-Endian (phổ biến): Lưu byte có trọng số thấp (Least Significant Byte) trước. Bộ nhớ 4 byte sẽ là: [C4] [09] [00] [00] -> char đọc byte đầu tiên là C4

Hệ thống Big-Endian: Lưu byte có trọng số cao (Most Significant Byte) trước. Bộ nhớ 4 byte sẽ là: [00] [00] [09] [C4] -> char  đọc byte đầu tiên là 00

37	sizeof(struct Test) là bao nhiêu trên hệ thống 32-bit?	
union Data {
    int i;
    char c[4];
};

struct Test {
    char flag;
    union Data data;
};
Kết quả là 8 byte
38	Kết quả khác nhau như thế nào giữa little-endian và big-endian?	
union U {
    int val;
    char byte[4];
};

int main(void) {
    union U u;
    u.val = 0x12345678;
    printf("%x %x %x %x\n", u.byte[0], u.byte[1], u.byte[2], u.byte[3]);
}
little endian sẽ là 78 56 34 12
big endian sẽ là 12 34 56 78
39	sizeof(struct Flags) là bao nhiêu?
struct Flags {
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 4;
};
Kết quả là 4 byte
40	"1. Giá trị flag, mode, value sẽ in ra bao nhiêu (giả sử hệ thống little-endian)?
2. Tại sao giá trị thay đổi khi chạy trên big-endian?
3. Giải thích cách compiler ánh xạ bit field vào raw."
union Data {
    struct {
        unsigned int flag  : 3;
        unsigned int mode  : 5;
        unsigned int value : 8;
    } info;
    unsigned short raw;
};

int main(void) {
    union Data d;
    d.raw = 0xABCD;
    printf("flag=%u, mode=%u, value=%u\n", d.info.flag, d.info.mode, d.info.value);
}
1. byte trong little endian sẽ là [CD] [AB] = [11001101] [10101011]
-> flag [101]; mode [11001]; value [10101011]
2. Khi big endian thì các byte có trọng số lớn hơn sẽ xếp ở đầu -> thay đổi
3. d.raw sẽ được lưu là [CD] [AB] = [11001101] [10101011]

41	"1. sizeof(struct Packet) là bao nhiêu trên 32-bit?
2. Giải thích tại sao sizeof không phải luôn bằng 2?
3. Nếu ta gán data.raw = 0xAB, giá trị của id, type, err lần lượt là gì?"
struct Packet {
    unsigned char header;
    union {
        struct {
            unsigned int id   : 4;
            unsigned int type : 3;
            unsigned int err  : 1;
        } bits;
        unsigned char raw;
    } data;
};
1. 8 byte
2.  vì union có kiểu int là 4 byte nên phải align theo 4 byte -> union chiếm 4 byte. header cũng phải align theo 4 byte -> 8 byte
3. 0xAB= 10101011
Nếu Little Endian: id 1011; type 010; err 1
Nếu big Endian: id 1010; type: 101; err 1

42	"1. sizeof(union Config) là bao nhiêu?
2. Tại sao cả hai struct đều có cùng vùng nhớ?
3. Nếu gán security.key = 0x7F, giá trị normal.mode có thay đổi không?"
union Config {
    struct {
        unsigned int enable : 1;
        unsigned int speed  : 2;
        unsigned int mode   : 3;
    } normal;

    struct {
        unsigned int secure : 1;
        unsigned int key    : 7;
    } security;
};
1. 4 byte
2. Vì đây là union
3. Có, vì 2 struct chia sẻ một vùng nhớ nên normal.mode sẽ bị thay đổi.
0x7F=0b01111111
Nếu Little Endian -> normal.mode = 111

43	"1. In ra kết quả gì (với little-endian)?
2. Giải thích tại sao việc truy cập ctrl.bits và ctrl.reg lại ảnh hưởng trực tiếp nhau?
3. Nếu muốn MODE chiếm bit 4–5 thay vì 1–2, sửa khai báo thế nào?"
typedef union {
    struct {
        unsigned int EN   : 1;
        unsigned int MODE : 2;
        unsigned int RSV  : 1;
        unsigned int CLK  : 4;
    } bits;
    unsigned char reg;
} CTRL_REG;

int main(void) {
    CTRL_REG ctrl = { .reg = 0xB2 };
    printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK);
}
1. 0xB2=10110010
EN=0, MODE=01, CLK = 1011
2. Vì union nên bits và reg chia sẻ chung một vùng nhớ
3. phải thêm một unsigned int : 3 để chiếm bit 1 2 3 trước ngay trước khi khai báo MODE

44	"1. sizeof(union Frame) là bao nhiêu?
2. Nếu bytes.low = 0xAA và bytes.high = 0xBB, giá trị của info.len, info.type, info.crc là gì?
3. Giải thích tại sao giá trị có thể khác nhau giữa compiler (GCC vs ARMCC)?"	
union Frame {
    struct {
        unsigned short len  : 10;
        unsigned short type : 3;
        unsigned short crc  : 3;
    } info;

    struct {
        unsigned char low;
        unsigned char high;
    } bytes;
};
1. 2 byte
2. AA BB = 10101010 10111011
len: 11 1010 1010
type: 110
crc: 101
3. Vì một bên là little endian, một bên là big endian	
