# Minitalk

The purpose of this project is to code a small data exchange program using `UNIX signals`.
It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

# Understand minitalk
You will have to realize a communication program in the form of a `client` and a `server`.

# Goal


The goal of the Minitalk project is to develop a simple program that allows processes (= programs running on a computer) to communicate with each other using a communication protocol called "minitalk". It corresponds to the protocol that you need to code.
The minitalk communication protocol involves sending messages between two processes using a series of signals over a single wire. 
One process, called the `"speaker/client"` sends the message by transmitting a series of signals over the wire. 
The other process, called the `"listener/server"` receives the message by interpreting the series of signals as a message.
