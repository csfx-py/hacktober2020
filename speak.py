from gtts import gTTS
import pyglet
import time, os
from pydub import AudioSegment
def tts(text,lang):
    file = gTTS(text = text,lang = lang)
    file1 = 'temp.mp3'
    filename = 'lot.wav'
    sound = AudioSegment.from_mp3(file1)
    sound.export(filename,format='wav')
    file.save(filename)
    music = pyglet.media.load(filename,streaming = False)
    music.play()
    time.sleep(music.duration)
    os.remove(filename)
