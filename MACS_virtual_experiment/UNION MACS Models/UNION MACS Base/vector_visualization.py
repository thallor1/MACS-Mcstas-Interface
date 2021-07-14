import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

"""
soa = np.array([[0, 0, 1, 1, -2, 0], [0, 0, 2, 1, 1, 0],
                [0, 0, 3, 2, 1, 0], [0, 0, 4, 0.5, 0.7, 0]])
"""

a_real = np.array([0, 3.25276, 3.25276])
b_real = np.array([0, -3.25276, 3.25276])
c_real = np.array([2.9288, 0, 0])

a_recip = 2*np.pi*np.cross(b_real, c_real)/(a_real.dot(np.cross(b_real, c_real)))
b_recip = 2*np.pi*np.cross(c_real, a_real)/(a_real.dot(np.cross(b_real, c_real)))
c_recip = 2*np.pi*np.cross(a_real, b_real)/(a_real.dot(np.cross(b_real, c_real)))



fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

for vector, label in zip([a_real, b_real, c_real], ["a", "b", "c"]):
    ax.quiver(0, 0, 0, vector[0], vector[1], vector[2], color="red")
    ax.text(vector[0], vector[1], vector[2], label)

for vector, label in zip([a_recip, b_recip, c_recip], ["h", "k", "l"]):
    ax.quiver(0, 0, 0, vector[0], vector[1], vector[2], color="blue")
    ax.text(vector[0], vector[1], vector[2], label)


#ax.quiver(X, Yr, Zr, Ur, Vr, Wr, color="red")
ax.set_xlim([-5, 5])
ax.set_ylim([-5, 5])
ax.set_zlim([-5, 5])
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")
plt.show()
