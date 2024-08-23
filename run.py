import os
print("Opening /obj/GBDJ.gb:")
from pyboy import PyBoy

myPath = os.path.dirname(os.path.abspath(__file__))

gb = PyBoy(myPath+"/obj/GBDJ.gb", window="SDL2", scale=4, sound=True, sound_emulated=True)


i = 0
while gb.tick():
    if i < 1:
        print(" OK.\n")
        i = i + 1
    pass

gb.stop()