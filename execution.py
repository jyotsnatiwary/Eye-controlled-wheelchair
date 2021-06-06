"""
Implementation of the GazeTracking library.
"""

import cv2
import pyrebase
from gaze_tracking import GazeTracking

gaze = GazeTracking()
webcam = cv2.VideoCapture(0)

# Pyrebase
config = {
	"apiKey": "AIzaSyBuJAiqLUOyBcEZFX9-GbFpYpO2CSyTsL8",
	"authDomain": "nodemcu-6a1b8.firebaseapp.com",
	"databaseURL": "https://nodemcu-6a1b8-default-rtdb.firebaseio.com",
	"projectId": "nodemcu-6a1b8",
	"storageBucket": "nodemcu-6a1b8.appspot.com",
	"messagingSenderId": "578188294320",
	"appId": "1:578188294320:web:8028e229c90a3dfc7b2375",
	"measurementId": "G-WPSY8SRPDW"
	}
firebase=pyrebase.initialize_app(config)
db=firebase.database()
db.child("Position").set("Null")

while True:
    # We get a new frame from the webcam
    _, frame = webcam.read()

    # We send this frame to GazeTracking to analyze it
    gaze.refresh(frame)

    frame = gaze.annotated_frame()
    text = ""

    if gaze.is_blinking():
        text = "Stop the wheelchair!"
        db.update({"Position":"Stop"})
    elif gaze.is_right():
        text = "Turn Right!"
        db.update({"Position":"Right"})
    elif gaze.is_left():
        text = "Turn Left!"
        db.update({"Position":"Left"})
    elif gaze.is_center():
        text = "Go Straight!"
        db.update({"Position":"Center"})

    cv2.putText(frame, text, (90, 60), cv2.FONT_HERSHEY_DUPLEX, 1.6, (147, 58, 31), 2)

    left_pupil = gaze.pupil_left_coords()
    right_pupil = gaze.pupil_right_coords()
    cv2.putText(frame, "Left pupil:  " + str(left_pupil), (90, 130), cv2.FONT_HERSHEY_DUPLEX, 0.9, (147, 58, 31), 1)
    cv2.putText(frame, "Right pupil: " + str(right_pupil), (90, 165), cv2.FONT_HERSHEY_DUPLEX, 0.9, (147, 58, 31), 1)

    cv2.imshow("Demo", frame)

    if cv2.waitKey(1) == 27:
        break
