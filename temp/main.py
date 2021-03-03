import face_recognition
import numpy as np
import cv2
import init_people_info as konwn
import time


def main():
    knownpeopledict = konwn.get_known_people_info()
    print("load people info finish")
    video_capture = cv2.VideoCapture(2)
    face_locations = []
    face_encodings = []
    face_names = []
    process_this_frame = True
    while True:
        ret, frame = video_capture.read()
        small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
        if process_this_frame:
            face_locations = face_recognition.face_locations(small_frame)
            face_encodings = face_recognition.face_encodings(
                small_frame, face_locations)
            face_names = []
            for face_encoding in face_encodings:
                for val in knownpeopledict:
                    match = face_recognition.compare_faces(
                        [knownpeopledict[val]], face_encoding,0.5)
                    if match[0]:
                        name = val
                        break
                    else:
                        name = "unknown"
                face_names.append(name)
        process_this_frame = not process_this_frame
        for (top, right, bottom, left), name in zip(face_locations, face_names):
            top *= 4
            right *= 4
            bottom *= 4
            left *= 4
            cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255),  2)
            cv2.rectangle(frame, (left, bottom - 35),
                          (right, bottom), (0, 0, 255), 2)
            font = cv2.FONT_HERSHEY_DUPLEX
            cv2.putText(frame, name, (left+6, bottom-6),
                        font, 1.0, (0, 0, 0), 1)
        cv2.imshow('Video', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        #time.sleep(10)  
    video_capture.release()
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main()