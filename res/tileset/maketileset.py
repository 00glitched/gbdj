import sys
from PIL import Image

def IMAGE_TO_C(path,list):
    
    for i in list:
        print("Converting "+i+".png into "+i+".c")
        imagePath = path+"/img/"+i+".png"
        cfilePath = path+"/c/"+i+".c"
        img = Image.open(imagePath)
        pixel = img.load()
        tiles = img.size
        x_max = int(tiles[0]/8)
        y_max = int(tiles[1]/8)
        maketileset = 1
        tiles_Len = x_max*y_max
        if (tiles_Len > 256):
            print("Error: your tileset is too big")
            maketileset = 0
        elif (tiles_Len > 128):
            print("Warning: your tileset is big")
        if (maketileset == 1):
            tileset = "\nconst uint8_t "+i+"_tileset[] =\n{\n"
            for b in range(y_max):
                for a in range(x_max):
                    for m in range(8):
                        byteA = "0b"
                        byteB = "0b"
                        for n in range(8):
                            RGB = pixel[a*8+n+0,b*8+m]
                            R = RGB[0]
                            G = RGB[1]
                            B = RGB[2]
                            prom = (R+G+B)/3
                            if (prom > 3*255/4):
                                byteA += "0"
                                byteB += "0"
                            elif (prom > 255/2):
                                byteA += "0"
                                byteB += "0"
                            elif (prom > 255/4):
                                byteA += "0"
                                byteB += "1"
                            else:
                                byteA += "1"
                                byteB += "1"
                        tileset += byteA+","+byteB+","
                        if (m == 3):
                            tileset += "\n"
                    tileset += "\n"
            tileset_Len = len(tileset)
            tileset = tileset[0:tileset_Len-2]
            tileset += "\n};"#+"\nconst uint16_t "+i+"_tileset_Len = "+str(16*tiles_Len)+";\n"
            IMGtoC = open (cfilePath, mode = "w")
            IMGtoC.write(tileset)
            IMGtoC.close()
            print(" OK.\n")