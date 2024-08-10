#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>

#include "../res/tileset/c/test.c"

const uint8_t SCREEN_TILE_LEN_X = 20;
const uint8_t SCREEN_TILE_LEN_Y = 18;

void setBkg (void)
    {
        set_bkg_data (0, 0u, test_tileset);
    }

void setBlank(uint8_t tile)
    {
        for (uint8_t j = 0; j < SCREEN_TILE_LEN_Y; j++)
            {
                for (uint8_t i = 0; i < SCREEN_TILE_LEN_X; i++)
                    {
                        set_bkg_tile_xy (i, j, tile);
                    }
            }
    }

void printMatrix (uint8_t x_pos, uint8_t y_pos, uint8_t x_len, uint8_t y_len, uint8_t *arr)
    {
        for (uint8_t j = 0; j < y_len; j++)
            {
                for (uint8_t i = 0; i < x_len; i++)
                    {
                        uint8_t k = *(arr + j * y_len + i);
                        set_bkg_tile_xy (i + x_pos, j + y_pos, k);
                    }
            }   
    }

/*
void printFunc (uint8_t x_pos, uint8_t y_pos, uint8_t x_len, uint8_t y_len, uint8_t arr, uint8_t mode)
    {
        switch (mode)
            {
                case 'y': //y(x), tile: const
                    set_bkg_tile_xy (0,0,2);
                break;

                case 'x': //x(y), tile: const
                    set_bkg_tile_xy (0,0,2);

                break;

                case 'a': //y(x), tile(arr)
                    set_bkg_tile_xy (0,0,2);
                break;

                case 'b': //x(y), tile(arr)
                   set_bkg_tile_xy (0,0,2);
                break;

            }
    }
*/