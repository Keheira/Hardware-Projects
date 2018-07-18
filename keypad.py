# Using a 4x3 keypad with combonation verification

import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)

KEYPAD = [
          [1,2,3],
          [4,5,6],
          [7,8,9],
          ["*",0,"#"]
         ]
         
#BCM GPIO numbers
ROW = [17,4,3,2]
COLUMN = [18,15,14]

# pin of your choice
PIN = '1359'
# store user input
input = ''
loop = True

for i in range(3):
    GPIO.setup(COLUMN[i], GPIO.OUT)
    GPIO.output(COLUMN[i], 1)

for j in range(4):
    GPIO.setup(ROW[j], GPIO.IN, pull_up_down = GPIO.PUD_UP)

try:
    while(loop):
        #keyboard code
        for i in range(3):
            GPIO.output(COLUMN[i],0)
            for j in range(4):
                if GPIO.input(ROW[j]) == 0:
                    print (KEYPAD[j][i])
                    input+= str(KEYPAD[j][i])
                    while GPIO.input(ROW[j]) == 0:
                           pass
            GPIO.output(COLUMN[i],1)
            # check input length
            if(len(input) == 4):
                if(input == PIN):
                    print("Correct")
                    input = ''
                    loop = False
                else:
                    print("Wrong")
                    input = ''
except KeyboardInterrupt:
    GPIO.cleanup()
