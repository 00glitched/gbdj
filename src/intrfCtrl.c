#include <stdint.h>
#include <stdio.h>

#include "../res/include/scren.h"
//#include "../res/include/audio.h"
//#include "../res/include/input.h"

const uint8_t K[4][4]=
    {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };

void intrfCtrl (void)
    {
        // graphs in screen
        printMatr(2,2,4,4,&K[0][0]);
        
        dispBkg();
    }
/*
void input_ctrl()
    {

    }
*/