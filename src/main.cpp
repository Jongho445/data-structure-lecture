#include "cstdlib"

#include "list/array/ArrayTest.h"
#include "sort/insertion_sort/InsertionSortTest.h"
#include "list/singly_linked_list/SinglyLinkedListTest.h"
#include "list/doubly_linked_list/DoublyLinkedListTest.h"
#include "list/circularly_linked_list/CircularlyLinkedListTest.h"

#include "stack/array_stack/ArrayStackTest.h"

int main() {
//    ArrayTest::run();
//    InsertionSortTest::run();
//    SinglyLinkedListTest::run();
    DoublyLinkedListTest::run();
//    CircularlyLinkedListTest::run();

//    ArrayStackTest::run();

    return EXIT_SUCCESS;
}
