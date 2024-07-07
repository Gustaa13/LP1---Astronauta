#include <iostream>
#include <string>
#include <vector>
#include "classes.cpp"

void cadastrar_astronauta(std::vector<Astronauta*>* astronautas)
{
  std::string cpf;
  std::string nome;
  int idade;
  bool ja_cadastrado = false;

  std::cout << "\033[2J\033[1;1H";
  std::cout << "Digite o CPF do astronauta: ";
  std::cin >> cpf;
  std::cout << "Digite o nome do astronauta: ";
  std::cin.ignore();
  std::getline(std::cin, nome);
  std::cout << "Digite a idade do astronauta: ";
  std::cin >> idade;

  for (auto astronauta : *astronautas){
    if(astronauta->getCpf() == cpf){
      ja_cadastrado = true;
      break;
    }
  }

  if(ja_cadastrado){
    std::cout << "\n Esse Cpf já foi cadastrado!" << std::endl;
  }
  else{
    Astronauta* novoAstronauta = new Astronauta(cpf, nome, idade);
    astronautas->push_back(novoAstronauta);
    std::cout << "\n Astronauta cadastrado com sucesso!" << std::endl;
  }
}

void cadastrar_voo(std::vector<Voo*>* voos)
{
  int codigo;
  bool ja_cadastrado = false;

  std::cout << "\033[2J\033[1;1H";
  std::cout << "Digite o codigo do Voo: ";
  std::cin >> codigo;

  for (auto voo : *voos){
    if(voo->getCodigo() == codigo){
      ja_cadastrado = true;
      break;
    }
  }

  if(ja_cadastrado){
    std::cout << "\n Esse código de voo já foi cadastrado!" << std::endl;
  }
  else{
    Voo* novoVoo = new Voo(codigo);
    voos->push_back(novoVoo);
    std::cout << "\n Voo cadastrado com sucesso!" << std::endl;
  }
}


void listar_astronautas(std::vector<Astronauta*>* astronautas)
{
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n ~~~ Astronautas Cadastrados ~~~" << std::endl;
  for (auto astronauta : *astronautas){
    std::cout << astronauta->getNome() << ", Cpf: " << astronauta->getCpf() << std::endl;
  }
}

void listar_astronautas_mortos(std::vector<Astronauta*>* astronautas)
{
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n ~~~ Astronautas Falecidos em Missão ~~~" << std::endl;
  for (auto astronauta : *astronautas){
    if(astronauta->getVivo() == false){
      std::cout << astronauta->getNome() << ", Cpf: " << astronauta->getCpf() << ", ";
      astronauta->listar_voos();
    }
  }
}

void listar_voos(std::vector<Voo*>* voos)
{
  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n ~~~ Voos em Planejamento: ~~~" << std::endl;
  for (auto voo : *voos){
    if(voo->getPlanejamento() && !voo->getExplodido() && !voo->getFinalizado()){
      std::cout << "\nVoo " << voo->getCodigo() << ":" << std::endl;
      voo->listarAstronautas_do_Voo();
    }
  }

  std::cout << "\n ~~~ Voos em Curso: ~~~" << std::endl;
  for (auto voo : *voos){
    if(!voo->getPlanejamento() && !voo->getExplodido() && !voo->getFinalizado()){
      std::cout << "\nVoo " << voo->getCodigo() << ":"  << std::endl;
      voo->listarAstronautas_do_Voo();
    }
  }

  std::cout << "\n ~~~ Voos Finalizados: ~~~" << std::endl;
  for (auto voo : *voos){
    if(!voo->getPlanejamento() && !voo->getExplodido() && voo->getFinalizado()){
      std::cout << "\nVoo " << voo->getCodigo() << ":" << std::endl;
      voo->listarAstronautas_do_Voo();
    }
  }

  std::cout << "\n ~~~ Voos Explodidos: ~~~" << std::endl;
  for (auto voo : *voos){
    if(!voo->getPlanejamento() && voo->getExplodido() && !voo->getFinalizado()){
      std::cout << "\nVoo " << voo->getCodigo() << ":" << std::endl;
      voo->listarAstronautas_do_Voo();
    }
  }
}

void adicionandoAstronauta(std::vector<Astronauta*>* astronautas, std::vector<Voo*>* voos)
{
  std::string cpf;
  int codigo_voo;

  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n ~~~ Adicionando astronauta ao Voo ~~~" << std::endl;
  std::cout << "\n Digite o código do Voo: ";
  std::cin >> codigo_voo;
  std::cout << "\n Digite o cpf do Astronauta: ";
  std::cin >> cpf;

  Astronauta* astronautaEncontrado = nullptr;
  Voo* vooEncontrado = nullptr;

  for (auto astronauta : *astronautas){
    if(astronauta->getCpf() == cpf){
      astronautaEncontrado = astronauta;
      break;
    }
  }

  for (auto voo : *voos){
    if(voo->getCodigo() == codigo_voo){
      vooEncontrado = voo;
      break;
    }
  }

  if (astronautaEncontrado && vooEncontrado && astronautaEncontrado->getVivo() && astronautaEncontrado->getDisponivel() && vooEncontrado->getPlanejamento() && !(vooEncontrado->getExplodido())) {
    vooEncontrado->addAstronauta(astronautaEncontrado);
  } 
  else{
    if (!astronautaEncontrado) {
      std::cout << "\n Não adicionado, astronauta não encontrado!" << std::endl;
    }
    else if(!astronautaEncontrado->getVivo()){
      std::cout << "\n Não adicionado, astronauta falecido!" << std::endl;
    }
    else if(!astronautaEncontrado->getDisponivel()){
      std::cout << "\n Não adicionado, astronauta indisponível no momento!" << std::endl;
    }

    if (!vooEncontrado) {
      std::cout << "\n Voo não encontrado, nenhum astronauta pode ser adicionado!" << std::endl;
    }
    else if(!vooEncontrado->getPlanejamento() && !vooEncontrado->getExplodido() && !vooEncontrado->getFinalizado()){
      std::cout << "\n Voo em curso, nenhum astronauta pode ser adicionado!" << std::endl;
    }
    else if(vooEncontrado->getFinalizado()){
      std::cout << "\n Voo finalizado, nenhum astronauta pode ser adicionado!" << std::endl;
    }
    else if(vooEncontrado->getExplodido()){
      std::cout << "\n Voo explodido, nenhum astronauta pode ser adicionado!!" << std::endl;
    }
    
  }
}

void removendoAstronauta(std::vector<Astronauta*>* astronautas, std::vector<Voo*>* voos)
{
  std::string cpf;
  int codigo_voo;

  std::cout << "\033[2J\033[1;1H";
  std::cout << "\n ~~~ Removendo astronauta do Voo ~~~" << std::endl;
  std::cout << "\n Digite o código do Voo: ";
  std::cin >> codigo_voo;
  std::cout << "\n Digite o cpf do Astronauta: ";
  std::cin >> cpf;

  Astronauta* astronautaEncontrado = nullptr;
  Voo* vooEncontrado = nullptr;

  for (auto astronauta : *astronautas){
    if(astronauta->getCpf() == cpf){
      astronautaEncontrado = astronauta;
      break;
    }
  }

  for (auto voo : *voos){
    if(voo->getCodigo() == codigo_voo){
      vooEncontrado = voo;
      break;
    }
  }

  if (astronautaEncontrado && vooEncontrado && astronautaEncontrado->getVivo() && vooEncontrado->getPlanejamento() && !(vooEncontrado->getExplodido())) {
    vooEncontrado->removerAstronauta(astronautaEncontrado);
  } 
  else{
    if (!astronautaEncontrado) {
      std::cout << "\n Não removido, astronauta não encontrado!" << std::endl;
    }
    else if(!astronautaEncontrado->getVivo() && vooEncontrado->getPlanejamento()){
      std::cout << "\n Não removido, astronauta não tripula esse voo!" << std::endl;
    }

    if (!vooEncontrado) {
      std::cout << "\n Voo não encontrado, nenhum astronauta pode ser removido!" << std::endl;
    }
    else if(!vooEncontrado->getPlanejamento() && !vooEncontrado->getExplodido() && !vooEncontrado->getFinalizado()){
      std::cout << "\n Voo em curso, nenhum astronauta pode ser removido!" << std::endl;
    }
    else if(vooEncontrado->getFinalizado()){
      std::cout << "\n Nenhum astronauta pode ser removido, esse voo já foi finalizado!" << std::endl;
    }
    else if(vooEncontrado->getExplodido()){
      std::cout << "\n Nenhum astronauta pode ser removido, esse voo explodiu!" << std::endl;
    }
  }
}

void controlador_de_Voos(std::vector<Voo*>* voos, int opcao)
{
  int codigo_voo;
  Voo* vooEncontrado = nullptr;

  switch (opcao)
  {
    case 1:
      std::cout << "\033[2J\033[1;1H";
      std::cout << "\n ~~~ Realizando Voo ~~~" << std::endl;
      std::cout << "\n Digite o código do Voo: ";
      std::cin >> codigo_voo;

      for (auto voo : *voos){
        if(voo->getCodigo() == codigo_voo){
          vooEncontrado = voo;
          break;
        }
      }

      if(vooEncontrado){
        vooEncontrado->realizarVoo();
      }
      else{
        std::cout << "\n Voo não encontrado!" << std::endl;
      }
      
      break;
  
    case 2:
      std::cout << "\033[2J\033[1;1H";
      std::cout << "\n ~~~ Explodindo Voo ~~~" << std::endl;
      std::cout << "\n Digite o código do Voo: ";
      std::cin >> codigo_voo;

      for (auto voo : *voos){
        if(voo->getCodigo() == codigo_voo){
          vooEncontrado = voo;
          break;
        }
      }

      if(vooEncontrado){
        vooEncontrado->explodirVoo();
      }
      else{
        std::cout << "\n Voo não encontrado!" << std::endl;
      }

      break;
  
    case 3:
      std::cout << "\033[2J\033[1;1H";
      std::cout << "\n ~~~ Finalizando Voo ~~~" << std::endl;
      std::cout << "\n Digite o código do Voo: ";
      std::cin >> codigo_voo;

      for (auto voo : *voos){
        if(voo->getCodigo() == codigo_voo){
          vooEncontrado = voo;
          break;
        }
      }

      if(vooEncontrado){
        vooEncontrado->finalizarVoo();
      }
      else{
        std::cout << "\n Voo não encontrado!" << std::endl;
      }
      
      break;

    default: std::cout << "\n Não existe essa opção";
  }
}

