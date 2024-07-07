#include <iostream>
#include <string>
#include <vector>
#include "funcs.hpp"

using namespace std;

int main() {
  int opcao = 12;
  vector<Astronauta*> astronautas;
  vector<Voo*> voos;
  
  while (opcao != 0){    
    cout << "\n--- Sistema de Gestão de Astronautas e Voo espaciais ---\n" << std::endl;
    cout << "1. Cadastrar Astronauta\n" << endl;
    cout << "2. Cadastrar Voo\n" << endl;
    cout << "3. Adicionar astronauta em voo\n" << endl;
    cout << "4. Remover astronauta de um voo\n" << endl;
    cout << "5. Realizar um voo\n" << endl;
    cout << "6. Explodir um voo\n" << endl;
    cout << "7. Finalizar um voo\n" << endl;
    cout << "8. Listar todos os voos\n" << endl;
    cout << "9. Listar todos os astronautas mortos\n" << endl;
    cout << "10. Listar todos os astronautas\n" << endl;
    cout << "0. Sair do sistema de gerenciamento\n" << endl;
    
    cout << "Escolha uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
      case 1: cadastrar_astronauta(&astronautas); break;
  
      case 2: cadastrar_voo(&voos); break;
  
      case 3: adicionandoAstronauta(&astronautas, &voos); break;
  
      case 4: removendoAstronauta(&astronautas, &voos); break;
  
      case 5: controlador_de_Voos(&voos, 1); break;
  
      case 6: controlador_de_Voos(&voos, 2); break;
  
      case 7: controlador_de_Voos(&voos, 3); break;
  
      case 8: listar_voos(&voos); break;
  
      case 9: listar_astronautas_mortos(&astronautas); break;

      case 10: listar_astronautas(&astronautas); break;
  
      case 0: 
        cout << "\033[2J\033[1;1H";
        cout << "\nSistema Finalizado!" << endl; 
        break;
      
      default: cout << "\nOpção inválida! Tente novamente!\n" << endl; 
    }
  }
}