from Tkinter import *
import tkFont
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)

GPIO.setup(14,GPIO.OUT)
GPIO.setup(15,GPIO.OUT)
GPIO.setup(18,GPIO.OUT)

GPIO.setup(14,GPIO.LOW)
GPIO.setup(15,GPIO.LOW)
GPIO.setup(18,GPIO.LOW)

wink = Tk()

myFont =tkFont.Font(family = 'Helvetica', size = 36, weight = 'bold')

def red():
	print("RED IS TURNED ON")
	if GPIO.input(14) :
		GPIO.output(14,GPIO.LOW)
		ledButton["text"] = "RED ON"
	
	else :
		GPIO.output(14,GPIO.HIGH)
				ledButton["text"] = "RED OFF"
def green():
	print("RED IS TURNED ON")
	if GPIO.input(15) :
		GPIO.output(15,GPIO.LOW)
		ledButton["text"] = "GREEN ON"
	
	else :
		GPIO.output(14,GPIO.HIGH)
				ledButton["text"] = "GREEN OFF"
def blue():
	print("BLUE IS TURNED ON")
	if GPIO.input(14) :
		GPIO.output(14,GPIO.LOW)
		ledButton["text"] = "BLUE ON"
	
	else :
		GPIO.output(14,GPIO.HIGH)
				ledButton["text"] = "BLUE OFF"
				
				
def exitprogram():
	print("EXIT BUTTON PRESSED")
		GPIO.cleanup()
	win.quit()

win.title("GUI by Rahul")
win.geometry('800x480')

exitbutton = Button(win,text = "Exit", font =myFont, command = exitProgram, height = 2, width = 6)
exitbutton.pack(side = BOTTOM)

redledButton = Button (win,text = "RED ON", font = myFont, command = red,height =2,width =8)
redledButton.pack()
greenledButton = Button (win,text = "GREEN ON", font = myFont, command = green,height =2,width =8)
greenledButton.pack()
blueledButton = Button (win,text = "BLUE ON", font = myFont, command = blue,height =2,width =8)
blueledButton.pack()

mainloop()
