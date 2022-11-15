cmake_minimum_required(VERSION 3.23)
project(ADT_BST_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(ADT_BST_tree main.cpp BST.cpp BST.h test.cpp test.h ForwardIterator.h ReverseIterator.h TreeNode.h menu.cpp menu.h)
