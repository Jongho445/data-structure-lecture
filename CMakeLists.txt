cmake_minimum_required(VERSION 3.22)
project(data_structure_lecture)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        data_structure_lecture src/main.cpp
        src/ch3/array/GameEntry.h src/ch3/array/GameEntry.cpp src/ch3/array/Scores.cpp src/ch3/array/Scores.h src/ch3/array/exception/IndexOutOfBounds.cpp src/ch3/array/exception/IndexOutOfBounds.h src/ch3/array/ArrayTest.h
        src/ch3/insertion_sort/InsertionSortTest.h src/ch3/insertion_sort/SortableArray.cpp src/ch3/insertion_sort/SortableArray.h
        src/ch3/singly_linked_list/SinglyLinkedListTest.h src/ch3/singly_linked_list/StringLinkedList.cpp src/ch3/singly_linked_list/StringLinkedList.h src/ch3/singly_linked_list/StringNode.h)

