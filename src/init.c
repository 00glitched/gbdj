#include <stdint.h>
#include <stdio.h>

#include "../res/include/scren.h"
#include "../res/include/audio.h"
//

void initFunc(void)
    {
        setBkg();
        setBlank(0x2F);
        audioProcessGlobal(0x0,0x7,0x7);
    }