# Base Conversion

This program takes a decimal number and a base as arguments and spits out that decimal number in the given base.
For example:
  $ ./conv 13 2
  1101
  $ ./conv 236709 8
  716245 
  $ ./conv 1352275 11
  843A91
  $ ./conv 38572856 64
  2J9Cu
  $ ./conv 3232236286 256
  192.168.2.254

  $ ./conv
  Usage: conv <decimal> <base>
  $ ./conv 11111 65
  INVALID BASE
 
To compile (linux/unix):
  make all

To run (linux/unix):
  ./conv [decimal number] [base]
