import os, sys, inspect, thread, time
from subprocess import call
sys.path.insert(0, "../lib")
import Leap
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture
import socket

HOST = "192.168.29.206" # remote host
PORT = 50007 # remote port

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

def send_to_server(direction):
    s.send(direction)

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
                    send_to_server("backward")
                    # Sub command: backward
                    prev_comm = "Backward"
            else: # downward palm
                if (prev_comm != "Forward"):
                    print "Forward"
                    send_to_server("forward")
                    # Sub command: forward
                    prev_comm = "Forward"

        elif (num_hands == 1):
            if (frame.hands.rightmost.is_left):
                if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                    if (prev_comm != "Backward Left"):
                        print "Backward Left"
                        send_to_server("backward_left")
                        # Sub command: Backward Left
                        prev_comm = "Backward Left"
                else: # downward palm
                    if (prev_comm != "Left"):
                        print "Left"
                        send_to_server("left")
                        # Sub command: Left
                        prev_comm = "Left"
            elif (frame.hands.rightmost.is_right):
                if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                    if (prev_comm != "Backward Right"):
                        print "Backward Right"
                        send_to_server("backward_right")
                        # Sub command: Backward Right
                        prev_comm = "Backward Right"
                else: # downward palm
                    if (prev_comm != "Right"):
                        print "Right"
                        send_to_server("right")
                        # Sub command: Right
                        prev_comm = "Right"

        elif (num_hands == 0):
            if (prev_comm != "Stop"):
                print "Stop"
                send_to_server("stop")
                # Sub command: Stop
                prev_comm = "Stop"

        time.sleep(0.1)

if __name__ == "__main__":
    main()
