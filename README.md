# Minitalk

<p align="center">
  <img src="https://github.com/AndersLazis/AndersLazis/blob/main/assets/covers/cover-minitalk-bonus.png" alt="Minitalk 42 project badge"/>
</p>

The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

The server must be started first. After its launch, it has to print its PID.
The client takes two parameters:
The server PID.
The string to send.
The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long. 1 second for displaying 100 characters is way too much!
Your server should be able to receive strings from several clients in a row without needing to restart.
The communication between your client and your server has to be done only using UNIX signals.
You can only use these two signals: SIGUSR1 and SIGUSR2.


## Status

Validated 22 Apr 2023. Grade: 125%.

## Usage
1- Clone this repository
	
	git clone https://https://github.com/AndersLazis/Minitalk
2- Run `make`
   	make
3- `make clean` so that you don't keep those object files that you won't need anymore

	make clean
4- Run server and copy its PID to the client alongside the message you want to send.

	./server
	./client <server_PID> <message>

#### Makefile Available Targets:  
`make` or `make all` - Makes _client_ and _server_  
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes the executables and all the resulting object files  
`make re` - fclean + all  
`make bonus` - same as `all`, added for subject purposes  
