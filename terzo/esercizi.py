# Scrivere in C un programma composto da due funzioni ed un programma principale. La prima funzione
# prende in ingresso un puntatore a file, legge il file come se contenesse dei numeri interi e restituisce la
# somma dei numeri letti. Anche la seconda funzione prende in ingresso un puntatore a un file, legge il
# file, interpreta i numeri letti come codifiche ASCII e restituisce la parola letta. Il programma principale
# deve chiedere all’utente di inserire il nome del file, controllare che venga aperto correttamente, invocare
# le funzioni definite in precedenza, se e come si ritiene opportuno, e stampare la valore intero restituito
# dalla prima funzione e la stringa restituita dalla seconda. Non e` possibile usare variabili condivise.

def primo(f):
    # contenga dei numeri
    # ? tutti sulla stessa riga e sono anche dei caratteri 
    a = f.read()
    a = a.strip().split()

    # mi creo la lista di interi con list-comprehension di python 
    # ritorno la somma della lista utilizzando la funziona built-in di python
    return sum([int(x) for x in a])

def primo_versione(f):
    # contenga dei numeri
    # ? tutti sulla stessa riga e sono anche dei caratteri 
    a = f.read()
    a = a.strip().split() # 1111 2222 -> ["1111", "2222"]

    accumulo = 0 
    for char in a:
        accumulo += int(char)

    return accumulo

def secondo(f):
    a = f.read()
    a = a.strip().split()

    # forse anche semplicmenete
    # se a è un array di stringhe
    # return "".join(a)
    return ''.join([str(x) for x in a])


def secondo_versione(f):
    a = f.read()
    a = a.strip().split()

    accumulo = '' 
    for char in a:
        accumulo += str(char)
    return accumulo

f = open("text1.txt", "rb") 

# s = open("text1.txt", "wb")
# s.write(b"\x04") 



primo(f) 
