from vlc import VideoMarqueeOption, Position, EventType,Instance
import time

class VLC_Player():
    def __init__(self, url):
        self.url = url

    def start(self,timeout=60):

        instance = Instance()
        player = instance.media_player_new()
        Media = instance.media_new(self.url)
        Media.get_mrl()
        print(type(Media))
        player.set_media(Media)
        #player.play()
        time.sleep(timeout)
if __name__ == "__main__":
    url = "http://192.168.1.6:8080/?action=stream"
    p = VLC_Player(url)
    p.start(1000)