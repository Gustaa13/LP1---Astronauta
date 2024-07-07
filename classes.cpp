#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Astronauta{

  private:
    std::string cpf;
    std::string nome;
    std::vector<int> voos;
    int idade;
    bool disponivel;
    bool vivo;

  public:
    // Métodos especiais
    // Construtor:
    Astronauta(std::string cpf, std::string nome, int idade)
      : cpf(cpf), nome(nome), idade(idade), disponivel(true), vivo(true) {}

    //Getters (Retorna o valor atual do atributo):
    std::string getCpf(){
      return cpf;
    }

    std::string getNome(){
      return nome;
    }

    int getIdade(){
      return idade;
    }

    bool getDisponivel(){
      return disponivel;
    }

    bool getVivo(){
      return vivo;
    }

    //Setters (Substitui o valor atual do atributo por outro valor)
    void setCpf(std::string cpfNovo){
      cpf = cpfNovo; 
    }

    void setNome(std::string nomeNovo){
      nome = nomeNovo;
    }
    
    void setIdade(int idadeNova){
      idade = idadeNova;
    }

    void setDisponivel(bool disponivelNovo){
      disponivel = disponivelNovo;
    }

    void setMorto(){
      vivo = false;
    }

    void setVoo(int codigo){
      voos.push_back(codigo);
    }

    //Métodos da classe:

    void listar_voos(){
      std::cout << "Voos: " << voos[0];
      for (unsigned int i = 1; i < voos.size(); i++){
        std::cout << ", " << voos[i];
      }
      std::cout << "" << std::endl;
    }
};

class Voo{

  private:
    int codigo;
    std::vector<Astronauta*> astronautas;
    bool planejamento;
    bool explodido;
    bool finalizado;

  public:
    // Métodos especiais
    // Construtor:
    Voo(int codigo) : codigo(codigo), planejamento(true), explodido(false), finalizado(false){}

    //Getters:
    int getCodigo(){
      return codigo;
    }

    bool getPlanejamento(){
      return planejamento;
    }

    bool getExplodido(){
      return explodido;
    }

    bool getFinalizado(){
      return finalizado;
    }

    //Setters:
    void setCodigo(int codigoNovo){
      codigo = codigoNovo;
    }

    void setPlanejamento(bool planejamentoNovo){
      planejamento = planejamentoNovo;
    }

    void setExplodido(){
      explodido = true;
    }

    void setFinalizado(){
      finalizado = true;
    }

    //Métodos do voo:
    void addAstronauta(Astronauta* astronautaNovo){
      bool ja_tripula_voo = false;

      for (auto astronauta : astronautas){
        if(astronauta->getCpf() == astronautaNovo->getCpf()){
          ja_tripula_voo = true;
          break;
        }
      }
      if(ja_tripula_voo){  
        std::cout << "\n Astronauta já tripula esse voo!" << std::endl;
      }
      else{
        astronautas.push_back(astronautaNovo);
        std::cout << "\n Astronauta adicionado com sucesso!" << std::endl;
      }
      
    }

    void removerAstronauta(Astronauta* astronautaNovo){
      bool ja_tripula_voo = false;
      
      for (auto astronauta : astronautas){
        if(astronauta->getCpf() == astronautaNovo->getCpf()){
          ja_tripula_voo = true;
          break;
        }
      }

      if(ja_tripula_voo){
        astronautas.erase(std::remove(astronautas.begin(), astronautas.end(), astronautaNovo), astronautas.end());
        std::cout << "\n Astronauta removido do voo com sucesso!" << std::endl;
      }
      else{
        std::cout << "\n Astronauta não tripula esse voo!" << std::endl;
      }
    }

    void listarAstronautas_do_Voo(){
      std::cout << "~~~ Tripulantes ~~~" << std::endl;
      for (auto astronauta : astronautas){
        std::cout << astronauta->getNome() << ", Cpf: " << astronauta->getCpf() << std::endl;
      }
    }

    void realizarVoo(){
      bool tripulante_indisponivel = false;
      for (auto astronauta : astronautas){
        if(!astronauta->getDisponivel()){
          tripulante_indisponivel = true;
          break;
        }
      }
      if(getPlanejamento() && !getExplodido() && !getFinalizado() && !tripulante_indisponivel && astronautas.size() > 0){
        setPlanejamento(false);
        for (auto astronauta : astronautas){
          astronauta->setDisponivel(false);
          astronauta->setVoo(codigo);
        }
        std::cout << "\n Voo partiuuu!" << std::endl;
      }
      else if(!getPlanejamento() && !getExplodido() && !getFinalizado()){
        std::cout << "\n Voo já em curso!" << std::endl;
      }
      else if(getExplodido()){
        std::cout << "\n Voo já explodido!" << std::endl;
      }
      else if(getFinalizado()){
        std::cout << "\n Voo já finalizado!" << std::endl;
      }
      else if(astronautas.size() <= 0){
        std::cout << "\n Voo não possui tripulantes!" << std::endl;
      }
      else if(tripulante_indisponivel){
        std::cout << "\n Voo possui tripulantes indiponíveis, remova-os ou espere suas missões espaciais acabarem!" << std::endl;
      }
      
      
    }

    void explodirVoo(){
      if(!getPlanejamento() && !getExplodido() && !getFinalizado()){
        setExplodido();
        for (auto astronauta : astronautas){
          astronauta->setMorto();
          astronauta->setDisponivel(false);
        }
        std::cout << "\n Voo explodiuu!" << std::endl;
      }
      else if(getPlanejamento()){
        std::cout << "\n Voo em planejamento!" << std::endl;
      }
      else if(getExplodido()){
        std::cout << "\n Voo já explodido!" << std::endl;
      }
      else if(getFinalizado()){
        std::cout << "\n Voo já finalizado!" << std::endl;
      }
    }

    void finalizarVoo(){
      if(!getPlanejamento() && !getExplodido() && !getFinalizado()){
        setFinalizado();
        for (auto astronauta : astronautas){
          astronauta->setDisponivel(true);
        }
        std::cout << "\n Missão finalizada com sucesso!" << std::endl;
      }
      else if(getPlanejamento()){
        std::cout << "\n Voo em planejamento!" << std::endl;
      }
      else if(getExplodido()){
        std::cout << "\n Voo já explodido!" << std::endl;
      }
      else if(getFinalizado()){
        std::cout << "\n Voo já finalizado!" << std::endl;
      }
    }
};