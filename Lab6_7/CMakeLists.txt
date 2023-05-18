cmake_minimum_required(VERSION 3.22)
project(Laboratorul_6_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laboratorul_6_7 main.cpp Domain/Film.h Domain/Film.cpp Tests/Teste.h Tests/Teste.cpp Errors/Erori.h Errors/Erori.cpp Repository/RepoFilme.h Repository/RepoFilme.cpp Validator/Validator.h Validator/Validator.cpp Bussines/ServiceFilme.cpp Bussines/ServiceFilme.h Presentation/Console.cpp Presentation/Console.h Utilitar/MyString.cpp Utilitar/MyString.h Utilitar/MyVector.h Utilitar/MyVector.h Cos_Inchiriere/CosFilme.cpp Cos_Inchiriere/CosFilme.h Repository/FileRepoFilme.cpp Repository/FileRepoFilme.h Undo/ActiuneUndo.h Repository/BaseRepo.h Repository/BaseRepo.h)
