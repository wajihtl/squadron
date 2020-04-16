med: collision.o vie.o  map.o ennemi.o main.o 
	gcc   collision.o vie.o  map.o ennemi.o main.o -lSDL -lSDL_image -lSDL_mixer -o med

main.o:main.c
	gcc -c main.c

ennemi.o:ennemi.c
	gcc -c ennemi.c

map.o:map.c
	gcc -c map.c



vie.o:vie.c
	gcc -c vie.c

collision.o:collision.c
	gcc -c collision.c



