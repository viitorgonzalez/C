#include <iostream>

/*Crie uma classe Equipamento com o atributo ligado (tipo boolean) e com os métodos liga e 
desliga.  O  método  liga()  torna  o  atributo  ligado  true  e  o  método  desliga()  torna  o  atributo 
ligado false. 
Crie também uma classe EquipamentoSonoro que herda as características de Equipamento e 
que  possui  os  atributos  volume  (tipo  short)  que  varia  de  0  a  10  e  stereo  (tipo  boolean).  A 
classe ainda deve possuir métodos get para retornar valor de cada atributo e set para gravar 
um  valor  em  um  atributo.  Crie  também  os  métodos  mono()  e  stereo().  O  método  mono() 
torna o atributo stereo falso e o método stereo() torna o atributo stereo verdadeiro. Ao ligar 
o EquipamentoSonoro através do método liga, seu volume é automaticamente ajustado para 
5.*/

class Equipamento { //classe equipamento
private:
    bool ligado; 

public:
    void liga() {
        this->ligado = true;
    }

    void desliga() {
        this->ligado = false;
    }
};

class EquipamentoSonoro : public Equipamento { //classe EquipamentoSonoro é filha de Equipamento
private:
    short volume;
    bool _stereo;

public:
    void setVolume (short volume) {
        if (volume >= 0 && volume <= 10)
            this->volume = volume;
    }

    short getVolume() {
        return this->volume;
    }

    void mono() {
        this->_stereo = false;
    }

    void stereo() {
        this->_stereo = true;
    }

    void liga() {
        Equipamento::liga();
        this->volume = 5;   
    }
};