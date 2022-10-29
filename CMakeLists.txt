cmake_minimum_required(VERSION 3.22)
project(data_structure_lecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        data_structure_lecture src/test/test_run.cpp
        src/main/algorithm/game_scores/GameEntry.h src/main/algorithm/game_scores/GameEntry.cpp src/main/algorithm/game_scores/Scores.cpp src/main/algorithm/game_scores/Scores.h src/main/exception/IndexOutOfBounds.h src/test/algorithm/GameScoresTest.h
        src/test/algorithm/InsertionSortTest.h src/main/algorithm/insertion_sort/SortableArray.cpp src/main/algorithm/insertion_sort/SortableArray.h
        src/test/linked_list/SinglyLinkedListTest.h src/main/linked_list/singly_linked_list/SLinkedList.h src/main/linked_list/singly_linked_list/SNode.h
        src/main/linked_list/doubly_linked_list/DNode.h src/main/linked_list/doubly_linked_list/DLinkedList.cpp src/main/linked_list/doubly_linked_list/DLinkedList.h src/test/linked_list/DoublyLinkedListTest.h src/main/linked_list/doubly_linked_list/Dnode.cpp
        src/main/linked_list/circularly_linked_list/CNode.cpp src/main/linked_list/circularly_linked_list/CNode.h src/main/linked_list/circularly_linked_list/CircleList.cpp src/main/linked_list/circularly_linked_list/CircleList.h src/test/linked_list/CircularlyLinkedListTest.h
        src/main/exception/StackEmpty.h src/main/exception/StackFull.h
        src/test/stack/ArrayStackTest.h src/main/stack/array_stack/ArrayStack.h
        src/main/stack/linked_stack/LinkedStack.cpp src/main/stack/linked_stack/LinkedStack.h src/test/stack/LinkedStackTest.h
        src/main/queue/linked_queue/LinkedQueue.cpp src/main/queue/linked_queue/LinkedQueue.h src/main/exception/QueueEmpty.h src/test/queue/LinkedQueueTest.h
        src/main/algorithm/ruler_drawer/RulerDrawer.cpp src/main/algorithm/ruler_drawer/RulerDrawer.h src/test/algorithm/RulerDrawerTest.h
        src/main/adt/array_vector/ArrayVector.cpp src/main/adt/array_vector/ArrayVector.h src/test/adt/ArrayVectorTest.h
        src/main/adt/node_list/NodeList.cpp src/main/adt/node_list/NodeList.h src/main/adt/node_list/Node.cpp src/main/adt/node_list/Node.h src/main/adt/node_list/Iterator.cpp src/test/adt/NodeListTest.h
        src/main/queue/linked_deque/LinkedDeque.cpp src/main/queue/linked_deque/LinkedDeque.h src/test/queue/LinkedDequeTest.h src/main/exception/DequeEmpty.h
        src/main/stack/deque_stack/DequeStack.cpp src/main/stack/deque_stack/DequeStack.h src/test/stack/DequeStackTest.h
        src/main/queue/array_queue/ArrayQueue.h src/main/exception/QueueFull.h src/test/queue/ArrayQueueTest.h
)

