#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>


void printTest (uint8_t len_x, uint8_t len_y)
    {
        uint8_t k=0;
        for (uint8_t j=0; j<len_y; j++)
            {
                for (uint8_t i=0; i<len_x; i++)
                    {
                        set_bkg_tile_xy (i, j, k); k++;
                    }
            }
    }

void test(void)
    {
        printTest(3,3);
    }