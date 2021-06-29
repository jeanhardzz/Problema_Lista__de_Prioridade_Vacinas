#ifndef PESSOA
#define PESSOA

class Pessoa{
    private:      
        int idade;
        float x;
        float y;
    public:
        Pessoa();        
        Pessoa(int idade, float x, float y);        
        float GetX();
        float GetY();
        int GetIdade();
};

#endif