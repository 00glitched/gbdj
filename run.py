import os
from pyboy import PyBoy

myPath = os.path.dirname(os.path.abspath(__file__))

gb = PyBoy(myPath+"/obj/GBDJ.gb", window="SDL2", scale=4, sound=True, sound_emulated=True)

while gb.tick():
    pass

gb.stop()