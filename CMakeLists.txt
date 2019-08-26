cmake_minimum_required(VERSION 3.14)
project(c_codes C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES main.c)

#add_executable(main linear_list/duLinkList.c)
#add_executable(main stack/seq_stack.c)
#add_executable(main queue/seqQueue1.c)
#add_executable(main queue/linkQueue.c)
add_executable(main string/req_string.c)