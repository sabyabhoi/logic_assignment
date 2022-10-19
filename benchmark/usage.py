from formula import Atom

a = Atom('a')
b = Atom('b')
c = Atom('c')

def dop(f, e):
	print("Formula: ", f)
	print("Valuation for", e, ": ", f.v(e))
	print("Counterexample: ", f.t())

dop(a | b, {a})
