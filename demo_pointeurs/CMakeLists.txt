# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.5)

project(projet2 C)

set(CMAKE_C_STANDARD 11)
set(SRCS
	main.c
	point1.c
	point2.c
)
	
set(HEADERS
	pointeurs.h
)

# On indique que l'on veut un exécutable "projet2" compilé à partir des fichiers décrit par les variables SRCS et HEADERS
add_executable(projet2 ${SRCS} ${HEADERS})

# si des libraries standard sont uitlisées, ajouter un lien dnas target_link_libraries ci-dessous (ex ici avec la library math)
# target_link_libraries(projet2 
# 	PRIVATE string.h
# )