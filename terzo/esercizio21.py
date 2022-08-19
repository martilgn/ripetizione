# prende in input una stringa, e un carattere
# e ritorna il numero di volte che il carattere è nella stringa
def conta_caratteri(string_to_check: str, c: str):
    i = 0

    for char in string_to_check:
        if char == c:
            i+=1
 
    return i        

def veloce(s: str, n: int) -> bool:
    dizionario = dict()

    for char in s:
        if char in dizionario:
            dizionario[char] += 1
        else:
            dizionario[char] = 1

    print(dizionario)

    for key in dizionario:
        if dizionario[key] >= n:
            return True 
    return False
    # 1 O(n)
    # "casa"
    # "c" -> 1
    # "a" -> 2
    # "s" -> 1

    # "casa"
    # 1, 1, 1, 1, 1 -> 5 O(n2)


def main(s: str, n: int) -> bool:
    for char in s:
        if conta_caratteri(s,char) >= n:
            return True
    return False    



if __name__ == "__main__":
    s = input("input la stringa: ")
    n = int(input("numero di volte: "))
    print(veloce(s, n))
