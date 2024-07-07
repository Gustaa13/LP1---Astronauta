#ifndef FUNCS_H
#define FUNCS_H

#include <vector>
#include "funcs.cpp"

void cadastrar_astronauta(std::vector<Astronauta*>* astronautas);
void listar_astronautas(std::vector<Astronauta*>* astronautas);
void listar_astronautas_mortos(std::vector<Astronauta*>* astronautas);
void controlador_de_Voos(std::vector<Voo*>* voos, int opcao);
void listar_voos(std::vector<Voo*>* voos);
void cadastrar_voo(std::vector<Voo*>* voos);
void adicionandoAstronauta(std::vector<Astronauta*>* astronautas, std::vector<Voo*>* voos);
void removendoAstronauta(std::vector<Astronauta*>* astronautas, std::vector<Voo*>* voos);

#endif