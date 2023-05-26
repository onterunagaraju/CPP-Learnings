
#include <iostream>

// Question: what is structural padding and packing in C&C++
// Answers: It is a way to spped up CPU Utilization

//#pragma pack(1) // disables padding  , Padding means adding bytes to data type in the memory

struct Base
{
    /*char a;
    char b;
    int i;
    char c;*/      // return ans as 12

    char a;
    char b;
    char c;
    int i;        // return ans 8
};

// 1 word ia 4 bytes in 32 bit processor
// 1 word is 8 bytes in 64 bit processor

// ----------------------CASE 1:-----------------------
//struct Base
//{
//    char a;
//    char b;
//    int i;        // return ans 4
//};

 /*   |a|b|-|-|i|i|i|i|   // here padding of 2 bytes added , padding added in most possible large data type
     0 1 2 3 4 5 6 7*/



     // ----------------------CASE 2:-----------------------
     //struct Base
     //{
     //    char a;
     //    int i;
     //    char b;
     //            // return ans 12
     //};

     //  |a|-|-|-|i|i|i|i|b|-|-|-|
     //   0 1 2 3 4 5 6 7 8 9 10 11


    // How data gets memory slots
    // 1 Byte ==> can be stored at multiple of 1 memory slot
    // 2 Byte ==> can be stored at multiple of 2 memory slot
    // 4 Byte ==> can be stored at multiple of 4 memory slot
    // 8 Byte ==> can be stored at multiple of 8 memory slot

    // that is the reason why padding is happening , it checks for next possible blocks of memory

struct A
{
    int x;
    double d;  // returns ans as 16 as it divides memory into blocks of 8 bytes as largest type is double. x is stored in first block of 8 bytes
                // in which 4 bytes are used to store x and another 4 bytes are padded(wasted). next 8 bytes used to store d. total 16 bytes.
};

struct B
{
    int y;
    A a;    // Here strcut obj a is of 16 byte size but it didn't divide the memory into blocks of 16 bytes. it checks for large data type in the struct
            // so here large type is double in the struct, so it divides the memory into blocks of 8 bytes. first 8 bytes for integer y and 
            // next 16 bytes for strcut obj a . so the ans is 24.

    /*int y;
    int k;      // this will give 24 as first 8 bytes suffcient for storing y,k and next 16 bytes for a;
    A a;*/

    /*int y;
    A a;        // this will give 32 as memory divides into blocks of 8 bytes. first 8 bytes for y and next 16 for a and next 8 bytes for k
    int k;*/
};

//int main()
//{
//    std::cout << sizeof(Base) << std::endl;
//    std::cout << sizeof(A) << std::endl;
//    std::cout << sizeof(B) << std::endl;
//    return 0;
//}


//// Question : How compilation works internally
//                                                    Editor or IDE (write source code)
//                                                               |
//                                                               |    (.cpp, .h) Source code, header files
//                                                               V
//                                                        Preprocessor 
//                                                               |
//                                                               |    (*.i) Included files, replaced symbols
//                                                               V
//                                                           Compiler 
//                                                               |
//                                                               |     (*.s) Assembly code
//                                                               V
//                                                           Assembler
//                                                               | 
//                                                               |       (*.o) object code
//                                                               V
//                     (static libraries (.lib, .a) --------->Linker
//                                                               |
//                                                               |  (.exe)
//                                                               V
//                     Dynamic libraries (.dll, .so)---------->Loader
//                                                               |
//                                                               |
//                                                               V
//                                                           Operating system
