#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>

#include "../res/tileset/c/Ascii.c"

void setBkg (void) { set_bkg_data (0, 0u, Ascii_tileset); }

void setMatrix (uint8_t x_pos, uint8_t y_pos, uint8_t x_len, uint8_t y_len, uint8_t arr[y_len][x_len])
    {
        for (size_t i = 0; i < count; i++)
            {
                for (size_t i = 0; i < count; i++)
                    {
                        set_bkg_tile_xy (i+x_pos,j+y_pos,arr[j][i]);
                    }
                
            }
            
        

    }