import wave as wav
import numpy
import struct
import array

path = "/home/glitch00/Documentos/gbdk/examples/gb/gbdj/"
list = ["kick"]
for i in list:
    sound = wav.open(path+"res/samples/wav/"+i+".wav")
    #get data
    meta = sound.getparams()
    frames_rate = meta.framerate
    frames_num = meta.nframes
    frames_width = meta.sampwidth
    frames = sound.readframes(frames_rate)
    
    #converting
    pcm_format = "<"+"h"*(len(frames)//frames_width)
    pcm = struct.unpack(pcm_format,frames)
    pcm_len = len(pcm)
    
    #export
    framearr = [0]
    framestr = "\nuint8_t "+i+"_sample[] =\n{\n"
    if (pcm_len > 2**11):
        kmod = int(2+pcm_len/(2**12))
    else:
        kmod = 1
    t=0
    for k in range(pcm_len):
        if (k%kmod == 0):
            framestr += str(int(8+pcm[k]/4096))+","
            
            #byteA = int(pcm[k]+2**15)/(2**8)
            byteA = int(8+pcm[k]/4096)*16
            #print(byteB)
            #byteB = int((pcm[k]+2**15)%(2**8))
            #framearr.append(int(8+pcm[k]/4096)*2**10)
            framearr.append(byteA)
            #framearr.append(byteB)
            t=t+1
    framestr_Len = len(framestr)
    framestr = framestr[0:framestr_Len-1]
    framestr += "\n};"+"\nconst uint8_t "+i+"_sample_Len = "+str(framestr_Len-1)+";\n"
    
    sound.close()
    
    out = wav.open(path+"res/samples/c/"+i+"_out.wav", mode="wb")
    out.setnchannels(1)
    out.setsampwidth(1)
    out.setframerate(44100/kmod)
    out.writeframes(bytearray(framearr))

        
        
    out.close()
    #print(framearr)
    
    
    