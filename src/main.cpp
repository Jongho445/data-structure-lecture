#include "cstdlib"

#include "list/array/ArrayTest.h"
#include "sort/insertion_sort/InsertionSortTest.h"
#include "list/singly_linked_list/SinglyLinkedListTest.h"
#include "list/doubly_linked_list/DoublyLinkedListTest.h"
#include "list/circularly_linked_list/CircularlyLinkedListTest.h"

#include "stack/array_stack/ArrayStackTest.h"
#include "stack/linked_stack/LinkedStackTest.h"
#include "queue/linked_queue/LinkedQueueTest.h"

int main() {
//    ArrayTest::run();
//    InsertionSortTest::run();
//    SinglyLinkedListTest::run();
    DoublyLinkedListTest::run();
//    CircularlyLinkedListTest::run();

//    ArrayStackTest::run();
//    LinkedStackTest::run();
//    LinkedQueueTest::run();

    return EXIT_SUCCESS;
}
