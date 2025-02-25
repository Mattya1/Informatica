# int funct(int n,int m)
# {
#     if(m>0){
#         return 1+f(n,m-1);
#     }
#     else
#         return n;
# }
# int main()
# {
#    int n,m;
#    cout << "Inserisci un numero ";
#    cin >> n;
#    cout << "Inserisci un altro numero ";
#    cin >> m;
#    cout << f(n,m);
#    return 0;
# }

.text
.globl main

funct:  addi $sp, $sp, -8   # Alloco lo stack
        sw   $a1, 4($sp)    # Salvo m
        sw   $ra, 0($sp)    # Salvo indirizzo di ritorno
if:     blez $a1, else      # Se m <= 0 go to else
        addi $a1, $a1, -1   # Calcolo m - 1
        jal  funct          # chiamo f(n,m-1)
        add  $v0, $v0, 1    # return 1 + f(n,m-1)
        j    end

else:   addi $v0, $a0, 0    # Return n

end:    lw   $a1, 4($sp)    # Ripristino m
        lw   $ra, 0($sp)    # Ripristino l'indirizzo
        addi $sp, $sp, 8    # Dealloco lo stack 
        jr   $ra  

main:   li   $v0, 5         # Read int
        syscall             # Chiamata a sistema
        move $a0, $v0       # Salvo n in a0
        li   $v0, 5         # read int
        syscall             # Chiamata a sistema
        move $a1, $v0       # Salvo m in a1
        addi $sp, $sp, -4   # Alloco lo stack
        sw   $ra, 0($sp)    # Salvo indirizzo di ritorno
        jal  funct          # Chiamo la funzione
        lw   $ra, 0($sp)    # Ripristino indirizzo di ritorno
        addi $sp, $sp, 4    # Dealloco lo stack
        move $s0, $a0       # Salvo n in s0
        move $a0, $v0       # Salvo il risultato della funzione in a0
        li   $v0, 1         # Read int
        syscall             # Chiamata a sistema
        jr   $ra            # End