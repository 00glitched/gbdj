from PIL import Image
path = input()
list = ["test"]
for i in list:
    imagePath = path+"gbdj/res/tileset/img/"+i+".png"
    cfilePath = path+"gbdj/res/tileset/c/"+i+".c"
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
                    tile = "0x"
                    for n in range(8):
                        RGB = pixel[a*8+n+0,b*8+m]
                        R = RGB[0]
                        G = RGB[1]
                        B = RGB[2]
                        prom = (R+G+B)/3
                        if (n == 4):
                            tile += ",0x"
                        if (prom > 3*255/4):
                            tile += "11"
                        elif (prom > 255/2):
                            tile += "10"
                        elif (prom > 255/4):
                            tile += "01"
                        else:
                            tile += "00"
                    tileset += tile+","
                    if (m == 3):
                        tileset += "\n"
                tileset += "\n"
        tileset_Len = len(tileset)
        tileset = tileset[0:tileset_Len-2]
        tileset += "\n};"+"\nconst uint8_t "+i+"_tileset_Len = "+str(tiles_Len-1)+";\n"
        #print(tileset)
        IMGtoC = open (cfilePath, mode = "w")
        IMGtoC.write(tileset)
        IMGtoC.close()