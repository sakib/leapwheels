import os, sys, inspect, thread, time
sys.path.insert(0, "../lib")
import Leap
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture

def main():
    controller = Leap.Controller()
    time.sleep(1)

    controller.enable_gesture(Leap.Gesture.TYPE_SWIPE);
    prev_comm = ""

    while(1):

        frame = controller.frame()
        num_hands = len(frame.hands)

        if (num_hands == 2):
            if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                if (prev_comm != "Backward"):
                    print "Backward"
                    # Sub command: backward
                    prev_comm = "Backward"
            else: # downward palm
                if (prev_comm != "Forward"):
                    print "Forward"
                    # Sub command: forward
                    prev_comm = "Forward"

        elif (num_hands == 1):
            if (frame.hands.rightmost.is_left):
                if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                    if (prev_comm != "Backward Left"):
                        print "Backward Left"
                        # Sub command: Backward Left
                        prev_comm = "Backward Left"
                else: # downward palm
                    if (prev_comm != "Left"):
                        print "Left"
                        # Sub command: Left
                        prev_comm = "Left"
            else:
                if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                    if (prev_comm != "Backward Right"):
                        print "Backward Right"
                        # Sub command: Backward Right
                        prev_comm = "Backward Right"
                else: # downward palm
                    if (prev_comm != "Right"):
                        print "Right"
                        # Sub command: Right
                        prev_comm = "Right"

        elif (num_hands == 0):
            if (prev_comm != "Stop"):
                print "Stop"
                # Sub command: Stop
                prev_comm = "Stop"

        time.sleep(0.1)

if __name__ == "__main__":
    main()
