#include <gb/gb.h> //repair xd, listo xd
#include <stdint.h> //standard
#include <stdio.h>
#include <time.h>

void process_buttonRead(uint8_t pointer_menu, uint8_t pointer_x_pos, uint8_t pointer_y_pos)
    {
        switch (pointer_menu)
            {
                int8_t UPDOWN = J_UP-J_DOWN;
                int8_t RGTLFT = J_RIGHT-J_LEFT;
                int8_t AB     = J_A - J_B;
                case 0:
                    if (UPDOWN == 1)
                        {
                            uint8_t pivotX = pointer_x_pos;
                            uint8_t pivotY = pointer_y_pos;
                            uint8_t finish = 0;
                            while(pivotY>0)
                                {
                                    pivotY--;

                                    // if pos is in an option
                                    if (MENU_MAIN_OPT_POS[pivotY][pivotX] > 0)
                                        {
                                            _pos_x = pivotX;        //define new pos
                                            _pos_y = pivotY;
                                            finish++;
                                        }
                                }
                        }
                    else if ( UPDOWN == -1)
                        {
                            uint8_t pivotX = pointer_x_pos;
                            uint8_t pivotY = pointer_y_pos;
                            uint8_t finish = 0;
                            while(pivotY < SCREEN_LENY || finish > 0)
                                {
                                    pivotY++;
                                    if (MENU_MAIN_OPT_POS[pivotY][pivotX] > 0)
                                        {
                                            _pos_x = pivotX;
                                            _pos_y = pivotY;
                                            finish++;
                                        }
                                }
                        }
                    
                break;
                
                

                default:
                break;
            }
    }