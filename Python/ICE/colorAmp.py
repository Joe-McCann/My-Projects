import turtle
import wave
import time
import math
from pydub import AudioSegment
from vlc import Instance
import numpy as np
from colorsys import hls_to_rgb

class colorAmp:
    
    def __init__(self, file, s = turtle.Screen(), e = 1, color = 1):
        self.screen = s
        self.elasticity = e
        self.avgLine = []
        self.color = color
        
        sound = AudioSegment.from_file(
            file, format=file[file.rfind(".")+1:])
        outPath = "read.wav"
        sound.export(outPath, format = "wav")

        instance = Instance()
        self.mediaPlayer = instance.media_player_new()
        self.mediaPlayer.set_media(instance.media_new(outPath))

        self.songFile = wave.open(outPath, 'r')

    def preReqs(self):
        self.frames = self.songFile.getnframes()
        self.frameRate = self.songFile.getframerate()
        self.length = self.frames/self.frameRate
        c = self.songFile.readframes(-1)
        c = abs(np.fromstring(c, 'Int16'))
        self.channels = [c[0::2], c[1::2]]
        self.spacing = 10**(math.floor(math.log(self.frames, 10))//2)
        self.points = self.spacing*10

    def generateSingleAverageWaveform(self):
        print("Waveform generation will take approximately"
              , self.length*.3638-.2558, "seconds")

        for i in range(self.points//2, len(self.channels[0])-self.points//2, self.spacing):
            self.avgLine.append((sum(self.channels[0][i-self.points//2:i+self.points//2]/(100*self.points))
                                +sum(self.channels[1][i-self.points//2:i+self.points//2]/(100*self.points))))

        print("Done with function generation")

    def preGen(self):
        self.preReqs()
        self.generateSingleAverageWaveform()
        mi = min(self.avgLine)
        ma = max(self.avgLine)
        t0 = time.time()

        self.mediaPlayer.play()
        while(time.time() - t0) < self.length:
            p = int(((time.time()-t0)/self.length*self.frames
                     -self.points)/self.spacing)
            self.screen.bgcolor(hls_to_rgb(self.color, float(((self.avgLine[p]-mi)/(ma-mi))**self.elasticity), 1))

    def inLineQuad(self, x):
        return 1-1/(1+x**2)

    def inLineQuad2(self, x):
        return 1-1/(.5*x+1)**2

    def inLine(self):
        self.preReqs()
        l = 0
        ddx = [0,0]
        t0 = time.time()
        self.mediaPlayer.play()
        while(time.time()-t0) < self.length:
            ddx[0] = ddx[1]
            ddx[1] = int(((time.time()-t0)/self.length)*self.frames)
            ddx[1] = (sum(self.channels[0][ddx[1] - self.points//2:ddx[1]+self.points//2]/(100*self.points))+
                          sum(self.channels[1][ddx[1] - self.points//2:ddx[1]+self.points//2]/(100*self.points)))/2
            hold = (ddx[1]-ddx[0])/50
            l += (hold)
            #print(hold)
            self.screen.bgcolor(map(lambda x: abs(x), hls_to_rgb(self.color, float(self.inLineQuad2(self.elasticity*l)), 1)))

    def inLineFFT(self):
        self.preReqs()
        l = 1
        ddx = [0,0,0,0]
        t0 = time.time()
        self.mediaPlayer.play()
        maxx = 0
        while(time.time()-t0) < self.length:
            ddx[2] = ddx[3]
            ddx[0] = ddx[1]
            ddx[1] = int(((time.time()-t0)/self.length)*self.frames)
            data = self.channels[0][ddx[1] - self.points//2:ddx[1]+self.points//2]
            fft = self.STFT(data)
            freqData = (sum(fft)/(len(fft)+1))
            ddx[3] = freqData.real**2+freqData.imag**2
            ddx[1] = (sum(abs(data)/(100*self.points))+
                          sum(abs(self.channels[1][ddx[1] - self.points//2:ddx[1]+self.points//2])/(100*self.points)))/2
            l *= math.exp((ddx[1]-ddx[0])/100*math.log(abs(ddx[3]-ddx[2])+10, 10))
            print(l)
            self.screen.bgcolor(hls_to_rgb(self.color, float(self.inLineQuad2(self.elasticity*l)), 1))

    def STFT(self, data):
        if(len(data))==0:
            return[0]
        window = np.hanning(len(data))
        t = np.multiply(data, window)
        return np.fft.rfft(t)
 
           


                           
    
        
