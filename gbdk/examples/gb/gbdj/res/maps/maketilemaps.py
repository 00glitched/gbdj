path = "/home/glitch00/Documentos/gbdk/examples/gb/gbdj/"
list = ["main"] #,"loop","track","inst","wave","samples","options"]
array=""
for i in list:
    #ui = "../src/ui/"
    uipos = path+"res/maps/txt/"+i+"_p.txt" # interactable positions
    uitxt = path+"res/maps/txt/"+i+"_t.txt" # screen graphics
    uic = path+"/res/maps/c/"+i+"_map.c"      # export as constants in .c file
    TXT = open (uitxt, mode='r')
    array="\n\nconst uint8_t uitxt_"+i+"[][] =\n{\n{"
    for j in range(18*21-1):
        char = TXT.read(1)
        if char != "\n":
            array+="'"+char+"'"
            if (j-20)%21!=20:
                array+=","
        else:
            array+="},\n{"
    TXT.close()
    array+="}\n};\n"
    array+="\n\nconst uint8_t uipos_"+i+"[][] =\n{\n{"
    UI = open (uipos, mode = 'r')
    for j in range(18*21-1):
        char = UI.read(1)
        if char != "\n":
            array+="'"
            if char>'0' and char<='9':
                array+=char
            else:
                array+=' '
            array+="'"
            if (j-20)%21!=20:
                array+=","
        else:
            array+="},\n{"
    UI.close()
    TXTtoC = open(uic, mode="w")
    TXTtoC.write(array)
    TXTtoC.close()