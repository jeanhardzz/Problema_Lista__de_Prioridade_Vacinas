#ifndef PESSOA
#define PESSOA

class Pessoa{
    private:      
        int idade;
        int x;
        int y;
    public:
        Pessoa();        
        Pessoa(int idade, int x, int y);        
        int GetX();
        int GetY();
        int GetIdade();
};

#endif