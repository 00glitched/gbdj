#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>
#include "res/tileset/test.c"
#include "res/tileset/c/test.c"

void setBkg (void) { set_bkg_data (0, 128u, test_tileset); }

void main(void)
    {
        setBkg();

        while(TRUE) //loop
            {
                test();
                SHOW_BKG;
                delay(500);
            }
    }