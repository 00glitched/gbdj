#include <gb/gb.h> 
#include <stdint.h>
#include <stdio.h>
#include <time.h>

//program
#include "../src/config.c"
#include "../src/globalvars.c"
#include "../src/screen.c" //todo now xd        <<<<----
#include "../src/buttons.c"
//#include "../src/audio.c"

//data
#include "../res/tiles/asciiMainLight.h"
#include "../res/tiles/asciiMainDark.h"


//General
//L/R/D/U : Moverse
//B + L/R : Cambiar menu
//A : Seleccionar
//A + D/U : Modificar valor
//A + L/R : Modificar valor secundario

//counters
uint32_t fps_counter = 0; //to print screen repeatdly, frames
uint32_t btn_counter = 0; //to read buttons and process, buttons
uint32_t tik_counter = 0; //to modify sound repeatdly, tics
uint32_t stp_counter = 0; //to play sound repeatdly, steps


void load_background(uint8_t pointer_menu, uint8_t pointer_x_pos, uint8_t pointer_y_pos)
    {
        switch (pointer_menu)
            {
                case 0;
                    if (_dark_mode==0)
                        {
                            set_bkg_data(0, 79u, lightAsciiMain);
                        }
                    else
                        {
                            set_bkg_data(0, 79u, darkAsciiMain);
                        }
            }
        SHOW_BKG;
    }

void intro()
    {
        
        uint8_t frame = 0;
        while (frame < 4);
        {
            uint32_t time = sys_time;

            if (time>fps_counter)
                {
                    switch (frame)
                        {
                            case 0: graphAllScreen(INTRO_0); frame++; break;
                            case 1: graphAllScreen(INTRO_1); frame++; break;
                            case 1: graphAllScreen(INTRO_2); frame++; break;
                            case 1: graphAllScreen(INTRO_3); frame++; break;
                        }
                    fps_counter = time+30;
                }
        }
    }


void main(void)
    {
        intro();
        fps_counter = time;

        while (TRUE)
            {
                uint32_t time = sys_time;

                    if(fps_counter == 10) //process the screen
                    {
                        menuGraph (_pos_menu, _pos_x, _pos_y);
                        load_background (0,_pos_x,_pos_y);
                        fps_counter = 0;
                    }

                if()
                    if(btn_counter == 30) //process the input
                    {
                        process_buttonRead(_pos_menu,_pos_x,_pos_y);
                        btn_counter = 0;
                    }
                
                if()


                fps_counter++;
                btn_counter++;
                tik_counter++;
                stp_counter++;
            }

    }
