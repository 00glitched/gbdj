import os
from pyboy import PyBoy

myPath = os.path.dirname(os.path.abspath(__file__))
gb = PyBoy(myPath+"/obj/GBDJ.gb")

while gb.tick():
    pass

gb.stop()