#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include "../src/config.c"

//tilesets
#include "../res/tiles/tileBank.c"

//maps
#include "../res/maps/mainMenu.c"
//#include "../res/maps/loopEditor.c"
//#include "../res/maps/trackEditor.c"
//#include "../res/maps/waveEditor.c"


void graphAllScreen(uint8_t screenTiles[SCREEN_LENY][SCREEN_LENX])
    {
        for (uint8_t j = 0; j < SCREEN_LENY; j++)
            {
                for (uint8_t i = 0; i < SCREEN_LENX; i++)
                    {
                        set_bkg_tile_xy(i,j,_MENU0);
                    }
                
            }
    }

void



void menuGraph(uint8_t pointer_menu, uint8_t pointer_x_pos, uint8_t pointer_y_pos)
    {
        switch(pointer_menu)
            {
                case 0: //main menu
                    if(_graph_vars==0)
                        {
                            graphAllScreen(MENU_0);
                        }
                    set_bkg_tile_xy (pointer_x_pos-1, pointer_y_pos, '-');
                    set_bkg_tile_xy (pointer_x_pos, pointer_y_pos, '>');
                    SHOW_BKG;
                break;

                case 10: //menu

                break;
            }
    }
