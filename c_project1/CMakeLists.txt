# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.5)

# Notre projet est étiqueté hello
project(hello C)

set(CMAKE_C_STANDARD 11)
# Créé des variables avec les fichiers à compiler
set(SRCS
	main.c
	hello.c
	)
	
	set(HEADERS
	hello.h
	)

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrit par les variables SRCS et HEADERS
add_executable(hello ${SRCS} ${HEADERS})

# si des libraries standard sont uitlisées, ajouter un lien dnas target_link_libraries ci-dessous (ex ici avec la library math)
#target_link_libraries(hello PRIVATE m)