**Context:[`Stack.c`](https://github.com/PhoenixAthens/JS-Adventures/blob/main/JS_Prototypes/protoChain.js)**<br>

Q1: What's the difference between declaring a struct like so
```c
typedef struct{
    int top;
    int data[SIZE];
}Stack;
```
and so
```c
struct stack{
    int top;
    int data[SIZE];
};
```
A: In C, the difference between these two declarations lies in the way you can create variables of the struct type.
- `typedef struct {..} Stack;`
This declaration defines a new type called `Stack` using a `typedef`. After this declaration, you can create variables of type `Stack` without using the `struct` keyword:
```c
Stack s1, s2;
```
- `struct stack { .. };`
This declaration defines a structure type named `stack`. To create variables of this type, you need to use the `struct` keyword:
```c
struct stack s1, s2;
```
Both declarations define the same structure layout with an `int` member `top` and an `int` array `data` of size `SIZE`. However, the `typedef` version provides a more convenient way to create variables of the struct type without having to use the `struct` keyword every time.

The `typedef` approach is often preferred because it makes the code more readable and easier to maintain, especially when working with nested or complex struct types. It also helps avoid potential syntax errors when dealing with pointers to structs.

For example, with the `typedef` version, you can declare a pointer to `Stack` like this:
```c
Stack *sp;
```
Without the `typedef`, you would need to write:
```c
struct stack *sp;
```
This can become cumbersome and error-prone, especially when dealing with nested structs or function pointers involving structs.

In summary, while both declarations define the same struct layout, the `typedef` version provides a more concise and convenient way to create variables and pointers of the struct type, improving code readability and maintainability.