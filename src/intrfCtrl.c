#include <stdint.h>
#include <stdio.h>

  #include "../res/include/scren.h"
//#include "../res/include/audio.h"
//#include "../res/include/input.h"

struct cood
    {
        uint8_t x;
        uint8_t y;
        uint8_t m;
        uint8_t n;
    };

uint8_t screen[18][20];

void intrfCtrl (void)
    {
        // graphs in screen
        printMatr(2,2,4,4,&screen[0][0]);
        
        dispBkg();
    }
/*
uint8_t input_ctrl (uint8_t x_pos, uint8_t y_pos, uint8_t m_pos, uint8_t n_pos)
    {
        uint8_t x;
        uint8_t y;
        uint8_t m;
        uint8_t n;
        
        
        
        uint8_t newpiv[4]; 
        return newpiv;
    }
    */
