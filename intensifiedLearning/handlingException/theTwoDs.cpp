#include <iostream>

// do not throw exceptions in the destructors like ever

/*
 * problem with resource handling
 * void File() {
 *     openFile();
 *     writeFile();
 *     closeFile();
 *
 *     what if writeFile throws an exception? the file is never closed
 *     solution: close the file after the catch block
 * }
 *
 * void doSomething() {
 *     auto* ptr{new Person{"deno", 10, SUPERCOOL};
 *
 *         "assuming an exception is thrown in creation of the Person"
 *         "ptr is never deleted"
 *
 *     delete ptr;
 * }
 *
 * solution:
 *  1) declare the variable outside the try block scope so that the both the try and catch
 *     handlers get access to the pointer
 *  2) second way is to use a RAII compliant class (often called smart pointers)
 *
 *  Exception handling is best used when all of the following are true:
 *  The error being handled is likely to occur only infrequently.
    The error is serious and execution could not continue otherwise.
    The error cannot be handled at the place where it occurs.
    There isn’t a good alternative way to return an error code back to the caller.
*/

int main() {
    return 0;
}

