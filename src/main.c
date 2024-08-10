#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>

//media
//#include "../res/tileset/c/test.c"

//source
#include "../src/screen.h"


void printTest (uint8_t len_x, uint8_t len_y)
    {
        uint8_t k=0;
        for (uint8_t j=0; j<len_y; j++)
            {
                for (uint8_t i=0; i<len_x; i++)
                    {
                        set_bkg_tile_xy (i, j, k);k++;
                    }
            }
    }

uint8_t MyMat[4][4]=
    {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };


void main(void)
    {
        setBkg();
        setBlank(47);
        uint8_t t=0;
        while(TRUE) //loop
            {
                printMatrix(6,6,4,4,&MyMat[0][0]);
                SHOW_BKG;
                DISPLAY_ON;
                delay(500);
            }
    }