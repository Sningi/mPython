# Programmed by RickyCga, 09/09/2016
# This program is for getting mjpg_streamer video, and analysis it.
import re
import base64
import cv2
import imutils
from urllib.request import urlopen, Request
import numpy as np

# mjpg-streamer URL information
piip = '192.168.1.6'  # input your pi's streamer ip
vPort0 = '8080'  # input port number you setup
# if you encrypted your streamer server, input your username and password here.
username = ''
password = ''
v0url = 'http://' + piip + ':' + vPort0 + '/?action=stream'
# Add user/pass to header
v0url = Request(v0url)
#base64string = base64.b64encode(bytes('%s:%s' % (username, password), 'ascii'))
#v0url.add_header("Authorization", "Basic %s" % base64string.decode('utf-8'))
v0stream = urlopen(v0url)  # open url
test = 1

# Read the boundary message and discard
v0stream.readline()
sz = 0
rdbuffer = None
clen_re = re.compile(b'Content-Length: (\d+)\\r\\n')

# Read each frame and Analysis
# TODO: This is hardcoded to mjpg-streamer's behavior
while True:
    v0stream.readline()  # content type

    try:  # content length
        clen = int(clen_re.match(v0stream.readline()).group(1))
        print('len is ',clen)
    except:
        continue

    v0stream.readline()  # timestamp
    v0stream.readline()  # empty line

    # Reallocate buffer if necessary
    if clen > sz:
        rdbuffer = bytearray(clen * 2)
        rdview = memoryview(rdbuffer)

    # Read frame into the preallocated buffer
    v0stream.readinto(rdview[:clen])
    v0stream.readline()  # endline
    v0stream.readline()  # boundary
    if test > 1:
        # Calculate Optical Flow
        nextFrame = cv2.imdecode(np.frombuffer(
            rdbuffer, count=clen, dtype=np.byte), flags=cv2.IMREAD_COLOR)  # decode jpeg, HSV
        next = nextFrame[:, :, 2]  # get HSV's 'V'
        next = cv2.GaussianBlur(next, (21, 21), 0)
        flow = cv2.calcOpticalFlowFarneback(
            prev, next, None, 0.5, 3, 10, 3, 7, 1.5, 0)  # calculate optical flow
        mag, ang = cv2.cartToPolar(flow[..., 0], flow[..., 1])
        hsv[..., 0] = ang * 180 / np.pi / 2  # convert angle to color
        hsv[..., 2] = cv2.normalize(mag, None, 0, 255, cv2.NORM_MINMAX)
        rgb = cv2.cvtColor(hsv, cv2.COLOR_HSV2BGR)
        cv2.imshow('opticalFlow', rgb)  # show optical flow

        # Motion Detect and Object Tracking
        frameDelta = cv2.absdiff(background, next)
        thresh = cv2.threshold(frameDelta, 25, 255, cv2.THRESH_BINARY)[1]
        thresh = cv2.dilate(thresh, None, iterations=4)
        _, cnts, _ = cv2.findContours(
            thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        for c in cnts:
            if cv2.contourArea(c) < 500:
                continue
            x, y, w, h = cv2.boundingRect(c)
            cv2.rectangle(prevFrame, (x, y), (x + w, y + h), (0, 255, 0), 2)
        cv2.imshow('Motion detect', prevFrame)

        # after diff two frame, update prev and prevFrame
        prev = next
        prevFrame = nextFrame
    else:
        # Read Optical prev frame, only exe at the first time
        imbuf=np.frombuffer(
            rdbuffer, count=clen, dtype=np.byte)
        print(imbuf)
        #test=2
        '''
        prevFrame = cv2.imdecode(np.frombuffer(
            rdbuffer, count=clen, dtype=np.byte), flags=cv2.IMREAD_COLOR)  # decode jpeg, HSV
        print(type(prevFrame))
        prev = prevFrame[:, :, 2]  # get HSV's  'V'
        prev = cv2.GaussianBlur(prev, (21, 21), 0)
        hsv = np.zeros_like(prevFrame)
        hsv[..., 1] = 255
        # Motion Detect and Object Tracking
        background = prev
        test = 2
        '''
    

    # show stream

    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()
