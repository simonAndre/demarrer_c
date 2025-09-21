# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.5)

project(demo_pointeurs C)

set(CMAKE_C_STANDARD 11)
set(SRCS
	main.c
	pointeurs1.c
	pointeurs2.c
	pointeurs3.c
	chaines.c
	pointeurs_struct.c
	liste_chainee.c
	)
	
	set(HEADERS
	pointeurs.h
	liste_chainee.h
	pointeurs_struct.h
)

# On indique que l'on veut un exécutable "projet2" compilé à partir des fichiers décrit par les variables SRCS et HEADERS
add_executable(demo_pointeurs ${SRCS} ${HEADERS})

# si des libraries standard sont uitlisées, ajouter un lien dnas target_link_libraries ci-dessous (ex ici avec la library math)
# target_link_libraries(demo_pointeurs 
# 	PRIVATE string.h
# )