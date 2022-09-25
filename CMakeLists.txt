cmake_minimum_required(VERSION 3.22)
project(data_structure_lecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        data_structure_lecture src/main.cpp
        src/algorithm/game_scores/GameEntry.h src/algorithm/game_scores/GameEntry.cpp src/algorithm/game_scores/Scores.cpp src/algorithm/game_scores/Scores.h src/exception/IndexOutOfBounds.h src/algorithm/game_scores/GameScoresTest.h
        src/algorithm/insertion_sort/InsertionSortTest.h src/algorithm/insertion_sort/SortableArray.cpp src/algorithm/insertion_sort/SortableArray.h
        src/linked_list/singly_linked_list/SinglyLinkedListTest.h src/linked_list/singly_linked_list/SLinkedList.h src/linked_list/singly_linked_list/SNode.h
        src/linked_list/doubly_linked_list/DNode.h src/linked_list/doubly_linked_list/DLinkedList.cpp src/linked_list/doubly_linked_list/DLinkedList.h src/linked_list/doubly_linked_list/DoublyLinkedListTest.h src/linked_list/doubly_linked_list/Dnode.cpp
        src/linked_list/circularly_linked_list/CNode.cpp src/linked_list/circularly_linked_list/CNode.h src/linked_list/circularly_linked_list/CircleList.cpp src/linked_list/circularly_linked_list/CircleList.h src/linked_list/circularly_linked_list/CircularlyLinkedListTest.h
        src/exception/StackEmpty.h src/exception/StackFull.h
        src/stack/array_stack/ArrayStackTest.h src/stack/array_stack/ArrayStack.h
        src/stack/linked_stack/LinkedStack.cpp src/stack/linked_stack/LinkedStack.h src/stack/linked_stack/LinkedStackTest.h
        src/queue/linked_queue/LinkedQueue.cpp src/queue/linked_queue/LinkedQueue.h src/exception/QueueEmpty.h src/queue/linked_queue/LinkedQueueTest.h
        src/algorithm/ruler_drawer/RulerDrawer.cpp src/algorithm/ruler_drawer/RulerDrawer.h src/algorithm/ruler_drawer/RulerDrawerTest.h
        src/list/array_vector/ArrayVector.cpp src/list/array_vector/ArrayVector.h src/list/array_vector/ArrayVectorTest.h
        src/list/node_list/NodeList.cpp src/list/node_list/NodeList.h src/list/node_list/Node.cpp src/list/node_list/Node.h src/list/node_list/Iterator.cpp src/list/node_list/NodeListTest.h
)

