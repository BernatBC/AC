import os
import os.path
from tqdm import tqdm #pip3 install tqdm
import threading
import math
import time

times_to_process = input("Indicate many times do you want to repeat the computation (for each program&N): ")
times_to_process = int(times_to_process)

def compute(program, actual_n):

    compilation_fail = os.system("gcc " + program +".c tiempo.c -DN="+str(actual_n)+" -o" + program + ".x")
    if (compilation_fail):
        print("Error, while compiling " + program + ", aborting...")
        return
    #print("Compilation of " +str(program)+ " N="+str(actual_n)+" succesefully!")
    time = 0.0
    #print("Times: ", end='')

    for i in range(times_to_process):
        output = os.popen("./"+ program + ".x").read()
        #print((str(output).split())[5], end=' ')
        time = time + float(output.split()[5])
    average = time/times_to_process
    print("\nThe average of time for " +program+ " is " + str(average)+ "ms for N="+ str(actual_n) +"\n")
    print("MFLOPS = " + str(((actual_n**3)*2)/(average*(10**3))))

#---------------------------------------

def main():
    program_list = ["mm-ijk", "mm-jki", "mm-kij", "mm-ijk2", "mm-jki2", "mm-kij2"]
    N_list = [256, 512, 1024]

    for program in program_list:
        if (not os.path.exists(os.getcwd()+"/"+program+".c")):
            print("File " + program + " doesn't exists, aborting...")
            return

    threads = []

    for actual_n in N_list:
        for program in program_list:
            threads.append(threading.Thread(target=compute, args=(program, actual_n,)))

    it = int(len(threads)/3)
    for x in range(it):
        print(x)
        threads[(x*3)+0].start()
        threads[(x*3)+1].start()
        threads[(x*3)+2].start()

        threads[(x*3)+0].join()
        threads[(x*3)+1].join()
        threads[(x*3)+2].join()

    # # Wait for all of them to finish
    # for x in threads:


if __name__ == "__main__":
    main()
    os.system("rm *x")
