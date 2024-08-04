#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>
#include "../res/tileset/c/test.c"

void setBkg (void) { set_bkg_data (0, 0u, test_tileset); }

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


void main(void)
    {
        setBkg();
        uint8_t t=0;
        while(TRUE) //loop
            {
                printTest(4,4);
                SHOW_BKG;
                DISPLAY_ON;
                delay(500);
            }
    }