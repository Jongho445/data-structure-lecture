cmake_minimum_required(VERSION 3.22)
project(data_structure_lecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        data_structure_lecture src/test/test_run.cpp
        src/main/algorithm/game_scores/GameEntry.h src/main/algorithm/game_scores/GameEntry.cpp src/main/algorithm/game_scores/Scores.cpp src/main/algorithm/game_scores/Scores.h src/main/exception/IndexOutOfBounds.h src/test/algorithm/GameScoresTest.h
        src/test/algorithm/InsertionSortTest.h src/main/algorithm/insertion_sort/SortableArray.cpp src/main/algorithm/insertion_sort/SortableArray.h
        src/test/linked_list/SinglyLinkedListTest.h src/main/linked_list/SLinkedList.h
        src/main/linked_list/node/DoubleNode.h src/main/linked_list/DLinkedList.h src/test/linked_list/DoublyLinkedListTest.h
        src/main/linked_list/node/SingleNode.h src/main/linked_list/CircleList.h src/test/linked_list/CircularlyLinkedListTest.h
        src/main/exception/StackEmpty.h src/main/exception/StackFull.h
        src/test/stack/ArrayStackTest.h src/main/stack/ArrayStack.h
        src/main/stack/LinkedStack.h src/test/stack/LinkedStackTest.h
        src/main/queue/LinkedQueue.h src/main/exception/QueueEmpty.h src/test/queue/LinkedQueueTest.h
        src/main/algorithm/ruler_drawer/RulerDrawer.cpp src/main/algorithm/ruler_drawer/RulerDrawer.h src/test/algorithm/RulerDrawerTest.h
        src/main/adt/array_vector/ArrayVector.h src/test/adt/ArrayVectorTest.h
        src/main/adt/node_list/NodeList.h src/test/adt/NodeListTest.h src/main/adt/node_list/Iterator.h
        src/main/queue/LinkedDeque.h src/test/queue/LinkedDequeTest.h src/main/exception/DequeEmpty.h
        src/main/stack/DequeStack.h src/test/stack/DequeStackTest.h
        src/main/queue/ArrayQueue.h src/main/exception/QueueFull.h src/test/queue/ArrayQueueTest.h
        src/main/tree/general/GeneralTree.h src/test/tree/GeneralTreeTest.h src/main/tree/general/GeneralPosition.h src/main/tree/general/GeneralTreeHelper.h src/main/tree/general/GeneralNode.h
        src/main/tree/binary/LinkedBinaryTree.h src/main/tree/binary/BinaryNode.h src/main/tree/binary/BinaryPosition.h src/test/tree/BinaryTreeTest.h src/main/tree/Traversal.h
)

