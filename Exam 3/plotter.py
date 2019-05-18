import matplotlib.pyplot as plt


x_values = []
y_values = []

with open("output.csv") as file:
	for line in file:
		while not line[-1].isalnum():
			line = line[:-1]
		x, y = [float(elem) for elem in line.split(",")]

		x_values.append(x)
		y_values.append(y)

plt.axis("square")

plt.axis([-2.1, 1.1, -1.5, 1.5])

plt.scatter(x_values, y_values, s = .2, color = "black")
plt.xlabel("Real part")
plt.ylabel("Imaginary part")
plt.savefig("fractal_plot.png")
plt.show()
