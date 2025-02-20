
dna1 = 'ACGATCAGCTACGATCGATCAGCTACGATCGCTCCGCTCG'
dna2 = 'TCGGTTTGTATCTCGAATACTTAGTC' 
dna3 = 'AAAAAAAAAAAAAA'

def transcribe(dna: str) -> str:
    rna = ''
    for i in dna:
        if(i == 'a' or i == 'A'):
            rna += 'U'
        elif (i == 't' or i == 'T'):
            rna += 'A'
        elif (i == 'g' or i == 'G'):
            rna += 'C'
        elif (i == 'c' or i == 'C'):
            rna += 'G'
        else:
            print("error unrecognised letter")
            return('')
    return rna

rna1 = transcribe(dna1)
rna2 = transcribe(dna2)
rna3 = transcribe(dna3)
print(f"rna1: {rna1}\nrna2: {rna2}\nrna3: {rna3}")