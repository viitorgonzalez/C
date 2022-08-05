#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/*Uma pessoa criou um arquivo (nome fornecido pelo usuário) que contém as informações de 
15 eletrodomésticos: nome da loja, telefone e preço de cada eletrodoméstico. Elabore uma 
classe chamada Eletrodomestico com esses atributos e métodos para manipulá-los 
(construtores, assessores, exibição). Desenvolva um programa que permita ler os dados deste 
arquivo  e  preencher  um  vetor  com  objetos  do  tipo  Eletrodomestico.  O  programa  também 
deve  calcular  e  gravar  em  um  outro  arquivo  (nome  fornecido  pelo  usuário)  a  média  dos 
preços cadastrados e uma relação contendo o nome e o telefone das lojas cujo preço estava 
abaixo da média.*/

const int N = 3;

class Eletrodomestico {
private:
    std::string nome;
    std::string telefone;
    float preco;

public:
    Eletrodomestico(){}

    Eletrodomestico(std::string nome, std::string telefone, float preco){
        this->nome = nome;
        this->telefone = telefone;
        this->preco = preco;
    }

    std::string getDados(){
        return "Nome: " + this->nome + "\tPreço: " + std::to_string(this->preco) + "\tTelefone: " + this->telefone + "\n"; //dados 
    }

    float getPreco() {
        return this->preco;
    }
};

int main(void) {
    Eletrodomestico *e[N];
    std::ifstream arq;
    std::string op;
    std::cout << "\nForneça o nome do arquivo: ";
    std::cin >> op;
    arq.open(op);

    std::string linhaArq;
    int contadorEletro = 0;
    while(std::getline(arq, linhaArq)) { //pegar linha por linha do arquivo
        
        std::istringstream iss(linhaArq);
        std::string stringSplit;

        int contador = 0;
        std::string nomeLoja;
        std::string telefoneLoja;
        std::string precoLoja;
        std::string valor;
        while(std::getline(iss, valor, ' ')) { //pegar os cortes das linhas nome, telefone, preco
            if (contador == 0) {
                nomeLoja = valor;
            } else if (contador == 1) {
                telefoneLoja = valor;
            } else if (contador == 2) {
                precoLoja = valor;
            }

            contador++;
        }

        e[contadorEletro] = new Eletrodomestico(nomeLoja, telefoneLoja, std::stof(precoLoja));
        contadorEletro++;
    }

    float media = 0;
    for (int i = 0; i < contadorEletro; i++) {
        media += e[i]->getPreco();
    }
    media /= contadorEletro;
    
    std::string opc;
    std::cout << "\nForneça o nome do arquivo de saída: ";
    std::cin >> opc;
    std::ofstream arqSaida;
    arqSaida.open(opc);
    
    for (int i = 0; i < contadorEletro; i++) {
        if (e[i]->getPreco() < media)
            arqSaida << e[i]->getDados();
    }

    arqSaida.close();
    arq.close();

    return 0;
}