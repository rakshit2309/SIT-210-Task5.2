import tkinter as tk
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setup(14,GPIO.OUT)
GPIO.setup(15,GPIO.OUT)
GPIO.setup(16,GPIO.OUT)

GPIO.setup(14,GPIO.LOW)
GPIO.setup(15,GPIO.LOW)
GPIO.setup(16,GPIO.LOW)

win =tk.Tk()
win.title("Rakshit GUI ")
win.geometry('800x800')

def toggle_red():
    if GPIO.input(14):
        GPIO.output(14, GPIO.LOW)
        red_button.config(text="Red: OFF")
    else:
        GPIO.output(14, GPIO.HIGH)
        red_button.config(text="Red: ON")
        
def toggle_green():
    if GPIO.input(15):
        GPIO.output(15, GPIO.LOW)
        green_button.config(text="Green: OFF")
    else:
        GPIO.output(15, GPIO.HIGH)
        green_button.config(text="Green: ON")
        
def toggle_blue():
    if GPIO.input(16):
        GPIO.output(16, GPIO.LOW)
        blue_button.config(text="Blue: OFF")
    else:
        GPIO.output(18, GPIO.HIGH)
        blue_button.config(text="Blue: ON")
   
red_button = tk.Radiobutton(win, text="Red: OFF", command=toggle_red)
red_button.pack(pady=10)
green_button = tk.Radiobutton(win, text="Green: OFF", command=toggle_green)
green_button.pack(pady=10)
blue_button = tk.Radiobutton(win, text="Blue: OFF", command=toggle_blue)
blue_button.pack(pady=10)

def exit_program():
    GPIO.cleanup()
    win.quit()


exit_button = tk.Button(win, text="Exit", command=exit_program)
exit_button.pack(pady=10)


win.mainloop()
