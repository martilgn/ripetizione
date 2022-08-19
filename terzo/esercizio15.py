# funzione che faccia codifica

def codifica_classica(n: int):
    ris = 0
    posizione = 1 

    # 10
    # prima it
    # 3 * 1 -> ris = 3
    # n = 1
    # seconda iterazione
    # 1 * 10 -> ris = 13
    # n = 0
    # esce 

    # 
    # 143 in base 7
    # 20 3
    # 2 6
    # 0 2
    # 263

    # 143
    # 3 * 1 = ris = 3
    # 20
    # 6 * 10 -> ris = 63
    # 2 * 100 -> ris = 263

    while n > 0:
        ris += (n % 7) * posizione 
        posizione *= 10 
        n = n // 7 # in c basta / altrimenti ti ritorna divisione del float

    return ris 


def main():
    n = input("inserisci numero: ")
    n = int(n)

    if (n <= 0):
        return 
    # legge e chiama la funzione
    a = codifica_classica(n)
    print(a)
    return
    
if __name__ == "__main__":
    main()