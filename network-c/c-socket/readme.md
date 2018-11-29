# Lập trình mạng C

## 1. argv và argc


- `argv` và `argc` là cách các đối số dòng lệnh được chuyển tới hàm main() trong C và C++.
- `argc` sẽ là số chuỗi được chỉ định bởi argv. Điều này sẽ (trong thực hành) là một cộng với số
lượng đối số, vì hầu như tất cả các triển khai sẽ thêm tên chương trình vào mảng.
- Các biến được đặt tên là `argc` (đối số đếm) và `argv` (đối số véc tơ) theo quy ước, nhưng chúng
có thể được cung cập bất kỳ mã định danh (id) hợp lệ nào:
  - int main (int num_args, char ** arg_strings) có giá trị như nhau.
- Chúng có thể được xóa bỏ qua hoàn toàn, sinh ra 
  - int main(), nếu bạn không có ý định xử lý các đối số dòng lệnh.


- Xém code dưới đây:

```
$ cat mysort.c
#include <stdio.h>
int main( int argc, char * argv [] ) {
    printf( "argc = %d\n", argc );
    for( int i = 0; i < argc; ++i ) {
        printf( "argv[ %d ] = %s\n", i, argv[ i ] );
    }
}

$ gcc mysort.c -o mysort

$ ./mysort 2 8 9 1 4 5
argc = 7
argv[ 0 ] = ./mysort
argv[ 1 ] = 2
argv[ 2 ] = 8
argv[ 3 ] = 9
argv[ 4 ] = 1
argv[ 5 ] = 4
argv[ 6 ] = 5

```

## 2. Hàm 







c++:
https://gnomezgrave.com/2015/03/03/simple-client-server-chat-program-using-select/

single server, multi-client in c:
https://github.com/codophobia/Multi-Client-Server-Chat
https://www.codegrudge.com/2014/07/tcpip-multiclient-chat-server.html


https://stackoverflow.com/questions/4200172/c-socket-programming-connecting-multiple-clients-to-server-using-select

A typical concurrent server using select.
http://exploreurtalents.blogspot.com/2010/03/typical-concurrent-server-using-select.html
http://forum.codecall.net/topic/64205-concurrent-tcp-server-using-select-api-in-linux-c/
https://therighttutorial.wordpress.com/2014/06/09/multi-client-server-chat-application-using-socket-programming-tcp/
https://www.tenouk.com/Module41.html
https://sites.google.com/site/sonsahn/Home/hoc-c-nha/network-programing-example/server-voi-select-trong-c-1
http://www.linuxhowtos.org/C_C++/socket.htm
