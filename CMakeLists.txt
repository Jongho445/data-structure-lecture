cmake_minimum_required(VERSION 3.22)
project(data_structure_lecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        data_structure_lecture src/main.cpp
        src/list/array/GameEntry.h src/list/array/GameEntry.cpp src/list/array/Scores.cpp src/list/array/Scores.h src/exception/IndexOutOfBounds.h src/list/array/ArrayTest.h
        src/sort/insertion_sort/InsertionSortTest.h src/sort/insertion_sort/SortableArray.cpp src/sort/insertion_sort/SortableArray.h
        src/list/singly_linked_list/SinglyLinkedListTest.h src/list/singly_linked_list/SLinkedList.h src/list/singly_linked_list/SNode.h
        src/list/doubly_linked_list/DNode.h src/list/doubly_linked_list/DLinkedList.cpp src/list/doubly_linked_list/DLinkedList.h src/list/doubly_linked_list/DoublyLinkedListTest.h src/list/doubly_linked_list/Dnode.cpp
        src/list/circularly_linked_list/CNode.cpp src/list/circularly_linked_list/CNode.h src/list/circularly_linked_list/CircleList.cpp src/list/circularly_linked_list/CircleList.h src/list/circularly_linked_list/CircularlyLinkedListTest.h
        src/exception/StackEmpty.h src/exception/StackFull.h
        src/stack/array_stack/ArrayStackTest.h src/stack/array_stack/ArrayStack.h
        src/stack/linked_stack/LinkedStack.cpp src/stack/linked_stack/LinkedStack.h src/stack/linked_stack/LinkedStackTest.h
        src/queue/linked_queue/LinkedQueue.cpp src/queue/linked_queue/LinkedQueue.h src/exception/QueueEmpty.h src/queue/linked_queue/LinkedQueueTest.h)

