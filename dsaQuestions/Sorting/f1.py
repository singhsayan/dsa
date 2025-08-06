def compoundInterest(principal, rate, time):


    rate = rate / 100
    amount = principal * (1 + rate) ** time
    return amount - principal

principal = 1000
rate = 5
time = 2
interest = compoundInterest(principal, rate, time)
print(f"Compound Interest: {interest:}")