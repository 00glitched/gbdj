#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>

#include "tileSet.h"  



void bkgl_updateBkg (void)
    {
        SHOW_BKG; DISPLAY_ON;
    }


/* basic graphic functions
 */
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
void ezelib_makeLine(uint8_t pos_x, uint8_t pos_y, uint8_t dir, uint8_t quant, uint8_t tile)
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
void ezelib_makeMatrix(uint8_t pos_x, uint8_t pos_y, uint8_t quant_x, uint8_t quant_y, uint8_t tile)
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

 /* text functions
 ** printTextInLine: print text in horizontal line
 ** printTextInMatrix: print text inside of matrix
 */

void bkgl_printInLine(uint8_t pos_x, uint8_t pos_y, uint8_t ref, uint8_t len, unsigned char text[len])
    {
        uint8_t pos_i = pos_x;
        for (uint8_t i = 0; i < len; i++)
            {
                pos_i = pos_x+i;
                uint8_t tile = text[i]-ref;
                set_bkg_tile_xy (pos_i, pos_y, tile);
            }
    }
void bkgl_printTextInMatrix(uint8_t pos_x, uint8_t pos_y, uint8_t len_i, uint8_t len_j, uint8_t ref, uint8_t len, unsigned char text[len])
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

/* plotting functions
** printFunction: print an i,y[i],tile[i] function
*/
void ezelib_plotFunction(uint8_t pos_x, uint8_t pos_y, uint8_t dir, uint8_t pos, uint8_t len, uint8_t val_height[len],uint8_t val_tile[len])
    {
        if(dir==0)
            {
                if (pos==0)
                    {
                        uint8_t pos_j;
                        for(uint8_t i = 0; i<len; i++)
                            {
                                uint8_t pos_i = pos_x+i;
                                pos_j = pos_y+val_height[i];
                                if (pos_i<SCREEN_LENX && pos_j<SCREEN_LENY)
                                    {
                                        set_bkg_tile_xy (pos_i,pos_j, val_tile[i]);
                                    }
                                else
                                    {
                                        i=len;
                                    }
                            }
                    else
            }
    }




void main(void)
   {
    
        char toprint[3] = {29,35,37};
        char htoprint[3] = {1,2,3};
        graph();
        ezelib_blankScreen(96);
        char line1[3][3] = {{'A','w','A'},{'O','w','O'},{'E','w','E'}};
        char line2[] = "De UwU";
        char line3[] = "Bam0 v0kit4 LPM OwO";
        
        
        // Loop forever
        while (TRUE)
            {
                

                //ezelib_makeLine(1, 1, 1, 2, 70);
                //ezelib_makeMatrix(3,3,2,2,33);
                //ezelib_printTextInLine(2,6,'A'-34,sizeof(line2),line2);
                //ezelib_printTextInMatrix(2,7,5,12,'A'-34,sizeof(line3),line3);
                ezelib_plotFunction(1, 1, 0, 0, 4, htoprint, toprint);


                SHOW_BKG;
                DISPLAY_ON;
                // Done processing, yield CPU and wait for start of next frame

                delay(500);
            }
    }