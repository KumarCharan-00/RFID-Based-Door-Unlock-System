# RFID Based Door Unlock System
This is a software simulation of RFID based Door Unlock System written in C language on AT89C51ED2 MicroController Using Proteus Software.

## Installing Proteus
Licensed version of Proteus Software(paid version) can be installed [here](https://www.labcenter.com/schematic/).
You can also go with the unlicensed [version](https://getintopc.com/softwares/circuit-designing/proteus-professional-2019-free-download) (but this is not recommended). After installation, you might find out that components list is empty to solve this problem follow any of the following three youtube video links ([link-1](https://www.youtube.com/watch?v=l4770kWKwRs), [link-2](https://www.youtube.com/watch?v=FaIP0DXBqgE), [link-3](https://www.youtube.com/watch?v=jVHkMjw3wxo&t=324s)). 
If you are new to proteus then these youtube links might help you [link-1](https://www.youtube.com/watch?v=XtQEkWfPMQs), [link-2](https://www.youtube.com/watch?v=b02Xm9ZV1Xc)

## Installing and Working with Keil C51
If you are using source code and hex files from the repo then this step can be avioded. If not then check this [link](https://www.youtube.com/watch?v=MG595VN4r70) followed by this [link](https://www.youtube.com/watch?v=mhHJV21CDjs) or follow the below steps:
  1. Install keil from [here](https://www.keil.com/demo/eval/c51.htm). (Once you few fill the details and submit you will be directed to a download page).
  2. Now create new project with uvproj as extension eg: rfid.uvproj
  3. Inside the project you can find a folder named target there you can add the code file. If there is file named STARTUP.ASM remove it.
  4. Now, [create a hex file](https://www.youtube.com/watch?v=8TXInOl2aAw).
  5. Now, translate and build the file.

## Upload code and run Simulation in Proteus
If you did not make any changes to the files then you can directly run the simulation after [adding hex file](https://www.youtube.com/watch?v=1oogpvQ9D1I). If not then check this [video](https://youtu.be/CXNZkPboCoU) or foolw the below steps
  1. Right-click on the microcontroller and click the option `Edit Properties`.
  2. There in the `Program File`, add the correct hex file.
  3. After adding hex file Run the simulation (it the button that has play symbol on it located at the bottom right corner of the window).
  4. A virutal terminal will be popped in new window. Pass the right 12 digit rfid codes mentioned in the code.

## Basic problems
  1. Once you close the virtual terminal with close button(`X`). It might not open again to avoid this stop the exceution of simulation rather than closing virtual terminal, in any case if the terminal is not opening You can try to change the project name and re-open the project.
  2. When passing characters to the virtual terminal make sure that you are not pressing any other key because even shift, backspace, ctrl, cmd, option are considered as characters and passed to microcontroller.
  3. If you cannot see the characters typed in virtual terminal, then right-click on virtual terminal and check whether `echo typed characters` is enabled if not enable it.
  4. Make sure that Virtual terminal box connected to a power source, if the motor is not working.
  
.
 
      
