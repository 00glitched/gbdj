#include <stdint.h>
#include <stdio.h>
#include <gb/gb.h>

void bkgl_updateBkg (void)
    {
        SHOW_BKG; DISPLAY_ON;
    }
void bkgl_blankScreen (uint8_t len_x, uint8_t len_y, uint8_t blankTile)
    {
        for (uint8_t j=0; j<len_y; j++)
            {
                for (uint8_t i=0; i<len_x; i++)
                    {
                        set_bkg_tile_xy (i,j, blankTile);
                    }
            }
    }
void bkgl_makeLine (uint8_t pos_x, uint8_t pos_y, uint8_t dir, uint8_t quant, uint8_t tile)
    {
        if (dir==0)
            {
                uint8_t tq = pos_x+quant;
                for (uint8_t t=pos_x; t<tq; t++)    //right
                    {
                        set_bkg_tile_xy (t, pos_y, tile);
                    }
            }
        else if (dir==1)
            {
                uint8_t tq = pos_y-quant;
                for (uint8_t t=pos_y; t>tq; t--)    //up
                    {
                        set_bkg_tile_xy (pos_x, t, tile);
                    }
            }
        else if(dir==2)
            {
                uint8_t tq = pos_x-quant;
                for(uint8_t t=pos_x; t>tq; t--)    //left
                    {
                        set_bkg_tile_xy (t, pos_y, tile);
                    }
            }
        else if (dir==3)
            {
                uint8_t tq = pos_y+quant;
                for(uint8_t t=pos_y; t<tq; t++)    //dowm
                    {
                        set_bkg_tile_xy (pos_x, t, tile);
                    }
            }
    }
void bkgl_makeMatrix (uint8_t pos_x, uint8_t pos_y, uint8_t quant_x, uint8_t quant_y, uint8_t tile)
    {

        uint8_t pos_i = pos_x+quant_x;
        uint8_t pos_j = pos_y+quant_y;
        for (uint8_t j = pos_y; j < pos_j; j++)
            {
                for (uint8_t i = pos_x; i < pos_i; i++)
                    {
                        set_bkg_tile_xy (i, j, tile);
                    }
            }
        
    }

void bkgl_printTextInLine (uint8_t pos_x, uint8_t pos_y, uint8_t ref, uint8_t len, uint8_t *text)
    {
        uint8_t pos_i = pos_x;
        for (uint8_t i = 0; i < len; i++)
            {
                pos_i = pos_x+i;
                uint8_t tile = text[i]-ref;
                set_bkg_tile_xy (pos_i, pos_y, tile);
            }
    }
void bkgl_printTextInMatrix (uint8_t pos_x, uint8_t pos_y, uint8_t len_i, uint8_t len_j, uint8_t ref, uint8_t len, uint8_t *text)
    {
        uint8_t pos_i = pos_x;
        uint8_t pos_j = pos_y;
        uint8_t pos_text = 0;
        for (uint8_t j = 0; j < len_j; j++)
            {
                for (uint8_t i = 0; i < len_i; i++)
                    {
                        
                        if (pos_text<len)
                            {
                                pos_i = pos_x+i;
                                pos_j = pos_y+j;
                                uint8_t tile = text[pos_text]-ref;
                                set_bkg_tile_xy (pos_i,pos_j, tile);
                                pos_text++;
                            }
                        else
                            {
                                i=len_i;j=len_j;
                            }
                    }
            }
    }