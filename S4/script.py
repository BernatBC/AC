import os
import filecmp

os.system("make all")
os.system("./Sesion04-0 > test0.txt")
os.system("./Sesion04-1 > test1.txt")
os.system("./Sesion04-2 > test2.txt")
print("")
if(filecmp.cmp("test0.txt", "test1.txt")): print("Files are identical")
else:  print("Files are NOT identical")
print("")
if(filecmp.cmp("test0.txt", "test2.txt")): print("Files are identical")
else:  print("Files are NOT identical")
print("")
