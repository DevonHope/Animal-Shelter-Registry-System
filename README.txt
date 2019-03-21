Our team, David Neale consists of members Devon (101038344), Hamza (101039500), Andrew (101038295) and Andy (101006098)


Project Description: 
  To build a GUI system for staff members to register clients and animals and then matchmake a client to an animal for optimal home situations for their pets. 

Installation/Building Instructions:
 Type in the the command in the terminal while in the current directory you untar'd the files: make (Creates and links all of the object files together to produce the executable 'cuACS')

Laucnhing Instructions:
	Type in the exact command after compiling the program: ./cuACS

If running from terminal after executing Makefile:
*  Once the program loads, it will execute code where it will create a folder (Animals) in the current directory
   It will then add the 25 animal files in the 'Animals' folder from the qrc resource file
* Same thing for clients, it will create a folder (Clients) in the current directory. Then it will add the 20 client files in the 'Clients' folder
* There will be a button called Staff and a drop down menu listing all the Client in Clients folder near the top of the main interface. Pressing either of those two enables you specific user privellages for those types of users, such as clients can only view all animal profiles and edit their own profile while staff can do just about anything except for editing the client profiles
* When you are adding an animal, a save dialog will show up and will bring you to the current directory. In there, it will show the 'Animals' folder where we store our animal files for the program to read from. If it does not bring you to the current directory, just simply navigate back to head back into that directory
* Same thing for adding a client, you will just need to add it in the 'Clients' folder
* Thus, you will need to save the animal or client to their respective folders everytime you want to add either of them
* Everytime you add, delete or edit an animal and client, hit their respective refresh buttons to reflect the changes

