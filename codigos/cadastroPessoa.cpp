#include <iostream>
#include <fstream>

/*Dados  os  seguintes  campos  de  uma  classe  Pessoa:    nome,  dia  de  aniversário  e  mês  de 
aniversário, desenvolver um programa que preencha um cadastro de 10 pessoas e grave em 
um arquivo (nome fornecido pelo usuário) cada um dos meses do ano e quem são as pessoas 
que fazem aniversário naquele mês, exibir também o dia. Na classe Pessoa, crie os métodos 
para manipular os atributos (construtores, assessores, métodos gerais). */

const int N = 10; //tamanho do vetor de Pessoa

class Pessoa {
private:
    std::string nome;
    int  diaBirth, mesBirth;

public:
    Pessoa(){}

    Pessoa(std::string nome, int dia, int mes){
        this->nome = nome;
        this->diaBirth = dia;
        this->mesBirth = mes;
    }

    void setNome(std::string nome){
        this->nome = nome;
    }

    void setDia(int dia){
        this->diaBirth = dia;
    }

    void setMes(int mes){
        this->mesBirth = mes;
    }

    std::string getDados(){
        return "Nome: " + this->nome + "\tData: " + std::to_string(this->diaBirth) + "/" + std::to_string(this->mesBirth) + "\n";
    }

    int getMes(){
        return this->mesBirth;
    }
};

int main(void) {
    Pessoa *p[N]; //vetor de ponteiros de Pessoa
    std::string entradaNome; //var para setar nome
    int entradaDia, entradaMes; //var para setar o dia e mes
    std::ofstream arq; 
    arq.open("arquivo.txt");

    for(int i = 0; i < N; i++) {
        p[i] = new Pessoa(); //criar um objeto de Pessoa
        std::cout << "\nDigite seu nome: ";
        std::cin >> entradaNome;
        std::cout << "\nDigite o dia de seu aniversário: ";
        std::cin >> entradaDia;
        std::cout << "\nDigite o mês de seu aniversário: ";
        std::cin >> entradaMes;
        p[i]->setNome(entradaNome);
        p[i]->setDia(entradaDia);
        p[i]->setMes(entradaMes);
    }

    for(int i = 1; i <= 12; i++) {
        for(int j = 0; j < N; j++) {
            if(p[j]->getMes() == i) {
                std::cout << p[j]->getDados(); //mostra na tela
                arq << p[j]->getDados(); //escreve em arquivo.txt
            }
        }
    }

    arq.close();
}