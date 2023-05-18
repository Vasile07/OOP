cmake_minimum_required(VERSION 3.17)
project(Laboratorul_2_4 C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(Laboratorul_2_4 main.c Domain/masina.h Domain/masina.c Tests/teste.h Interface/console.h Tests/teste.c Repository/repo_masini.h Service/service_masini.h Repository/repo_masini.c Service/service_masini.c Interface/console.c Validation/validator.h Validation/validator.c)
