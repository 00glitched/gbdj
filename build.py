import os
from res.tileset.maketileset import IMAGE_TO_C
from res.sample.makesample import WAV_TO_C

myPath = os.path.dirname(os.path.abspath(__file__))

#for tileset
tileset_list = ["test","Ascii"]
#exec (open (myPath+"/res/tileset/maketileset.py").read())
IMAGE_TO_C(myPath+"/res/tileset",tileset_list)

#for tilemap

#for samples
sample_list = ["test"]
#exec (open (myPath+"/res/tileset/makesample.py").read())
WAV_TO_C(myPath+"/res/sample",sample_list)

#for presets