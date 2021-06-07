# Eye-tracking
EPICS project- Eyeball controlled wheelchair

## 1. INTRODUCTION
Paralysis is a loss of strength in and control over a muscle or group of muscles in a part of the
body. Most of the time, this is not due to a problem with the muscles themselves. It is more
likely due to a problem somewhere along the chain of nerve cells that runs from the body part
to your brain and back again. These nerve cells deliver the signals for your muscles to move.
When any part of the relay system — such as the brain, spinal cord, nerves, or junction
between the nerve and the muscle — is damaged, the signals to move do not make it through
to the muscles and paralysis results. There are many ways the relay system can be damaged
and could take a heavy toll on person’s life. However, as the science progresses new
technologies have emerged to our aid against this disease 

## 1.1 Objectives
1. To build a hardware system that would track the eye movement to send messages to the
software.
2. Tracking of eye movement to help patients to interact and type on the screen without
physically touching anything.
3. To enable patients to move their car through the movement of their eye.
4. Muscle Stimulation: To build a hardware system to detect muscle movement to send
response to the software counterpart.

## 1.2 Working Principle:
Eye Tracking: Almost all of the technologies use a basic framework that operates through
rapid periodic sampling of the position of the participant’s eyes. Samples are taken at rapid
intervals (for instance, every 16 milliseconds). The position of the eyes at each sampling
point is determined on the basis of light reflected from the curvature of the corneas and the
position of the pupils. To determine this, a low level of infrared light is projected from the
eye tracking device. The infrared light, which is invisible to humans, is reflected off the eyes
and the angle of reflection is captured by a camera. A calibration procedure conducted at the
outset of the session (described below) allows the technology to match the physical
orientation of the eyes to specific coordinates on the monitor, providing the data input stream.
The data stream is recorded as a set of x-y coordinates of the point of gaze for each sample
obtained. Most programs also offer a variety of visualization options for displaying either
individual data patterns from a single participant or aggregated patterns across groups of
participants.

# 2. major steps that provide the basic framework for eye tracking are:

## 2.1 Process of Data Collection via Eye tracking:
Data collection for eye tracking research consists of two phases. The first phase is the
calibration phase, in which the technology obtains information about the size, curvature, and
position of the eye. The research phase then presents the task of interest for data acquisition.
Calibration Phase: Iinitial calibration must occur before data collection in order for the eye
tracker to match the angle of reflected light from the eyes to the specific x-y coordinates on
the stimulus presentation screen. During the initial calibration period, the participant is
presented with a series of targets that appear at specified pre-set x-y coordinates.
Calibration requires the participant to fixate on the targets (called calibration points) as they
are presented sequentially on the screen. Although instructions can be given (“look at each
dot when it appears on the screen”) the task can also be presented fully without spoken
instructions, through use of motion and sound cues that naturally attract fixation.
Common Research Tasks: The types of tasks most commonly used in eye tracking research
fall into one of two broad categories: free viewing and task-based. In free-viewing paradigms,
the participant is simply asked to look at one or more images while the pattern of eye gaze is
recorded. Free viewing is typically used to study what preferentially attracts and maintains
attention naturally, and has been used in studies of infants through adults and with individuals
with and without disabilities.
In task-based paradigms, the participant searches the image(s) on the basis of some
instruction. Often, the participant may be instructed to make a judgment about the image, for
instance, to determine the emotion on a face or find a target on the screen.

## 2.2 Quantifying the Data Recorded in Eye Tracking: Dependent Measures:
To quantify the stream of data recording the x-y coordinates of the participants’ gaze, each
stimulus image is divided into “regions” or “areas of interest” using a drawing program in the
eye tracking software. Each area of interest is enclosed within a border, and what constitutes
an area of interest is determined by the experimental question.
The software will determine when the point-of-gaze being recorded falls within or outside
any given area, by matching the calculated eye position from the incoming data stream to the
x-y coordinates of each area of interest on the stimulus monitor. Several dependent measures
can be obtained from this input stream, including patterns of fixation, saccades (that is, the
rapid eye movements between fixations), and pupil dilation.

* Eye movement can be regarded as a pivotal real-time input medium for humancomputer communication, which is especially important for people with physical
disability. The proposed system focuses on providing a simple and convenient
interactive mode by only using user's eye.
* We shall be using eye tracking primarily for mouse controlling. Our goal is to achieve
basic mouse activity and traversal just by using eye movements. It includes, Scrolling,
Cursor Traversal and Clicking (Left and right).
* Project Components:
1. Python
2. OpenCV
3. NumPy
4. Webcam
* In recent years, with the development of better and cheaper components for eye gaze
interaction, low-cost eye trackers have been produced by several high-profile
companies, such as Tobii's EyeX tracker, Gaze Point’s GP3 tracker, and the Eye Tribe
Tracker. As eye tracking gear gets cheaper, new applications with the concept of
using eye tracking in HCI are clearly beginning to blossom.

![1](https://user-images.githubusercontent.com/43038862/120959168-d21b3980-c776-11eb-8b8a-166ab58ac66a.JPG)

# 3 Result and Outcomes
* Initially, we had aimed at building a Wheel Chair similar to that of Stefan Hawking’s.
But later, we realised that a major drawback of Hawking’s chair is time delay. His
model first captured the image and then transferred it to detection module which
caused a major time lag and required a lot of database space.
* Hence, we decided to overcome this flaw and increase the accuracy of our model by
creating a real time low-cost Gaze detection with an accuracy rate of 98%.
* Our model performs real time detection of the pupil using the CV-2 tools and hence
results in 0-time lag.
* Our model is also equipped with eye-controlled keyboard typing with the help of gaze
ratio at an accuracy rate of 95%. The user of our model can type and express just by
looking at the letters.
* The eye directive wheelchair prototype requires no human contact and is a life saviour
for people suffering from Quadriplegia, disease that restricts all body movement
except eye and eyebrow muscle.
* The novelty of our system lies in the fact that no part of the system physically
interacts with the user, as a result making him feel comfortable. A mounted camera
tracks the eye movement and controls the wheelchair, thus enabling the patient to
move around with confidence. The patient’s family will also be able to track his
whereabouts by looking at database updates.
