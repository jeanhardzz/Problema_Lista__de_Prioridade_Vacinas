#ifndef POSTO
#define POSTO

class Posto{
    private:      
        int capacidade;
        float x;
        float y;
    public:
        Posto(); 
        Posto(int capacidade, float x, float y);        
        float GetX();
        float GetY();
        int GetCapacidade();
};

#endif