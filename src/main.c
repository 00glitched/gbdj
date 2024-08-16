#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>

//media
//#include "../res/tileset/c/test.c"

//source
#include "../src/screen.h"


uint8_t MyMat[4][4]=
    {
        {1,0,0,0},
        {0,2,0,0},
        {0,0,3,0},
        {0,0,0,4}
    };

uint8_t MyMat1[4]= {1,0,0,0};
uint8_t MyMat2[4]= {2,2,2,5};
uint32_t counter_fps = 0;
const uint8_t delay_fps = 12;

void main(void)
    {
        setBkg();
        setBlank(47);
        uint8_t t=0;
        uint8_t Xi=0;
        while(TRUE) //loop
            {
                
                uint32_t CLK = sys_time;
                if (counter_fps < CLK)
                    {
                        printTile (Xi-1, 6, 4, 4, 47);
                        printFunc (Xi, 6, 4, &MyMat1[0], &MyMat2[0]);
                        SHOW_BKG;
                        DISPLAY_ON;
                        Xi++;
                        if (Xi>6){Xi=0;}
                        counter_fps+=delay_fps;
                    }
            }
    }