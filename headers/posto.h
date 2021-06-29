#ifndef POSTO
#define POSTO

class Posto{
    private:      
        int capacidade;
        int x;
        int y;
    public:
        Posto(); 
        Posto(int capacidade, int x, int y);        
        int GetX();
        int GetY();
        int GetCapacidade();
};

#endif