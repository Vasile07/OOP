cmake_minimum_required(VERSION 3.17)
project(Lab5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab5 main.c listaOferte.c oferta.c ofertaRepo.c ofertaService.c testOfertaRepo.c testOfertaService.c ui.c)
