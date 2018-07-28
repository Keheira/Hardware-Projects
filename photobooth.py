'''
Using the Pi Camera V2.1

Enter the number of pictures -> Enter the folder to save the photos under -> Enjoy your photos
'''
from picamera import PiCamera
from time import sleep
import os

num_input = input('How many pictures: ')
dirName = input('Name this directory: ')
count=0

if(not os.path.exists(dirName)):
    os.mkdir(dirName)

camera = PiCamera()
camera.resolution = (1024, 768)
while(count < int(num_input)):
    camera.start_preview()
    sleep(2)
    file = dirName+'/photo'+str(count)+'.jpg'
    camera.capture(file)
    camera.stop_preview()
    sleep(5)
    count+=1

print('All done! Enjoy')
