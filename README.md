# Minitalk

<p align="center">
  <img src="https://https://github.com/AndersLazis/AndersLazis/blob/main/assets/covers/cover-minitalk-bonus.png" alt="Minitalk 42 project badge"/>
</p>

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
