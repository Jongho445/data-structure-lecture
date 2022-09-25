#include "cstdlib"

#include "algorithm/game_scores/GameScoresTest.h"
#include "algorithm/insertion_sort/InsertionSortTest.h"

#include "linked_list/singly_linked_list/SinglyLinkedListTest.h"
#include "linked_list/doubly_linked_list/DoublyLinkedListTest.h"
#include "linked_list/circularly_linked_list/CircularlyLinkedListTest.h"

#include "stack/array_stack/ArrayStackTest.h"
#include "stack/linked_stack/LinkedStackTest.h"
#include "queue/linked_queue/LinkedQueueTest.h"

int main() {
//    GameScoresTest::run();
//    InsertionSortTest::run();

//    SinglyLinkedListTest::run();
    DoublyLinkedListTest::run();
//    CircularlyLinkedListTest::run();

//    ArrayStackTest::run();
//    LinkedStackTest::run();
//    LinkedQueueTest::run();

    return EXIT_SUCCESS;
}
