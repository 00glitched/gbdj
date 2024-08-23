import os
import shutil

myPath = os.path.dirname(os.path.abspath(__file__))


folder_cont = os.listdir(myPath+"/res/include")

for i in folder_cont:
    try:
        print("Cleaning "+i+" from /src:")
        os.remove(myPath+"/src/"+i)
        print(" OK.\n")
    except:
        pass

folder_cont = os.listdir(myPath+"/obj")
folder_expt = ["GBDJ.gb","gbFileWillGenerateHere.md"]

for i in folder_cont:
    count = 0
    for j in folder_expt:
        if i == j:
            count = count + 1
    if count == 0:
        try:
            print("Cleaning "+i+" from /src:")
            os.remove(myPath+"/obj/"+i)
            print(" OK.\n")
        except:
            pass