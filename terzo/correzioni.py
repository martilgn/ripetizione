# pagina 10
# primo(v):
# 1. inizializzazione non è richiesta, lo inizializza nel for. 
# 2. il return deve essere fuori dal for. 
# per il resto è ok

# quantiprimi(f):
# la funzione non ritorna niente, dovrebbe ritornare 4 valori. 

# main():
# non stampa niente perché non viene ritornato niente.
def primo(v):
    i=0
    # i = 2
    # return True
    for i in range(2,v,1):
        if (v%i==0): return False

    return True

# ritornare anche i primi 3 numeri primi
def quantiprimi(file):
    contprimi = 0
    valori = file.read().split()

    lista_di_primi = [] 
    # lista_di_primi = list() 

    # storare i primi 3 primi
    for val in valori:
        v = int(val)
        if (primo(v)):
            contprimi+=1

            if len(lista_di_primi) < 3:
                lista_di_primi.append(v) 

    # ritorno i valori richiesti 
    # massimo di 3 primi, e il conteggio alla fine. 
    lista_di_primi.append(contprimi)

    return lista_di_primi

def main():
    nf = input("Inserisci nome del file")
    f = open( nf , 'r' )
    soluzione = quantiprimi(f)
    print("I numeri primi sono: ", soluzione[:-1])
    print("format print di prova {}".format(3))
    print(f"numero di primi è {soluzione[len(soluzione) - 1]}")
    f.close(f)

# pagina 11
# nOccorrenze
# giusto, ma si potrebbe anche utilizzare len, per le stringhe per contare.
# main
# chiamato male il format print di python
# dire che esiste anche un altro modo per fare il format print

def nOccorrenze(f,c):
    contac=0
    for linea in f:
        parole = linea.split()
        for parola in parole:
            for car in parola:
                if car == c:
                    contac+=1

    return contac

def nCaratteri(f):
    contc=0
    for linea in f:
        parole = linea.split()
        for parola in parole:
            for car in parola:
                contc+=1

    return contc

def main():
    nf = input("Inserisci nome file: ")
    c1 = input("Inserisci il primo carattere: ")
    c2 = input("Inserisci il secondo carattere: ")
    c3 = input("Inserisci il terzo carattere: ")

    f = open(nf,'r')
    print(f"Il numero di caratteri contenuti nel file sono: {nCaratteri(f)} ")

    print("Il numero di caratteri contenuti nel file sono: %d " % nCaratteri(f))
    print("Il numero di occorrenze del carattere %c nel file è: %d " % (c1, nOccorrenze(f,c1)))
    print("Il numero di occorrenze del carattere %c nel file è: %d " % (c2, nOccorrenze(f,c2)))
    print("Il numero di occorrenze del carattere %c nel file è: %d " % (c3, nOccorrenze(f,c3)))
    f.close()