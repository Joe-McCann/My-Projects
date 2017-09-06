import os
import colorAmp
from tkinter import *

def getFiles():
    fil = os.listdir()
    fileExtensions = ['.mp3', '.wav']
    files = []
    for file in fil:
        for ext in fileExtensions:
            if ext in file:
                files.append(file)
                break
    return files

def getPath():
    eVal = elast.get()
    cVal = color.get()
    path = listbox.get(ACTIVE)
    root.destroy()
    ca = colorAmp.colorAmp(path, e = float(eVal), color = float(cVal))
    ca.inLine()

root = Tk()
root.configure(background="#161616")
var = StringVar(root)

files = getFiles()

scrollbar = Scrollbar(root)
scrollbar.grid(row=0, column=2, rowspan=3, sticky=N+S+W, pady=10)

listbox = Listbox(root)
listbox.grid(row=0, column=0, columnspan=2, rowspan=3, pady=10)

for i in files:
    listbox.insert(END, i)

listbox.config(yscrollcommand=scrollbar.set,fg="#e0dbdb", bg="#262525")
scrollbar.config(command=listbox.yview)

elast = Entry(root, fg="#e0dbdb", bg="#262525")
elast.insert(END, "1")
color = Entry(root, fg="#e0dbdb", bg="#262525")
color.insert(END, "1")

Label(root, text="Elasticity: ", fg="#e0dbdb", bg="#161616").grid(row=0, column=3,sticky=S)
elast.grid(row=0, column=4,sticky=S)
Label(root, text="Color: ", fg="#e0dbdb", bg="#161616").grid(row=1,column=3,sticky=N)
color.grid(row=1, column=4,sticky=N)

button = Button(root, text="   OK   ", command=getPath, fg="#1d3a1d", bg="#6f726f")
button.grid(row=2, column=3, columnspan=2)

mainloop()

