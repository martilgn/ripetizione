def main2():
    with open("text2.txt", 'r') as f:
        content = f.read()
        parole = content.strip().split()
        return sum([1 for x in parole if len(x) % 2 == 0])


def main():

    with open("text2.txt", 'r') as f:
        content = f.read()
        """
        aaaaaa
        aaaaaa
        aaaaaa
        """
        i = 0
        parole = content.strip().split()
        for parola in parole: 
            if len(parola) % 2 == 0:
                i += 1
        return i        


if __name__ == "__main__":
    print(main())
    print(main2())
