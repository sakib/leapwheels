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
    bounce = 0

    while True:

        frame = controller.frame()
        num_hands = len(frame.hands)

        #print bounce

        if (num_hands == 2):
            if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                if (prev_comm != "Backward" and bounce > 5):
                    print "Backward"
                    send_to_server("b")
                    bounce = 0
                    # Sub command: backward
                    prev_comm = "Backward"
                else:
                    bounce = bounce + 1
            else: # downward palm
                if (prev_comm != "Forward" and bounce > 5):
                    print "Forward"
                    send_to_server("f")
                    bounce = 0
                    # Sub command: forward
                    prev_comm = "Forward"
                else:
                    bounce = bounce + 1
        elif (num_hands == 1):
            if (frame.hands.rightmost.is_left):
                if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                    if (prev_comm != "Backward Left" and bounce > 5):
                        print "Backward Left"
                        send_to_server("x")
                        bounce = 0
                        # Sub command: Backward Left
                        prev_comm = "Backward Left"
                    else:
                        bounce = bounce + 1
                else: # downward palm
                    if (prev_comm != "Left" and bounce > 5):
                        print "Left"
                        send_to_server("l")
                        bounce = 0
                        # Sub command: Left
                        prev_comm = "Left"
                    else:
                        bounce = bounce + 1
            elif (frame.hands.rightmost.is_right):
                if (frame.hands.rightmost.palm_normal[1] > 0): # upward palm
                    if (prev_comm != "Backward Right" and bounce > 5):
                        print "Backward Right"
                        send_to_server("y")
                        bounce = 0
                        # Sub command: Backward Right
                        prev_comm = "Backward Right"
                    else:
                        bounce = bounce + 1
                else: # downward palm
                    if (prev_comm != "Right" and bounce > 5):
                        print "Right"
                        send_to_server("r")
                        bounce = 0
                        # Sub command: Right
                        prev_comm = "Right"
                    else:
                        bounce = bounce + 1
        elif (num_hands == 0):
            if (prev_comm != "Stop" and bounce > 5):
                print "Stop"
                send_to_server("s")
                bounce = 0
                # Sub command: Stop
                prev_comm = "Stop"
            else:
                bounce = bounce + 1

        time.sleep(0.1)

if __name__ == "__main__":
    main()
