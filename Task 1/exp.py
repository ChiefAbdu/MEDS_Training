def exp(x, terms=200):
    result = 1.0  
    term = 1.0  

    for n in range(1, terms):
        term = term * (x / n)
        result = result + term

    return result