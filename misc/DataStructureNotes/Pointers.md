# Pointers

## Introduction to pointers in C/C++

A Pointer in C language is a variable which holds the address of another variable of same data type.

Pointers are used to access memory and manipulate the address.



## [Working with pointers](https://www.youtube.com/watch?v=X1DcpcgSUXw&index=2&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)

Need to initialize the pointer to print the value in C but works fine in C++:

```c++
#include <iostream>
using namespace std;

int main(){
    int a;
    int* p;
    cout<<p<<endl;
}
```

> ```
> naman@Xnub2:~$ g++ test.cpp
> naman@Xnub2:~$ ./a.out
> 0
> ```

Correct implementation

```c++
#include <iostream>
using namespace std;

int main(){
    
    // variable declaraion 
    int a;
    int* p;

    // variable initialization
    a = 10;
    p = &a;

    // cheching inititalized values
    cout<<"a: "<<a<<endl;
    cout<<"p: "<<p<<endl;
    // checking de-referenced value
    cout<<"*p: "<<*p<<endl;
    // checking address of the variable
    cout<<"&a: "<<&a<<endl;
}
```

> ```
> naman@Xnub2:~$ g++ test.cpp
> naman@Xnub2:~$ ./a.out
> a: 10
> p: 0x7ffd23a2138c
> *p: 10
> &a: 0x7ffd23a2138c
> ```



Another example

```c++
#include <iostream>
using namespace std;

int main(){

    // variable declaraion
    int a;
    int* p;

    // variable initialization
    a = 10;
    p = &a;

    // cheching inititalized values
    cout<<"Address of a: "<<p<<endl;
    // checking de-referenced value
    cout<<"Value of a: "<<*p<<endl;

    int b = 20;
    *p = b;

    // will address of p changes
    cout<<"Address of a: "<<p<<endl;
    cout<<"Value of a: "<<*p<<endl;

}
```

> ```
> naman@Xnub2:~$ g++ test.cpp
> naman@Xnub2:~$ ./a.out
> Address of a: 0x7ffe2b99e238
> Value of a: 10
> Address of a: 0x7ffe2b99e238
> Value of a: 20
> ```



## [Pointer types, pointer arithmetic, void pointers](https://www.youtube.com/watch?v=JTttg85xsbo&index=3&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)

TODO



## [Pointers to Pointers in C/C++](https://www.youtube.com/watch?v=d3kd5KbGB48&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=4)

```c++
#include <iostream>
using namespace std;

int main(){

    int x = 5;
    int* p =&x;
    *p = 6;
    int** q = &p;
    int*** r = &q;

    cout<<*p<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;
    cout<<*r<<endl;
    cout<<**r<<endl;
    cout<<***r<<endl;

    ***r = 10;
    cout<<x<<endl;

    **q = *p + 2;
    cout<<x<<endl;
}
```

> ```
> naman@Xnub2:~$ g++ test.cpp
> naman@Xnub2:~$ ./a.out
> 6
> 0x7ffff2753bfc
> 6
> 0x7ffff2753c00
> 0x7ffff2753bfc
> 6
> 10
> 12
> ```



## [Pointers as function arguments - call by reference](https://www.youtube.com/watch?v=LW8Rfh6TzGg&index=5&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)

TODO



## [Pointers and arrays](https://www.youtube.com/watch?v=ASVB8KAFypk&index=6&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)





